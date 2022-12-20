// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>

#include <chainparamsseeds.h>
#include <consensus/merkle.h>
#include <deploymentinfo.h>
#include <hash.h> // for signet block challenge hash
#include <powdata.h>
#include <script/interpreter.h>
#include <util/string.h>
#include <util/system.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>

namespace
{

constexpr const char pszTimestampTestnet[] = "Decentralised Autonomous Worlds";
constexpr const char pszTimestampMainnet[]
    = "HUC #2,351,800: "
      "8730ea650d24cd01692a5adb943e7b8720b0ba8a4c64ffcdf5a95d9b3fb57b7f";

/* Premined amount is 222,222,222 BITS.  This is the maximum possible number of
   coins needed in case everything is sold in the ICO.  If this is not the case
   and we need to reduce the coin supply, excessive coins will be burnt by
   sending to an unspendable OP_RETURN output.  */
constexpr CAmount premineAmount = 222222222 * COIN;

/*
The premine on regtest is sent to a 1-of-2 multisig address.

The two addresses and corresponding privkeys are:
  cRH94YMZVk4MnRwPqRVebkLWerCPJDrXGN:
    b69iyynFSWcU54LqXisbbqZ8uTJ7Dawk3V3yhht6ykxgttqMQFjb
  ceREF8QnXPsJ2iVQ1M4emggoXiXEynm59D:
    b3fgAKVQpMj24gbuh6DiXVwCCjCbo1cWiZC2fXgWEU9nXy6sdxD5

This results in the multisig address: dHNvNaqcD7XPDnoRjAoyfcMpHRi5upJD7p
Redeem script:
  512103c278d06b977e67b8ea45ef24e3c96a9258c47bc4cce3d0b497b690d672497b6e21
  0221ac9dc97fe12a98374344d08b458a9c2c1df9afb29dd6089b94a3b4dc9ad57052ae

The constant below is the HASH160 of the redeem script.  In other words, the
final premine script will be:
  OP_HASH160 hexPremineAddress OP_EQUAL
*/
constexpr const char hexPremineAddressRegtest[]
    = "2b6defe41aa3aa47795b702c893c73e716d485ab";

/*
The premine on testnet and mainnet is sent to a 2-of-4 multisig address.  The
keys are held by the founding members of the Playchain team.

The address is:
  DHy2615XKevE23LVRVZVxGeqxadRGyiFW4

The hash of the redeem script is the constant below.  With it, the final
premine script is:
  OP_HASH160 hexPremineAddress OP_EQUAL
*/
constexpr const char hexPremineAddressMainnet[]
    = "8cb1c236d34c74221fe4163bbba739b52e95f484";

CBlock CreateGenesisBlock(const CScript& genesisInputScript, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = genesisInputScript;
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = 0;
    genesis.nNonce   = 0;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);

    std::unique_ptr<CPureBlockHeader> fakeHeader(new CPureBlockHeader ());
    fakeHeader->nNonce = nNonce;
    fakeHeader->hashMerkleRoot = genesis.GetHash ();
    genesis.pow.setCoreAlgo (PowAlgo::NEOSCRYPT);
    genesis.pow.setBits (nBits);
    genesis.pow.setFakeHeader (std::move (fakeHeader));

    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 */
CBlock
CreateGenesisBlock (const uint32_t nTime, const uint32_t nNonce,
                    const uint32_t nBits,
                    const std::string& timestamp,
                    const uint160& premineP2sh)
{
  const std::vector<unsigned char> timestampData(timestamp.begin (),
                                                 timestamp.end ());
  const CScript genesisInput = CScript () << timestampData;

  std::vector<unsigned char>
    scriptHash (premineP2sh.begin (), premineP2sh.end ());
  std::reverse (scriptHash.begin (), scriptHash.end ());
  const CScript genesisOutput = CScript ()
    << OP_HASH160 << scriptHash << OP_EQUAL;

  const int32_t nVersion = 1;
  return CreateGenesisBlock (genesisInput, genesisOutput, nTime, nNonce, nBits,
                             nVersion, premineAmount);
}

/**
 * Mines the genesis block (by finding a suitable nonce only).  When done, it
 * prints the found nonce and block hash and exits.
 */
void MineGenesisBlock (CBlock& block, const Consensus::Params& consensus)
{
  std::cout << "Mining genesis block..." << std::endl;

  block.nTime = GetTime ();

  auto& fakeHeader = block.pow.initFakeHeader (block);
  while (!block.pow.checkProofOfWork (fakeHeader, consensus))
    {
      assert (fakeHeader.nNonce < std::numeric_limits<uint32_t>::max ());
      ++fakeHeader.nNonce;
      if (fakeHeader.nNonce % 1000 == 0)
        std::cout << "  nNonce = " << fakeHeader.nNonce << "..." << std::endl;
    }

  std::cout << "Found nonce: " << fakeHeader.nNonce << std::endl;
  std::cout << "nTime: " << block.nTime << std::endl;
  std::cout << "Block hash: " << block.GetHash ().GetHex () << std::endl;
  std::cout << "Merkle root: " << block.hashMerkleRoot.GetHex () << std::endl;
  exit (EXIT_SUCCESS);
}

} // anonymous namespace

