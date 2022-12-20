// Copyright (c) 2018-2022 The Playchain developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ZMQ_ZMQGAMES_H
#define BITCOIN_ZMQ_ZMQGAMES_H

#include <sync.h>
#include <zmq/zmqpublishnotifier.h>

#include <set>
#include <string>
#include <vector>

class CBlock;
class CBlockIndex;
class CTransaction;
class UniValue;

namespace node {
class BlockManager;
} // namespace node

/**
 * Helper class to manage the list of tracked game IDs.
 */
class TrackedGames
{

private:

  /** The set of tracked game IDs.  */
  std::set<std::string> games GUARDED_BY (cs);

  /** Lock for this instance.  */
  mutable RecursiveMutex cs;

  friend class ZMQGameBlocksNotifier;
  friend class ZMQGamePendingNotifier;

public:

  TrackedGames () = delete;
  TrackedGames (const TrackedGames&) = delete;
  void operator= (const TrackedGames&) = delete;

  explicit TrackedGames (const std::vector<std::string>& g)
    : games(g.begin (), g.end ())
  {}

  UniValue Get () const;

  void Add (const std::string& game);
  void Remove (const std::string& game);

};

/**
 * Superclass for game ZMQ notifiers.  It references a list of tracked
 * games and provides general utility methods common for all game notifiers.
 */
class ZMQGameNotifier : public CZMQAbstractPublishNotifier
{

protected:

  /** Reference to the list of tracked games.  */
  const TrackedGames& trackedGames;

  /**
   * Sends a multipart message where the payload data is JSON.
   */
  bool SendZmqMessage (const std::string& command, const UniValue& data);

public:

  ZMQGameNotifier () = delete;
  ZMQGameNotifier (const ZMQGameNotifier&) = delete;
  void operator= (const ZMQGameNotifier&) = delete;

  explicit ZMQGameNotifier (const TrackedGames& tg)
    : trackedGames(tg)
  {}

};

/**
 * ZMQ publisher that handles the attach/detach messages for the Playchain game
 * interface (see doc/playchain/interface.md).
 */
class ZMQGameBlocksNotifier : public ZMQGameNotifier
{

private:

  /**
   * Block manager with the block map we use to get context information
   * like median time for blocks.
   */
  const node::BlockManager& blockman;

public:

  static const char* PREFIX_ATTACH;
  static const char* PREFIX_DETACH;

  explicit ZMQGameBlocksNotifier (const node::BlockManager& b,
                                  const TrackedGames& tg)
    : ZMQGameNotifier(tg), blockman(b)
  {}

  /**
   * Sends the block attach or detach notifications.  They are essentially the
   * same, except that they have a different command string.
   */
  bool SendBlockNotifications (const std::set<std::string>& games,
                               const std::string& commandPrefix,
                               const std::string& reqtoken,
                               const CBlock& block);

  bool NotifyBlockAttached (const CBlock& block) override;
  bool NotifyBlockDetached (const CBlock& block) override;

};

/**
 * ZMQ publisher that handles notifications for pending moves.
 */
class ZMQGamePendingNotifier : public ZMQGameNotifier
{

private:

  static const char* PREFIX_MOVE;

public:

  using ZMQGameNotifier::ZMQGameNotifier;

  bool NotifyTransactionAcceptance (const CTransaction& tx,
                                    uint64_t seq) override;

};

#endif // BITCOIN_ZMQ_ZMQGAMES_H
