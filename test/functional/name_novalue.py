#!/usr/bin/env python3
# Licensed under CC0 (Public domain)

# Test that name_firstupdate and name_update handle missing
# name values gracefully. This test uses direct RPC calls.
# Testing the wrappers is out of scope.

from test_framework.names import NameTestFramework, val
from test_framework.util import *

class NameNovalueTest(NameTestFramework):

    def set_test_params(self):
        self.setup_clean_chain = True
        self.setup_name_test ([["-namehistory", "-limitnamechains=3"]])

    def run_test(self):
        node = self.nodes[0]
        self.generate (node, 200)

        node.name_register ("d/name")
        self.generate (node, 1)
        self.log.info("Name registered; no value provided.")

        self.checkName(0, "d/name", "{}")
        self.log.info("Value equals empty JSON.")

        node.name_update("d/name", val ("1"))
        self.generate (node, 1)
        self.log.info('Value changed to "1"; change is in chain.')

        self.checkName(0, "d/name", val ("1"))
        self.log.info('Value equals "1".')

        node.name_update("d/name")
        self.generate (node, 1)
        self.log.info("Updated; no value specified.")

        self.checkName(0, "d/name", val ("1"))
        self.log.info('Name was updated. Value still equals "1".')

        node.name_update("d/name", val ("2"))
        node.name_update("d/name")
        node.name_update("d/name", val ("3"))
        self.generate (node, 1)
        self.log.info('Stack of 3 registrations performed.')

        history = node.name_history("d/name")
        reference = ["{}"] + val (["1", "1", "2", "2", "3"])
        assert(list(map(lambda x: x['value'], history)) == reference)
        self.log.info('Updates correctly consider updates in the mempool.')


if __name__ == '__main__':
    NameNovalueTest ().main ()