/**
 * Main network on which people trade goods and services.
 */
class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = CBaseChainParams::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 4200000;
        /* The value of ~3.8 BITS is calculated to yield the desired total
           PoW coin supply.  For the calculation, see here:

           https://github.com/playchain/playchain/issues/70#issuecomment-441292533
        */
        consensus.initialSubsidy = 382934346;
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 1;
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 2016; // segwit activation height + miner confirmation window
        consensus.powLimitNeoscrypt = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1815; // 90% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        // The best chain should have at least this much work.
        // The value is the chain work of the Playchain mainnet chain at height
        // 4'150'000, with best block hash:
        // 430d6769cded8708cb075284ba0bbcc00682461404785eed5662e91789bccf08
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000034c25b9a2b105a34177ba88");
        consensus.defaultAssumeValid = uint256S("0x430d6769cded8708cb075284ba0bbcc00682461404785eed5662e91789bccf08"); // 4'150'000

        consensus.nAuxpowChainId = 1829;

        consensus.rules.reset(new Consensus::MainNetConsensus());

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xcc;
        pchMessageStart[1] = 0xbe;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0xfe;
        nDefaultPort = 8394;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 6;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock (1531470713, 482087, 0x1e0ffff0,
                                      pszTimestampMainnet,
                                      uint160S (hexPremineAddressMainnet));
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("e5062d76e5f50c42f493826ac9920b63a8def2626fd70a5cec707ec47a4c4651"));
        assert(genesis.hashMerkleRoot == uint256S("0827901b75ab43978c3cf20a78baf040faeb0e2eeff3a2c58ab6521a6d46f8fd"));

        vSeeds.emplace_back("seed.playchain.io.");
        vSeeds.emplace_back("seed.playchain.domob.eu.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,30);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,130);
        /* FIXME: Update these below.  */
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "bits";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_main), std::end(chainparams_seed_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = false;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {      0, uint256S("ce46f5f898b38e9c8c5e9ae4047ef5bccc42ec8eca0142202813a625e6dc2656")},
                { 340000, uint256S("e685ccaa62025c5c5075cfee80e498589bd4788614dcbe397e12bf2b8e887e47")},
                {1234000, uint256S("a853c0581c3637726a769b77cadf185e09666742757ef2df00058e876cf25897")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
         // TODO to be specified in a future patch.
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 4096 430d6769cded8708cb075284ba0bbcc00682461404785eed5662e91789bccf08
            .nTime    = 1662355660,
            .nTxCount = 5709786,
            .dTxRate  = 0.0319401364764268,
        };
    }

    int DefaultCheckNameDB () const override
    {
        return -1;
    }
};

