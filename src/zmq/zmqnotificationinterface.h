// Copyright (c) 2015-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
#define BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H

#include <primitives/transaction.h>
#include <validationinterface.h>
#include <zmq/zmqgames.h>

#include <cstdint>
#include <list>
#include <memory>

class CBlock;
class CBlockIndex;
class CZMQAbstractNotifier;
class ZMQGameBlocksNotifier;

namespace node {
class BlockManager;
} // namespace node

class CZMQNotificationInterface final : public CValidationInterface
{
public:
    virtual ~CZMQNotificationInterface();

    std::list<const CZMQAbstractNotifier*> GetActiveNotifiers() const;

    static CZMQNotificationInterface* Create(const node::BlockManager& b);

    inline TrackedGames* GetTrackedGames() {
        return trackedGames.get();
    }

    inline ZMQGameBlocksNotifier* GetGameBlocksNotifier() {
        return gameBlocksNotifier;
    }

protected:
    bool Initialize();
    void Shutdown();

    // CValidationInterface
    void TransactionAddedToMempool(const CTransactionRef& tx, uint64_t mempool_sequence) override;
    void TransactionRemovedFromMempool(const CTransactionRef& tx, MemPoolRemovalReason reason, uint64_t mempool_sequence) override;
    void BlockConnected(const std::shared_ptr<const CBlock>& pblock, const CBlockIndex* pindexConnected) override;
    void BlockDisconnected(const std::shared_ptr<const CBlock>& pblock, const CBlockIndex* pindexDisconnected) override;
    void UpdatedBlockTip(const CBlockIndex *pindexNew, const CBlockIndex *pindexFork, bool fInitialDownload) override;

private:
    CZMQNotificationInterface();

    void *pcontext;
    std::list<std::unique_ptr<CZMQAbstractNotifier>> notifiers;

    /**
     * The game blocks notifier, if any.  This is used to send on-demand
     * notifications for game_sendupdates.
     */
    ZMQGameBlocksNotifier* gameBlocksNotifier;

    /** The tracked games for notifications.  */
    std::unique_ptr<TrackedGames> trackedGames;

};

extern CZMQNotificationInterface* g_zmq_notification_interface;

#endif // BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
