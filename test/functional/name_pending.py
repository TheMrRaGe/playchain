#!/usr/bin/env python3
# Copyright (c) 2015-2021 Daniel Kraft
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

# RPC test for name_pending call.

from test_framework.names import NameTestFramework, val
from test_framework.util import *

class NamePendingTest (NameTestFramework):

  def set_test_params (self):
    self.setup_name_test ([[]] * 2)

  def run_test (self):
    node = self.nodes[0]

    # Register a name that can then be update'd in the mempool.
    node.name_register ("x/a", val ("old-value-a"))
    self.generate (node, 1)

    # Start a new name registration as well.
    txb = node.name_register ("x/b", val ("value-b"))

    # Perform the unconfirmed updates.  Include a currency transaction
    # to check that it is not shown.
    txa = node.name_update ("x/a", val ("value-a"))
    addrOther = self.nodes[1].getnewaddress ()
    node.sendtoaddress (addrOther, 1)

    # Check that name_show still returns the old value.
    self.checkName (0, "x/a", val ("old-value-a"))

    # Check sizes of mempool against name_pending.
    mempool = node.getrawmempool ()
    assert_equal (len (mempool), 3)
    pending = node.name_pending ()
    assert_equal (len (pending), 2)

    # Check result of full name_pending (called above).
    for op in pending:
      assert op['txid'] in mempool
      if op['name'] == 'x/a':
        assert_equal (op['op'], 'name_update')
        assert_equal (op['value'], val ('value-a'))
        assert_equal (op['txid'], txa)
      elif op['name'] == 'x/b':
        assert_equal (op['op'], 'name_register')
        assert_equal (op['value'], val ('value-b'))
        assert_equal (op['txid'], txb)
      else:
        assert False

    # Check name_pending with name filter that does not match any name.
    pending = node.name_pending ('x/does not exist')
    assert_equal (pending, [])

    # Check name_pending with name filter.
    self.checkPendingName (0, 'x/a', 'name_update', val ('value-a'), txa)

    # We don't know the golden value for vout, as this is randomised.  But we
    # can store the output now and then verify it with name_show after the
    # update has been mined.
    pending = node.name_pending ('x/a')
    assert_equal (len (pending), 1)
    pending = pending[0]
    assert 'vout' in pending

    # Mine a block and check that all mempool is cleared.
    self.generate (node, 1)
    assert_equal (node.getrawmempool (), [])
    assert_equal (node.name_pending (), [])

    # Verify vout from before against name_show.
    confirmed = node.name_show ('x/a')
    assert_equal (pending['vout'], confirmed['vout'])

    # Send a name and check that ismine is handled correctly.
    tx = node.name_update ('x/a', val ('sent-a'), {"destAddress": addrOther})
    self.sync_mempools ()
    self.checkPendingName (0, 'x/a', 'name_update', val ('sent-a'), tx, False)
    self.checkPendingName (1, 'x/a', 'name_update', val ('sent-a'), tx, True)

  def checkPendingName (self, ind, name, op, value, txid, mine=None):
    """
    Call name_pending on a given name and check that the result
    matches the expected values.
    """

    res = self.nodes[ind].name_pending (name)
    assert_equal (len (res), 1)

    obj = res[0]
    assert_equal (obj['op'], op)
    assert_equal (obj['name'], name)
    assert_equal (obj['value'], value)
    assert_equal (obj['txid'], txid)
    assert isinstance (obj['ismine'], bool)
    if mine is not None:
      assert_equal (obj['ismine'], mine)

    # There is no golden value for vout, but we can decode the transaction
    # to make sure it is correct.
    rawtx = self.nodes[ind].getrawtransaction (txid, 1)
    assert 'nameOp' in rawtx['vout'][obj['vout']]['scriptPubKey']


if __name__ == '__main__':
  NamePendingTest ().main ()