/**
 * Testnet (v3): public test network which is reset from time to time.
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = CBaseChainParams::TESTNET;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 4200000;
        consensus.initialSubsidy = 10 * COIN;
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 1;
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 2016; // segwit activation height + miner confirmation window
        consensus.MinBIP9WarningHeight = consensus.SegwitHeight + consensus.nMinerConfirmationWindow;
        consensus.powLimitNeoscrypt = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
        consensus.nMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        // The value is the chain work of the Playchain testnet chain at height
        // 110'000 with best block hash:
        // 01547d538737e01d81d207e7d2f4c8f2510c6b82f0ee5dd8cd6c26bed5a03d0f
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000000e59eda1191b9");
        consensus.defaultAssumeValid = uint256S("0x01547d538737e01d81d207e7d2f4c8f2510c6b82f0ee5dd8cd6c26bed5a03d0f"); // 110'000

        consensus.nAuxpowChainId = 1829;

        consensus.rules.reset(new Consensus::TestNetConsensus());

        pchMessageStart[0] = 0xcc;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xfe;
        nDefaultPort = 18394;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 1;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock (1530623291, 343829, 0x1e0ffff0,
                                      pszTimestampTestnet,
                                      uint160S (hexPremineAddressMainnet));
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("5195fc01d0e23d70d1f929f21ec55f47e1c6ea1e66fae98ee44cbbc994509bba"));
        assert(genesis.hashMerkleRoot == uint256S("59d1a23342282179e810dff9238a97d07bd8602e3a1ba0efb5f519008541f257"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.emplace_back("seed.testnet.playchain.io.");
        vSeeds.emplace_back("seed.testnet.playchain.domob.eu.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,88);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,90);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,230);
        /* FIXME: Update these below.  */
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "chitn";

        // FIXME: Namecoin has no fixed seeds for testnet, so that the line
        // below errors out.  Use it once we have testnet seeds.
        //vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_test), std::end(chainparams_seed_test));
        vFixedSeeds.clear();

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        m_is_test_chain = true;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {     0, uint256S("3bcc29e821e7fbd374c7460306eb893725d69dbee87c4774cdcd618059b6a578")},
                { 11000, uint256S("57670b799b6645c7776e9fdbd6abff510aaed9790625dd28072d0e87a7fafcf4")},
                { 70000, uint256S("e2c154dc8e223cef271b54174c9d66eaf718378b30977c3df115ded629f3edb1")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
            // TODO to be specified in a future patch.
        };

        chainTxData = ChainTxData{
            // Data from rpc: getchaintxstats 4096 01547d538737e01d81d207e7d2f4c8f2510c6b82f0ee5dd8cd6c26bed5a03d0f
            .nTime    = 1586091497,
            .nTxCount = 113579,
            .dTxRate  = 0.002815363095612851,
        };
    }

    int DefaultCheckNameDB () const override
    {
        return -1;
    }
};

/**
 * Signet: test network with an additional consensus parameter (see BIP325).
 */
class SigNetParams : public CChainParams {
public:
    explicit SigNetParams(const ArgsManager& args) {
        std::vector<uint8_t> bin;
        vSeeds.clear();

        if (!args.IsArgSet("-signetchallenge")) {
            /* FIXME: Adjust the default signet challenge to something else if
               we want to use signet for Namecoin.  */
            bin = ParseHex("512103ad5e0edad18cb1f0fc0d28a3d4f1f3e445640337489abb10404f2d1e086be430210359ef5021964fe22d6f8e05b2463c9540ce96883fe3b278760f048f5189f2e6c452ae");
            //vSeeds.emplace_back("178.128.221.177");

            consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000000000001291fc22898");
            consensus.defaultAssumeValid = uint256S("0x000000d1a0e224fa4679d2fb2187ba55431c284fa1b74cbc8cfda866fd4d2c09"); // 105495
            m_assumed_blockchain_size = 1;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                // Data from RPC: getchaintxstats 4096 000000d1a0e224fa4679d2fb2187ba55431c284fa1b74cbc8cfda866fd4d2c09
                .nTime    = 1661702566,
                .nTxCount = 1903567,
                .dTxRate  = 0.02336701143027275,
            };
        } else {
            const auto signet_challenge = args.GetArgs("-signetchallenge");
            if (signet_challenge.size() != 1) {
                throw std::runtime_error(strprintf("%s: -signetchallenge cannot be multiple values.", __func__));
            }
            bin = ParseHex(signet_challenge[0]);

            consensus.nMinimumChainWork = uint256{};
            consensus.defaultAssumeValid = uint256{};
            m_assumed_blockchain_size = 0;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                0,
                0,
                0,
            };
            LogPrintf("Signet with challenge %s\n", signet_challenge[0]);
        }

        if (args.IsArgSet("-signetseednode")) {
            vSeeds = args.GetArgs("-signetseednode");
        }

        strNetworkID = CBaseChainParams::SIGNET;
        consensus.signet_blocks = true;
        consensus.signet_challenge.assign(bin.begin(), bin.end());
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.BIP16Height = 1;
        consensus.BIP34Height = 1;
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1815; // 90% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimitNeoscrypt = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Activation of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        consensus.nAuxpowChainId = 1829;

        consensus.rules.reset(new Consensus::TestNetConsensus());

        // message start is defined as the first 4 bytes of the sha256d of the block script
        HashWriter h{};
        h << consensus.signet_challenge;
        uint256 hash = h.GetHash();
        memcpy(pchMessageStart, hash.begin(), 4);

        nDefaultPort = 38394;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock (1601286749, 534547, 0x1e0ffff0,
                                      pszTimestampTestnet,
                                      uint160S (hexPremineAddressMainnet));
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x8d5223e215a03970bb3d3bc511a0d9a003e03cbc973289611ca6e0e617f57ccf"));
        assert(genesis.hashMerkleRoot == uint256S("0x59d1a23342282179e810dff9238a97d07bd8602e3a1ba0efb5f519008541f257"));

        vFixedSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,88);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,90);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,230);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = true;
        m_is_mockable_chain = false;
    }

    int DefaultCheckNameDB () const override
    {
        return -1;
    }
};

