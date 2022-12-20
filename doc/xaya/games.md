# Games on the Blockchain

This document describes how games in Playchain are structured and how they interact
with the core Playchain blockchain.  By following these rules, games ensure that
they fit well into the Playchain ecosystem and that the
[game-specific Playchain interface](interface.md) works well for them.

## Basic Model

Each game has a **game state**, which represents, for instance, the current
state and position of each avatar, in-game assets that each player owns, etc.
A particular state is associated
with each block in the Playchain blockchain, and all nodes running a particular game
have consensus about the current state.  This state is roughly speaking
what the UTXO set is in Bitcoin, except that it may be more complex as needed
for the particular game.

**NOTE:** Each *block hash* has a unique state associated with it; but if
a chain reorg occurs, then different blocks at the same *height* in the chain
will typically have *different* game states associated with them.  So when
storing or processing game states, the **block hash** and not the block height
should be used as the unique key!

The state is then **modified** from one block to the next by processing all
**moves** done by players in the new block; this is similar to how Bitcoin
transactions in each block update the UTXO set when attaching a new block to
the Bitcoin chain.  How exactly the game state is updated depends on the
game rules, and this is the core functionality that each game engine must
implement.  In other words, the game engine needs a **function that maps
an old state and a list of moves to a new state**:

> `f`: (old state, moves) -> new state

