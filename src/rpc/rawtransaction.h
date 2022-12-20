// Copyright (c) 2017-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_RPC_RAWTRANSACTION_H
#define BITCOIN_RPC_RAWTRANSACTION_H

class CTransaction;
class UniValue;
class uint256;

void TxToJSON(const CTransaction& tx, const uint256 hashBlock, UniValue& entry, Chainstate& active_chainstate);

#endif // BITCOIN_RPC_RAWTRANSACTION_H