/**
 * Regression test: intended for private networks only. Has minimal difficulty to ensure that
 * blocks can be found instantly.
 */
class CRegTestParams : public CChainParams {
public:
    explicit CRegTestParams(const ArgsManager& args) {
        strNetworkID =  CBaseChainParams::REGTEST;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 150;
        // The subsidy for regtest net is kept same as upstream Bitcoin, so
        // that we don't have to update many of the tests unnecessarily.
        consensus.initialSubsidy = 50 * COIN;
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 1; // Always active unless overridden
        consensus.BIP65Height = 1;  // Always active unless overridden
        consensus.BIP66Height = 1;  // Always active unless overridden
        consensus.CSVHeight = 1;    // Always active unless overridden
        consensus.SegwitHeight = 0; // Always active unless overridden
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimitNeoscrypt = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)

        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        consensus.nAuxpowChainId = 1829;

        consensus.rules.reset(new Consensus::RegTestConsensus());

        pchMessageStart[0] = 0xcc;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 18495;
        nPruneAfterHeight = args.GetBoolArg("-fastprune", false) ? 100 : 1000;
        m_assumed_blockchain_size = 0;
        m_assumed_chain_state_size = 0;

        UpdateActivationParametersFromArgs(args);

        genesis = CreateGenesisBlock (1300000000, 0, 0x207fffff,
                                      pszTimestampTestnet,
                                      uint160S (hexPremineAddressRegtest));
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("6f750b36d22f1dc3d0a6e483af45301022646dfc3b3ba2187865f5a7d6d83ab1"));
        assert(genesis.hashMerkleRoot == uint256S("9f96a4c275320aaf6386652444be5baade11e2f9f40221a98b968ae5c32dd55a"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();
        vSeeds.emplace_back("dummySeed.invalid.");

        fDefaultConsistencyChecks = true;
        fRequireStandard = true;
        m_is_test_chain = true;
        m_is_mockable_chain = true;

        checkpointData = {
            {
                {0, uint256S("18042820e8a9f538e77e93c500768e5be76720383cd17e9b419916d8f356c619")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
            {
                110,
                {AssumeutxoHash{uint256S("0xdc81af66a58085fe977c6aab56b49630d87b84521fc5a8a5c53f2f4b23c8d6d5")}, 110},
            },
            {
                200,
                {AssumeutxoHash{uint256S("0x51c8d11d8b5c1de51543c579736e786aa2736206d1e11e627568029ce092cf62")}, 200},
            },
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,88);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,90);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,230);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "chirt";
    }

    int DefaultCheckNameDB () const override
    {
        return 0;
    }

    /**
     * Allows modifying the Version Bits regtest parameters.
     */
    void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout, int min_activation_height)
    {
        consensus.vDeployments[d].nStartTime = nStartTime;
        consensus.vDeployments[d].nTimeout = nTimeout;
        consensus.vDeployments[d].min_activation_height = min_activation_height;
    }
    void UpdateActivationParametersFromArgs(const ArgsManager& args);
};

static void MaybeUpdateHeights(const ArgsManager& args, Consensus::Params& consensus)
{
    for (const std::string& arg : args.GetArgs("-testactivationheight")) {
        const auto found{arg.find('@')};
        if (found == std::string::npos) {
            throw std::runtime_error(strprintf("Invalid format (%s) for -testactivationheight=name@height.", arg));
        }
        const auto name{arg.substr(0, found)};
        const auto value{arg.substr(found + 1)};
        int32_t height;
        if (!ParseInt32(value, &height) || height < 0 || height >= std::numeric_limits<int>::max()) {
            throw std::runtime_error(strprintf("Invalid height value (%s) for -testactivationheight=name@height.", arg));
        }
        if (name == "bip16") {
            consensus.BIP16Height = int{height};
        } else if (name == "segwit") {
            consensus.SegwitHeight = int{height};
        } else if (name == "bip34") {
            consensus.BIP34Height = int{height};
        } else if (name == "dersig") {
            consensus.BIP66Height = int{height};
        } else if (name == "cltv") {
            consensus.BIP65Height = int{height};
        } else if (name == "csv") {
            consensus.CSVHeight = int{height};
        } else {
            throw std::runtime_error(strprintf("Invalid name (%s) for -testactivationheight=name@height.", arg));
        }
    }
}