This function **processes the game state forward in time**.  In addition, to
properly handle chain reorgs, there must be a way to *restore old game states*.
This is discussed [below](#undoing).

In general, it is the responsibility of the **game engine** to keep track
of the current state and its updates.  The Playchain daemon, on the other hand,
provides the game engine with information about each attached or detached
block and the [moves](#moves) performed in them.

## Moves <a name="moves"></a>

Player accounts are represented in Playchain by [names](blockchain.md#names)
with the `p/` prefix.
For instance, `p/domob` is for the player account "domob".
Each player performs moves by **updating** this name to a value that encodes
the move(s) he wants to make.

The updated name value must be a [JSON object](https://json.org/).
If it contains moves associated with a particular game (which is identified
by a unique [game id](#games)), then the move data should be stored as
a JSON value in `.g[GAMEID]`.  The game decides on the type and format of the
move data, as well as how it processes the move when updating
the game state.

**As a fundamental rule, game engines should only ever depend on Playchain
transactions that are name updates (or registrations) referencing the
particular game ID!  This can be `p/` names that store a move in `g[GAMEID]`,
and it can be updates to the [`g/` name](#games) itself.
The game state must not depend on any other transactions,
neither pure currency transactions nor name updates not referencing the game.
Furthermore, the game engine must only take into account the actual move
value from the name update, not any other data.  It may, however, also depend
on [*currency outputs*](#currency) created in the same transaction
and the *spent inputs* (useful for [atomic trades](trading.md)).**

In particular, games must also not include any newly registered names into
the game state until those names have been referenced by a move associated
with the game's ID.
Typically, players should make an explicit move with a new name that indicates
they wish to join the game or create an avatar in the game.
(Of course, game UIs may show a list of all the names the player owns
so that the player can easily choose to join in this way through the UI.)

Here are some example values:

* `{}`:  This is the minimal valid JSON object, and can be used as a value
  when a name is registered or sent to a different address if no moves
  are intended to be made at the same time.  Name updates with this value are
  not sent to any game engine.

* `{"g":{"chess":"e8Q"}}`:  A move (encoded as string) for the game `chess`.

* More complicated examples may also contain moves encoded as JSON objects,
  other fields on the top level (they are not yet specified and will be
  ignored),
  and moves in two games at the same time:

        {
          "chat": "Playchain rocks!",
          "g":
            {
              "chess": "0-0-0",
              "huc":
                {
                  "wp": [0, 0, 42, 48, 0, 0]
                }
            }
        }

  If a name is updated to this value, then both the `chess` and `huc` game
  engines are notified (if installed).  The `chess` engine must only process
  the chess move `"0-0-0"`, though, and must ignore all other parts.
  Similarly, the `huc` engine must only process the JSON object for the
  `huc` move.

## Game IDs <a name="games"></a>

Since the [move format](#moves) references particular games, there must be
**unique IDs** for each game.  These game IDs are strings, and game creators
must reserve them by registering the name `g/GAMEID` on the Playchain blockchain.
This ensures uniqueness.

**NOTE:** This rule is not strictly enforceable by the blockchain, but it
is in the game creator's own interest to follow this guideline.

Ownership of the name corresponding to a game can be used to prove to every
node that someone is the "owner" of a game.  This can be used to send update
notifications or other trusted communication to all users of a particular game.
In particular, `g/` names of a game can send *admin commands* to all
instances of the game.  For that, the name should be updated to a value that
contains a custom JSON value (encoding the command in a game-specific form)
in the `cmd` field of the top-level JSON object.  For instance:

    {
      "cmd":
        {
          "type": "setparam",
          "name": "goldprice",
          "value": 100,
        },
      "other stuff": "ignored",
    }

## Duplicate JSON Keys

The JSON standard allows object values to contain duplicate keys.  Ideally,
this "feature" should not be used / relied upon at all, especially since
many JSON libraries cannot handle this very well.

### Moves

From the point of view of moves in a Playchain game, these situations with
duplicated JSON keys are interesting:

    {
      "g": {"first": "move 1"},
      "g": {"second": "move 2"},
    }

For a duplicated `g` field like this, Playchain will process all of them in order.
In the example above, the transaction specifies two valid moves,
one for `g/first` and the other for `g/second`.

    {
      "g":
        {
          "my game": "move a",
          "my game": "move b"
        }
    }

If the game ID itself is duplicated (either within one `g` field or
because the `g` field is also duplicated), then Playchain will ignore all
moves **except the last**.  In other words, in the example above,
**only `move b`** would be "the" move for `g/my game` in this transaction.

    {
      "g": {"my game": {"x": 1, "x": 2}}
    }

If keys are duplicated *within a move*, then the data will be passed on
like that (i.e. `{"x": 1, "x": 2}`) as move to the game.  **Games must
be prepared for this situation, and handle it gracefully in some
well-defined way.**

For instance, [`libplaychaingame`](https://github.com/playchain/libplaychaingame) will
de-dup keys (keeping only the last within each JSON object) before passing
data on to the individual game logic.

### Admin Commands

For an admin command, the `cmd` field can also be duplicated:

    {
      "cmd": "first",
      "cmd": "second"
    }

In this case, all associated values are considered valid admin commands
for the game in question.

## BITS Transactions in Games <a name="currency"></a>

Games may also need to process BITS transactions, at least in a limited fashion.
For instance, it may be possible to buy in-game items from the game developer
with BITS, or the game may implement a player-to-player market place where
transactions are settled in BITS.

To facilitate this, game engines can process all **currency outputs**
created by name transactions that reference their game ID.  In other words,
a player can issue a move and *in the same Playchain transaction* also send BITS to,
for instance, the Playchain address of the game developer or a trading partner.
The game engine will then (but only if done in the same transaction) know about
this, and can implement rules that update the game state accordingly.
For instance, a game rule could be like this:

> If the move data contains `{"buy": "diamond sword"}` **and** at least
  1,000 BITS are sent to the company address Cxyz, **then** the player gets
  a diamond sword for her avatar in the game state.

Note that there exists a second possibility for trading in games:
[Atomic name updates](trading.md) can be used to couple game moves
(e.g. an explicit command to transfer an item) with payments in BITS.
This is particularly useful for market places between players themselves,
rather than payments to a game developer.

An alternative to handling BITS payments is to require **burning of BITS**.
This can be used to create a cost for certain actions (e.g. to discourage
spamming them), while not creating a privileged instance (the receiver
of payments).  To burn BITS in relation to a given move in a game,
they should be sent to an `OP_RETURN` output with `g/GAMEID` as the data
part.  (The burn must be related uniquely to a specific game, since otherwise
a single burn of BITS could be used for multiple games at the same time.)

## Processing Backwards in Time <a name="undoing"></a>

While the typical behaviour of the Playchain blockchain is to attach blocks
on top of each other, it may happen that the blockchain is *reorganised*.
This means that one or multiple blocks that were previously part of the best
chain must be **detached**, and alternative blocks are attached to replace
them.  To handle these situations, game engines need a way to
**restore old game states** or, in other words, **process backwards in time**
when a block is detached.

There are two suggested strategies that may be employed for this, depending
on the particular properties of each game:

### Archiving Old States

The most straight-forward solution is to simply keep "archived copies" of old
game states, keyed by the block hashes they correspond to.  Then in case of
a reorg, the game engine can restore the archived copy of some game state
before the chain fork, and update it forward in time with all the blocks that
are then attached on top of it.

Note that it is not necessary to store *every* previous game state, as one can
simply process forward all following blocks.  This means that a good strategy
may be to store a game state for the last `n` blocks to cheaply handle
short reorgs, and then one game state every `k` blocks for cases where
very old game states may be needed (requiring to process, in the worst
case, `k - 1` forward steps).

This option is easy to implement because it reuses the forward-processing
function `f` that the game engine needs anyway.  On the other hand, it requires
storing at least a certain number of old game states, which may be costly (or
not).  Also, if not every game state is archived, this may require more
processing power to retrieve an old game state.

Depending on how the current game state is stored, it may be possible to take
advantage of existing **snapshotting** and/or **copy-on-write functionality**
of the underlying file system or database, which can make this particularly easy
and cheap to implement.

This model is used successfully in [Huntercoin](http://huntercoin.org/).

### Backwards Processing and Undo Data

An alternative is to implement separate logic that **reverts** the changes
made to the game state by a particular block.  This can then be used to
compute the old game state when detaching a block, before attaching a new one.

Since the moves made in a particular block are archived already by the Playchain
daemon as part of the block, they are readily available when detaching the
block.  However, it may very well be the case that the forward-processing
function `f` is not reversible, because it "destroys" or "overwrites" some
data in the old game state.  For instance, if a move simply says to
"make this boat in my fleet the flagship", then it may not be possible to
determine afterwards which boat was the flagship before.  To handle these
cases, all of the destroyed information must be stored in some extra
**undo data** associated with the block, such that the mapping
from the old state and moves to the new state *and the undo data* can be
reverted by the backwards-processing function

> `b`: (new state, moves, undo data) -> old state.

**It is the responsibility of the game engine and not the Playchain daemon to
keep all the undo data relevant for the particular game!**

This method is, in some sense, a custom implementation of incremental snapshots
for all old game states.  It requires more work to implement, but can be the
most efficient solution, as the exact nature of the undo data can be optimised
for the particular game.

This approach is employed by Bitcoin Core to handle changes
to the UTXO set during reorgs.
