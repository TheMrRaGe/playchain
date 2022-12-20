#!/usr/bin/env python3
# Copyright (c) 2018-2021 Daniel Kraft
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""RPC test for the "sendCoins" option with name operations."""

from test_framework.names import NameTestFramework, val
from test_framework.util import *


class NameSendCoinsTest (NameTestFramework):

  def set_test_params (self):
    self.setup_name_test ([[]] * 1)

  def verifyTx (self, txid, expected):
    """Verify that the given tx sends currency to the expected recipients."""

    txData = self.nodes[0].gettransaction (txid)
    assert_greater_than (txData["confirmations"], 0)

    tx = self.nodes[0].decoderawtransaction (txData["hex"])
    vout = tx['vout']

    # There should be two additional outputs: name and change
    assert_equal (len (vout), len (expected) + 2)

    actual = {}
    for out in vout:
      if 'nameOp' in out['scriptPubKey']:
        continue
      addr = out['scriptPubKey']['address']
      if not addr in expected:
        # This must be the change address.  Through the assertion above about
        # the expected sizes, we make sure that the test fails if there is
        # not exactly one key with this property.
        continue
      actual[addr] = out['value']

    assert_equal (actual, expected)

  def run_test (self):

    # Send name_register with sendCoins option and verify it worked as expected.
    addr1 = self.nodes[0].getnewaddress ()
    addr2 = self.nodes[0].getnewaddress ()
    sendCoins = {addr1: 1, addr2: 2}
    txid = self.nodes[0].name_register ("x/testname", val ("value"),
                                        {"sendCoins": sendCoins})
    self.generate (self.nodes[0], 1)
    self.verifyTx (txid, sendCoins)

    # Test different variations (numbers of target addresses) with name_update.
    for n in range (5):
      sendCoins = {self.nodes[0].getnewaddress (): 42 + i for i in range (n)}
      txid = self.nodes[0].name_update ("x/testname", val ("value"),
                                        {"sendCoins": sendCoins})
      self.generate (self.nodes[0], 1)
      self.verifyTx (txid, sendCoins)

    # Verify the range check for amount and the address validation.
    assert_raises_rpc_error (-3, 'Invalid amount for send',
                             self.nodes[0].name_update,
                             "x/testname", val ("value"),
                             {"sendCoins": {addr1: 0}})
    assert_raises_rpc_error (-5, 'Invalid address',
                             self.nodes[0].name_update,
                             "x/testname", val ("value"),
                             {"sendCoins": {"x": 1}})

    # Verify the insufficient funds check, both where it fails a priori
    # and where we just don't have enough for the fee.
    balance = self.nodes[0].getbalance ()
    assert_raises_rpc_error (-6, 'Insufficient funds',
                             self.nodes[0].name_update,
                             "x/testname", val ("value"),
                             {"sendCoins": {addr1: balance + 1}})
    assert_raises_rpc_error (-6, 'Insufficient funds',
                             self.nodes[0].name_update,
                             "x/testname", val ("value"),
                             {"sendCoins": {addr1: balance}})

    # Check that we can send a name_update that spends almost all funds in
    # the wallet.  We only need to keep a tiny amount to pay for the fee
    # (but less than the locked amount of 0.01).
    keep = Decimal ("0.009")
    sendCoins = {addr1: balance - keep}
    txid = self.nodes[0].name_update ("x/testname", val ("value"),
                                      {"sendCoins": sendCoins})
    self.generate (self.nodes[0], 1)
    self.verifyTx (txid, sendCoins)


if __name__ == '__main__':
  NameSendCoinsTest ().main ()