void CRegTestParams::UpdateActivationParametersFromArgs(const ArgsManager& args)
{
    MaybeUpdateHeights(args, consensus);

    if (!args.IsArgSet("-vbparams")) return;

    for (const std::string& strDeployment : args.GetArgs("-vbparams")) {
        std::vector<std::string> vDeploymentParams = SplitString(strDeployment, ':');
        if (vDeploymentParams.size() < 3 || 4 < vDeploymentParams.size()) {
            throw std::runtime_error("Version bits parameters malformed, expecting deployment:start:end[:min_activation_height]");
        }
        int64_t nStartTime, nTimeout;
        int min_activation_height = 0;
        if (!ParseInt64(vDeploymentParams[1], &nStartTime)) {
            throw std::runtime_error(strprintf("Invalid nStartTime (%s)", vDeploymentParams[1]));
        }
        if (!ParseInt64(vDeploymentParams[2], &nTimeout)) {
            throw std::runtime_error(strprintf("Invalid nTimeout (%s)", vDeploymentParams[2]));
        }
        if (vDeploymentParams.size() >= 4 && !ParseInt32(vDeploymentParams[3], &min_activation_height)) {
            throw std::runtime_error(strprintf("Invalid min_activation_height (%s)", vDeploymentParams[3]));
        }
        bool found = false;
        for (int j=0; j < (int)Consensus::MAX_VERSION_BITS_DEPLOYMENTS; ++j) {
            if (vDeploymentParams[0] == VersionBitsDeploymentInfo[j].name) {
                UpdateVersionBitsParameters(Consensus::DeploymentPos(j), nStartTime, nTimeout, min_activation_height);
                found = true;
                LogPrintf("Setting version bits activation parameters for %s to start=%ld, timeout=%ld, min_activation_height=%d\n", vDeploymentParams[0], nStartTime, nTimeout, min_activation_height);
                break;
            }
        }
        if (!found) {
            throw std::runtime_error(strprintf("Invalid deployment (%s)", vDeploymentParams[0]));
        }
    }
}

static std::unique_ptr<const CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<const CChainParams> CreateChainParams(const ArgsManager& args, const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN) {
        return std::unique_ptr<CChainParams>(new CMainParams());
    } else if (chain == CBaseChainParams::TESTNET) {
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    } else if (chain == CBaseChainParams::SIGNET) {
        return std::unique_ptr<CChainParams>(new SigNetParams(args));
    } else if (chain == CBaseChainParams::REGTEST) {
        return std::unique_ptr<CChainParams>(new CRegTestParams(args));
    }
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(gArgs, network);
}

std::chrono::seconds
AvgTargetSpacing (const Consensus::Params& params, const unsigned height)
{
  /* The average target spacing for any block (all algorithms combined) is
     computed by dividing some common multiple timespan of all spacings
     by the number of blocks expected (all algorithms together) in that
     time span.

     The numerator is simply the product of all block times, while the
     denominator is a sum of products that just excludes the current
     algorithm (i.e. of all (N-1) tuples selected from the N algorithm
     block times).  */
  int64_t numer = 1;
  int64_t denom = 0;
  for (const PowAlgo algo : {PowAlgo::SHA256D, PowAlgo::NEOSCRYPT})
    {
      const int64_t spacing = Ticks<std::chrono::seconds>(
          params.rules->GetTargetSpacing(algo, height));

      /* Multiply all previous added block counts by this target spacing.  */
      denom *= spacing;

      /* Add the number of blocks for the current algorithm to the denominator.
         This starts off with the product of all already-processed algorithms
         (excluding the current one), and will be multiplied later on by
         the still-to-be-processed ones (in the line above).  */
      denom += numer;

      /* The numerator is the product of all spacings.  */
      numer *= spacing;
    }

  assert (denom > 0);
  assert (numer % denom == 0);
  return std::chrono::seconds{numer / denom};
}
