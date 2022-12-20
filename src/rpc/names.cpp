// Copyright (c) 2014-2021 Daniel Kraft
// Copyright (c) 2020 yanmaani
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <base58.h>
#include <chainparams.h>
#include <core_io.h>
#include <init.h>
#include <index/namehash.h>
#include <key_io.h>
#include <names/common.h>
#include <names/main.h>
#include <node/context.h>
#include <primitives/transaction.h>
#include <psbt.h>
#include <rpc/blockchain.h>
#include <rpc/names.h>
#include <rpc/server.h>
#include <rpc/server_util.h>
#include <script/names.h>
#include <txmempool.h>
#include <util/strencodings.h>
#include <validation.h>
#ifdef ENABLE_WALLET
# include <wallet/rpc/util.h>
# include <wallet/wallet.h>
#endif

#include <univalue.h>

#include <boost/xpressive/xpressive_dynamic.hpp>

#include <algorithm>
#include <cassert>
#include <memory>
#include <stdexcept>

namespace
{

NameEncoding
EncodingFromOptionsJson (const UniValue& options, const std::string& field,
                         const NameEncoding defaultValue)
{
  NameEncoding res = defaultValue;
  RPCTypeCheckObj (options,
    {
      {field, UniValueType (UniValue::VSTR)},
    },
    true, false);
  if (options.exists (field))
    try
      {
        res = EncodingFromString (options[field].get_str ());
      }
    catch (const std::invalid_argument& exc)
      {
        LogPrintf ("Invalid value for %s in options: %s\n  using default %s\n",
                   field, exc.what (), EncodingToString (defaultValue));
      }

  return res;
}

} // anonymous namespace

/**
 * Utility routine to construct a "name info" object to return.  This is used
 * for name_show and also name_list.
 */
UniValue
getNameInfo (const UniValue& options,
             const valtype& name, const valtype& value,
             const COutPoint& outp, const CScript& addr)
{
  UniValue obj(UniValue::VOBJ);
  AddEncodedNameToUniv (obj, "name", name,
                        EncodingFromOptionsJson (options, "nameEncoding",
                                                 ConfiguredNameEncoding ()));
  AddEncodedNameToUniv (obj, "value", value,
                        EncodingFromOptionsJson (options, "valueEncoding",
                                                 ConfiguredValueEncoding ()));
  obj.pushKV ("txid", outp.hash.GetHex ());
  obj.pushKV ("vout", static_cast<int> (outp.n));

  /* Try to extract the address.  May fail if we can't parse the script
     as a "standard" script.  */
  CTxDestination dest;
  std::string addrStr;
  if (ExtractDestination (addr, dest))
    addrStr = EncodeDestination (dest);
  else
    addrStr = "<nonstandard>";
  obj.pushKV ("address", addrStr);

  return obj;
}

/**
 * Return name info object for a CNameData object.
 */
UniValue
getNameInfo (const UniValue& options,
             const valtype& name, const CNameData& data)
{
  UniValue result = getNameInfo (options,
                                 name, data.getValue (),
                                 data.getUpdateOutpoint (),
                                 data.getAddress ());
  addHeightInfo (data.getHeight (), result);
  return result;
}

void
addHeightInfo (const int height, UniValue& data)
{
  data.pushKV ("height", height);
}

#ifdef ENABLE_WALLET
/**
 * Adds the "ismine" field giving ownership info to the JSON object.
 */
void
addOwnershipInfo (const CScript& addr, const wallet::CWallet* pwallet,
                  UniValue& data)
{
  if (pwallet == nullptr)
    return;

  AssertLockHeld (pwallet->cs_wallet);
  const wallet::isminetype mine = pwallet->IsMine (addr);
  const bool isMine = (mine & wallet::ISMINE_SPENDABLE);
  data.pushKV ("ismine", isMine);
}
#endif

namespace
{

valtype
DecodeNameValueFromRPCOrThrow (const UniValue& val, const UniValue& opt,
                               const std::string& optKey,
                               const NameEncoding defaultEnc)
{
  const NameEncoding enc = EncodingFromOptionsJson (opt, optKey, defaultEnc);
  try
    {
      return DecodeName (val.get_str (), enc);
    }
  catch (const InvalidNameString& exc)
    {
      std::ostringstream msg;
      msg << "Name/value is invalid for encoding " << EncodingToString (enc);
      throw JSONRPCError (RPC_NAME_INVALID_ENCODING, msg.str ());
    }
}

} // anonymous namespace

valtype
DecodeNameFromRPCOrThrow (const UniValue& val, const UniValue& opt)
{
  return DecodeNameValueFromRPCOrThrow (val, opt, "nameEncoding",
                                        ConfiguredNameEncoding ());
}

valtype
DecodeValueFromRPCOrThrow (const UniValue& val, const UniValue& opt)
{
  return DecodeNameValueFromRPCOrThrow (val, opt, "valueEncoding",
                                        ConfiguredValueEncoding ());
}

namespace
{

/**
 * Decodes the identifier for a name lookup according to the nameEncoding,
 * and also looks up the preimage if we look up by hash.
 */
valtype
GetNameForLookup (const UniValue& val, const UniValue& opt)
{
  const valtype identifier = DecodeNameFromRPCOrThrow (val, opt);

  RPCTypeCheckObj (opt,
    {
      {"byHash", UniValueType (UniValue::VSTR)},
    },
    true, false);

  if (!opt.exists ("byHash"))
    return identifier;

  const std::string byHashType = opt["byHash"].get_str ();
  if (byHashType == "direct")
    return identifier;

  if (g_name_hash_index == nullptr)
    throw std::runtime_error ("-namehashindex is not enabled");
  if (!g_name_hash_index->BlockUntilSyncedToCurrentChain ())
    throw std::runtime_error ("The name-hash index is not caught up yet");

  if (byHashType != "sha256d")
    {
      std::ostringstream msg;
      msg << "Invalid value for byHash: " << byHashType;
      throw JSONRPCError (RPC_INVALID_PARAMETER, msg.str ());
    }

  if (identifier.size () != 32)
    throw JSONRPCError (RPC_INVALID_PARAMETER,
                        "SHA-256d hash must be 32 bytes long");

  const uint256 hash(identifier);
  valtype name;
  if (!g_name_hash_index->FindNamePreimage (hash, name))
    {
      std::ostringstream msg;
      msg << "name hash not found: " << hash.GetHex ();
      throw JSONRPCError (RPC_WALLET_ERROR, msg.str ());
    }

  return name;
}

/**
 * Helper class that extracts the wallet for the current RPC request, if any.
 * It handles the case of disabled wallet support or no wallet being present,
 * so that it is suitable for the non-wallet RPCs here where we just want to
 * provide optional extra features (like the "ismine" field).
 *
 * The main benefit of having this class is that we can easily LOCK2 with the
 * wallet and another lock we need, without having to care about the special
 * cases where no wallet is present or wallet support is disabled.
 */
class MaybeWalletForRequest
{

private:

#ifdef ENABLE_WALLET
  std::shared_ptr<wallet::CWallet> wallet;
#endif

public:

  explicit MaybeWalletForRequest (const JSONRPCRequest& request)
  {
#ifdef ENABLE_WALLET
    try
      {
        /* GetWalletForJSONRPCRequest throws an internal error if there
           is no wallet context.  We want to handle this situation gracefully
           and just fall back to not having a wallet in this case.  */
        if (util::AnyPtr<wallet::WalletContext> (request.context))
          {
            wallet = wallet::GetWalletForJSONRPCRequest (request);
            return;
          }
      }
    catch (const UniValue& exc)
      {
        const auto& code = exc["code"];
        if (!code.isNum () || code.getInt<int> () != RPC_WALLET_NOT_SPECIFIED)
          throw;

      }

    /* If the wallet is not set, that's fine, and we just indicate it to
       other code (by having a null wallet).  */
    wallet = nullptr;
#endif
  }

  RecursiveMutex*
  getLock () const
  {
#ifdef ENABLE_WALLET
    return (wallet != nullptr ? &wallet->cs_wallet : nullptr);
#else
    return nullptr;
#endif
  }

#ifdef ENABLE_WALLET
  wallet::CWallet*
  getWallet ()
  {
    return wallet.get ();
  }

  const wallet::CWallet*
  getWallet () const
  {
    return wallet.get ();
  }
#endif

};

/**
 * Variant of addOwnershipInfo that uses a MaybeWalletForRequest.  This takes
 * care of disabled wallet support.
 */
void
addOwnershipInfo (const CScript& addr, const MaybeWalletForRequest& wallet,
                  UniValue& data)
{
#ifdef ENABLE_WALLET
  addOwnershipInfo (addr, wallet.getWallet (), data);
#endif
}

/**
 * Utility variant of getNameInfo that already includes ownership information.
 * This is the most common call for methods in this file.
 */
UniValue
getNameInfo (const ChainstateManager& chainman, const UniValue& options,
             const valtype& name, const CNameData& data,
             const MaybeWalletForRequest& wallet)
{
  UniValue res = getNameInfo (options, name, data);
  addOwnershipInfo (data.getAddress (), wallet, res);
  return res;
}

/** Named constant for optional RPCResult fields.  */
constexpr bool optional = true;

} // anonymous namespace

const RPCResult NameOpResult{RPCResult::Type::OBJ, "nameOp", optional,
    "The encoded name-operation (if the script has one)",
    {
      {RPCResult::Type::STR, "op", "The type of operation"},
      {RPCResult::Type::STR_HEX, "hash", optional, "Hash value for name_new"},
      {RPCResult::Type::STR_HEX, "rand", optional, "Seed value for name_firstupdate"},
      {RPCResult::Type::STR, "name", optional, "Name for updates"},
      {RPCResult::Type::STR, "name_error", optional, "Encoding error for the name, if any"},
      {RPCResult::Type::STR, "name_encoding", optional, "Encoding of the name"},
      {RPCResult::Type::STR, "value", optional, "Value for updates"},
      {RPCResult::Type::STR, "value_error", optional, "Encoding error for the value, if any"},
      {RPCResult::Type::STR, "value_encoding", optional, "Encoding of the value"},
    }};

/* ************************************************************************** */

NameInfoHelp::NameInfoHelp ()
{
  withField ({RPCResult::Type::STR, "name", optional, "the requested name"});
  withField ({RPCResult::Type::STR, "name_encoding", "the encoding of \"name\""});
  withField ({RPCResult::Type::STR, "name_error", optional,
              "replaces \"name\" in case there is an error"});
  withField ({RPCResult::Type::STR, "value", optional, "the name's current value"});
  withField ({RPCResult::Type::STR, "value_encoding", "the encoding of \"value\""});
  withField ({RPCResult::Type::STR, "value_error", optional,
              "replaces \"value\" in case there is an error"});

  withField ({RPCResult::Type::STR_HEX, "txid", "the name's last update tx"});
  withField ({RPCResult::Type::NUM, "vout",
              "the index of the name output in the last update"});
  withField ({RPCResult::Type::STR, "address", "the address holding the name"});
#ifdef ENABLE_WALLET
  withField ({RPCResult::Type::BOOL, "ismine", optional,
              "whether the name is owned by the wallet"});
#endif
}

NameInfoHelp&
NameInfoHelp::withHeight ()
{
  withField ({RPCResult::Type::NUM, "height", "the name's last update height"});
  return *this;
}

NameOptionsHelp::NameOptionsHelp ()
{}

NameOptionsHelp&
NameOptionsHelp::withArg (const std::string& name, const RPCArg::Type type,
                          const std::string& doc)
{
  return withArg (name, type, "", doc, {});
}

NameOptionsHelp&
NameOptionsHelp::withArg (const std::string& name, const RPCArg::Type type,
                          const std::string& doc,
                          const std::vector<RPCArg> inner)
{
  return withArg (name, type, "", doc, std::move (inner));
}

NameOptionsHelp&
NameOptionsHelp::withArg (const std::string& name, const RPCArg::Type type,
                          const std::string& defaultValue,
                          const std::string& doc)
{
  return withArg (name, type, defaultValue, doc, {});
}

NameOptionsHelp&
NameOptionsHelp::withArg (const std::string& name, const RPCArg::Type type,
                          const std::string& defaultValue,
                          const std::string& doc,
                          const std::vector<RPCArg> inner)
{
  RPCArg::Fallback fb;
  if (defaultValue.empty ())
    fb = RPCArg::Optional::OMITTED;
  else
    fb = defaultValue;

  if (inner.empty ())
    innerArgs.emplace_back (name, type, fb, doc);
  else
    innerArgs.emplace_back (name, type, fb, doc, std::move (inner));

  return *this;
}

NameOptionsHelp&
NameOptionsHelp::withWriteOptions ()
{
  withArg ("destAddress", RPCArg::Type::STR,
           "The address to send the name output to");

  withArg ("sendCoins", RPCArg::Type::OBJ_USER_KEYS,
           "Addresses to which coins should be sent additionally",
           {
              {"address", RPCArg::Type::AMOUNT, RPCArg::Optional::NO,
               "A key-value pair. The key (string) is the address,"
               " the value (float or string) is the amount in " + CURRENCY_UNIT}
           });

  withArg ("burn", RPCArg::Type::OBJ_USER_KEYS,
           "Data and amounts of BITS to burn in the transaction",
           {
              {"data", RPCArg::Type::AMOUNT, RPCArg::Optional::NO,
               "A key-value pair. The key (string) is the burn data,"
               " the value (float or string) is the amount in " + CURRENCY_UNIT}
           });

  return *this;
}

NameOptionsHelp&
NameOptionsHelp::withNameEncoding ()
{
  withArg ("nameEncoding", RPCArg::Type::STR,
           "Encoding (\"ascii\", \"utf8\" or \"hex\") of the name argument");
  return *this;
}

NameOptionsHelp&
NameOptionsHelp::withValueEncoding ()
{
  withArg ("valueEncoding", RPCArg::Type::STR,
           "Encoding (\"ascii\", \"utf8\" or \"hex\") of the value argument");
  return *this;
}

NameOptionsHelp&
NameOptionsHelp::withByHash ()
{
  withArg ("byHash", RPCArg::Type::STR,
           "Interpret \"name\" as hash (\"direct\" or \"sha256d\")");
  return *this;
}

RPCArg
NameOptionsHelp::buildRpcArg () const
{
  return RPCArg ("options", RPCArg::Type::OBJ,
                 RPCArg::Optional::OMITTED_NAMED_ARG,
                 "Options for this RPC call", innerArgs);
}

/* ************************************************************************** */
namespace
{

RPCHelpMan
name_show ()
{
  NameOptionsHelp optHelp;
  optHelp
      .withNameEncoding ()
      .withValueEncoding ()
      .withByHash ();

  return RPCHelpMan ("name_show",
      "\nLooks up the current data for the given name.  Fails if the name doesn't exist.\n",
      {
          {"name", RPCArg::Type::STR, RPCArg::Optional::NO, "The name to query for"},
          optHelp.buildRpcArg (),
      },
      NameInfoHelp ()
        .withHeight ()
        .finish (),
      RPCExamples {
          HelpExampleCli ("name_show", "\"myname\"")
        + HelpExampleRpc ("name_show", "\"myname\"")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params, {UniValue::VSTR, UniValue::VOBJ});
  auto& chainman = EnsureChainman (EnsureAnyNodeContext (request));

  if (chainman.ActiveChainstate ().IsInitialBlockDownload ())
    throw JSONRPCError(RPC_CLIENT_IN_INITIAL_DOWNLOAD,
                       "Playchain is downloading blocks...");

  UniValue options(UniValue::VOBJ);
  if (request.params.size () >= 2)
    options = request.params[1].get_obj ();

  const valtype name = GetNameForLookup (request.params[0], options);

  CNameData data;
  {
    LOCK (cs_main);
    if (!chainman.ActiveChainstate ().CoinsTip ().GetName (name, data))
      {
        std::ostringstream msg;
        msg << "name never existed: " << EncodeNameForMessage (name);
        throw JSONRPCError (RPC_WALLET_ERROR, msg.str ());
      }
  }

  MaybeWalletForRequest wallet(request);
  LOCK2 (wallet.getLock (), cs_main);
  return getNameInfo (chainman, options, name, data, wallet);
}
  );
}

/* ************************************************************************** */

RPCHelpMan
name_history ()
{
  NameOptionsHelp optHelp;
  optHelp
      .withNameEncoding ()
      .withValueEncoding ()
      .withByHash ();

  return RPCHelpMan ("name_history",
      "\nLooks up the current and all past data for the given name.  -namehistory must be enabled.\n",
      {
          {"name", RPCArg::Type::STR, RPCArg::Optional::NO, "The name to query for"},
          optHelp.buildRpcArg (),
      },
      RPCResult {RPCResult::Type::ARR, "", "",
          {
              NameInfoHelp ()
                .withHeight ()
                .finish ()
          }
      },
      RPCExamples {
          HelpExampleCli ("name_history", "\"myname\"")
        + HelpExampleRpc ("name_history", "\"myname\"")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params, {UniValue::VSTR, UniValue::VOBJ});
  auto& chainman = EnsureChainman (EnsureAnyNodeContext (request));

  if (!fNameHistory)
    throw std::runtime_error ("-namehistory is not enabled");

  if (chainman.ActiveChainstate ().IsInitialBlockDownload ())
    throw JSONRPCError(RPC_CLIENT_IN_INITIAL_DOWNLOAD,
                       "Playchain is downloading blocks...");

  UniValue options(UniValue::VOBJ);
  if (request.params.size () >= 2)
    options = request.params[1].get_obj ();

  const valtype name = GetNameForLookup (request.params[0], options);

  CNameData data;
  CNameHistory history;

  {
    LOCK (cs_main);

    const auto& coinsTip = chainman.ActiveChainstate ().CoinsTip ();
    if (!coinsTip.GetName (name, data))
      {
        std::ostringstream msg;
        msg << "name not found: " << EncodeNameForMessage (name);
        throw JSONRPCError (RPC_WALLET_ERROR, msg.str ());
      }

    if (!coinsTip.GetNameHistory (name, history))
      assert (history.empty ());
  }

  MaybeWalletForRequest wallet(request);
  LOCK2 (wallet.getLock (), cs_main);

  UniValue res(UniValue::VARR);
  for (const auto& entry : history.getData ())
    res.push_back (getNameInfo (chainman, options, name, entry, wallet));
  res.push_back (getNameInfo (chainman, options, name, data, wallet));

  return res;
}
  );
}

/* ************************************************************************** */

RPCHelpMan
name_scan ()
{
  NameOptionsHelp optHelp;
  optHelp
      .withNameEncoding ()
      .withValueEncoding ()
      .withArg ("minConf", RPCArg::Type::NUM, "1",
                "Minimum number of confirmations")
      .withArg ("maxConf", RPCArg::Type::NUM,
                "Maximum number of confirmations")
      .withArg ("prefix", RPCArg::Type::STR,
                "Filter for names with the given prefix")
      .withArg ("regexp", RPCArg::Type::STR,
                "Filter for names matching the regexp");

  return RPCHelpMan ("name_scan",
      "\nLists names in the database.\n",
      {
          {"start", RPCArg::Type::STR, RPCArg::Default{""}, "Skip initially to this name"},
          {"count", RPCArg::Type::NUM, RPCArg::Default{500}, "Stop after this many names"},
          optHelp.buildRpcArg (),
      },
      RPCResult {RPCResult::Type::ARR, "", "",
          {
              NameInfoHelp ()
                .withHeight ()
                .finish ()
          }
      },
      RPCExamples {
          HelpExampleCli ("name_scan", "")
        + HelpExampleCli ("name_scan", "\"d/abc\"")
        + HelpExampleCli ("name_scan", "\"d/abc\" 10")
        + HelpExampleRpc ("name_scan", "\"d/abc\"")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params,
                {UniValue::VSTR, UniValue::VNUM, UniValue::VOBJ});
  auto& chainman = EnsureChainman (EnsureAnyNodeContext (request));

  if (chainman.ActiveChainstate ().IsInitialBlockDownload ())
    throw JSONRPCError(RPC_CLIENT_IN_INITIAL_DOWNLOAD,
                       "Playchain is downloading blocks...");

  UniValue options(UniValue::VOBJ);
  if (request.params.size () >= 3)
    options = request.params[2].get_obj ();

  valtype start;
  if (!request.params[0].isNull ())
    start = DecodeNameFromRPCOrThrow (request.params[0], options);

  int count = 500;
  if (!request.params[1].isNull ())
    count = request.params[1].getInt<int> ();

  /* Parse and interpret the name_scan-specific options.  */
  RPCTypeCheckObj (options,
    {
      {"minConf", UniValueType (UniValue::VNUM)},
      {"maxConf", UniValueType (UniValue::VNUM)},
      {"prefix", UniValueType (UniValue::VSTR)},
      {"regexp", UniValueType (UniValue::VSTR)},
    },
    true, false);

  int minConf = 1;
  if (options.exists ("minConf"))
    minConf = options["minConf"].getInt<int> ();
  if (minConf < 1)
    throw JSONRPCError (RPC_INVALID_PARAMETER, "minConf must be >= 1");

  int maxConf = -1;
  if (options.exists ("maxConf"))
    {
      maxConf = options["maxConf"].getInt<int> ();
      if (maxConf < 0)
        throw JSONRPCError (RPC_INVALID_PARAMETER,
                            "maxConf must not be negative");
    }

  valtype prefix;
  if (options.exists ("prefix"))
    prefix = DecodeNameFromRPCOrThrow (options["prefix"], options);

  bool haveRegexp = false;
  boost::xpressive::sregex regexp;
  if (options.exists ("regexp"))
    {
      haveRegexp = true;
      regexp = boost::xpressive::sregex::compile (options["regexp"].get_str ());
    }

  /* Iterate over names and produce the result.  */
  UniValue res(UniValue::VARR);
  if (count <= 0)
    return res;

  MaybeWalletForRequest wallet(request);
  LOCK2 (wallet.getLock (), cs_main);

  const int maxHeight = chainman.ActiveHeight () - minConf + 1;
  int minHeight = -1;
  if (maxConf >= 0)
    minHeight = chainman.ActiveHeight () - maxConf + 1;

  valtype name;
  CNameData data;
  const auto& coinsTip = chainman.ActiveChainstate ().CoinsTip ();
  std::unique_ptr<CNameIterator> iter(coinsTip.IterateNames ());
  for (iter->seek (start); count > 0 && iter->next (name, data); )
    {
      const int height = data.getHeight ();
      if (height > maxHeight)
        continue;
      if (minHeight >= 0 && height < minHeight)
        continue;

      if (name.size () < prefix.size ())
        continue;
      if (!std::equal (prefix.begin (), prefix.end (), name.begin ()))
        continue;

      if (haveRegexp)
        {
          try
            {
              const std::string nameStr = EncodeName (name, NameEncoding::UTF8);
              boost::xpressive::smatch matches;
              if (!boost::xpressive::regex_search (nameStr, matches, regexp))
                continue;
            }
          catch (const InvalidNameString& exc)
            {
              continue;
            }
        }

      res.push_back (getNameInfo (chainman, options, name, data, wallet));
      --count;
    }

  return res;
}
  );
}

/* ************************************************************************** */

RPCHelpMan
name_pending ()
{
  NameOptionsHelp optHelp;
  optHelp
      .withNameEncoding ()
      .withValueEncoding ();

  return RPCHelpMan ("name_pending",
      "\nLists unconfirmed name operations in the mempool.\n"
      "\nIf a name is given, only check for operations on this name.\n",
      {
          {"name", RPCArg::Type::STR, RPCArg::Optional::OMITTED_NAMED_ARG, "Only look for this name"},
          optHelp.buildRpcArg (),
      },
      RPCResult {RPCResult::Type::ARR, "", "",
          {
              NameInfoHelp ()
                .withField ({RPCResult::Type::STR, "op", "the operation being performed"})
                .finish ()
          }
      },
      RPCExamples {
          HelpExampleCli ("name_pending", "")
        + HelpExampleCli ("name_pending", "\"d/domob\"")
        + HelpExampleRpc ("name_pending", "")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params, {UniValue::VSTR, UniValue::VOBJ}, true);

  MaybeWalletForRequest wallet(request);
  auto& mempool = EnsureMemPool (EnsureAnyNodeContext (request));
  LOCK2 (wallet.getLock (), mempool.cs);

  UniValue options(UniValue::VOBJ);
  if (request.params.size () >= 2)
    options = request.params[1].get_obj ();

  std::vector<uint256> txHashes;
  mempool.queryHashes (txHashes);

  const bool hasNameFilter = !request.params[0].isNull ();
  valtype nameFilter;
  if (hasNameFilter)
    nameFilter = DecodeNameFromRPCOrThrow (request.params[0], options);

  UniValue arr(UniValue::VARR);
  for (const auto& txHash : txHashes)
    {
      std::shared_ptr<const CTransaction> tx = mempool.get (txHash);
      if (!tx)
        continue;

      for (size_t n = 0; n < tx->vout.size (); ++n)
        {
          const auto& txOut = tx->vout[n];
          const CNameScript op(txOut.scriptPubKey);
          if (!op.isNameOp () || !op.isAnyUpdate ())
            continue;
          if (hasNameFilter && op.getOpName () != nameFilter)
            continue;

          UniValue obj = getNameInfo (options,
                                      op.getOpName (), op.getOpValue (),
                                      COutPoint (tx->GetHash (), n),
                                      op.getAddress ());
          addOwnershipInfo (op.getAddress (), wallet, obj);
          switch (op.getNameOp ())
            {
            case OP_NAME_REGISTER:
              obj.pushKV ("op", "name_register");
              break;
            case OP_NAME_UPDATE:
              obj.pushKV ("op", "name_update");
              break;
            default:
              assert (false);
            }

          arr.push_back (obj);
        }
    }

  return arr;
}
  );
}

/* ************************************************************************** */

namespace
{

/**
 * Performs the action of namerawtransaction and namepsbt on a given
 * CMutableTransaction.  This is used to share the code between the two
 * RPC methods.
 */
void
PerformNameRawtx (const unsigned nOut, const UniValue& nameOp,
                  CMutableTransaction& mtx)
{
  if (nOut >= mtx.vout.size ())
    throw JSONRPCError (RPC_INVALID_PARAMETER, "vout is out of range");
  auto& script = mtx.vout[nOut].scriptPubKey;

  /* namerawtransaction does not have an options argument.  This would just
     make the already long list of arguments longer.  Instead of using
     namerawtransaction, namecoin-tx can be used anyway to create name
     operations with arbitrary hex data.  */
  const UniValue NO_OPTIONS(UniValue::VOBJ);

  RPCTypeCheckObj (nameOp,
    {
      {"op", UniValueType (UniValue::VSTR)},
      {"name", UniValueType (UniValue::VSTR)},
      {"value", UniValueType (UniValue::VSTR)},
    }
  );

  const std::string op = find_value (nameOp, "op").get_str ();
  const valtype name
    = DecodeNameFromRPCOrThrow (find_value (nameOp, "name"), NO_OPTIONS);
  const valtype value
    = DecodeValueFromRPCOrThrow (find_value (nameOp, "value"), NO_OPTIONS);

  if (op == "name_register")
    script = CNameScript::buildNameRegister (script, name, value);
  else if (op == "name_update")
    script = CNameScript::buildNameUpdate (script, name, value);
  else
    throw JSONRPCError (RPC_INVALID_PARAMETER, "Invalid name operation");
}

} // anonymous namespace

RPCHelpMan
namerawtransaction ()
{
  return RPCHelpMan ("namerawtransaction",
      "\nAdds a name operation to an existing raw transaction.\n"
      "\nUse createrawtransaction first to create the basic transaction, including the required inputs and outputs also for the name.\n",
      {
          {"hexstring", RPCArg::Type::STR_HEX, RPCArg::Optional::NO, "The transaction hex string"},
          {"vout", RPCArg::Type::NUM, RPCArg::Optional::NO, "The vout of the desired name output"},
          {"nameop", RPCArg::Type::OBJ, RPCArg::Optional::NO, "The name operation to create",
              {
                  {"op", RPCArg::Type::STR, RPCArg::Optional::NO, "The operation to perform, can be \"name_register\" and \"name_update\""},
                  {"name", RPCArg::Type::STR, RPCArg::Optional::NO, "The name to operate on"},
                  {"value", RPCArg::Type::STR, RPCArg::Optional::NO, "The new value for the name"},
              },
          },
      },
      RPCResult {RPCResult::Type::OBJ, "", "",
          {
              {RPCResult::Type::STR_HEX, "hex", "Hex string of the updated transaction"},
          },
      },
      RPCExamples {
          HelpExampleCli ("namerawtransaction", R"("raw tx hex" 1 "{\"op\":\"name_register\",\"name\":\"my-name\",\"value\":\"first value\")")
        + HelpExampleCli ("namerawtransaction", R"("raw tx hex" 1 "{\"op\":\"name_update\",\"name\":\"my-name\",\"value\":\"new value\")")
        + HelpExampleRpc ("namerawtransaction", R"("raw tx hex", 1, "{\"op\":\"name_update\",\"name\":\"my-name\",\"value\":\"new value\")")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params,
                {UniValue::VSTR, UniValue::VNUM, UniValue::VOBJ});

  CMutableTransaction mtx;
  if (!DecodeHexTx (mtx, request.params[0].get_str (), true))
    throw JSONRPCError (RPC_DESERIALIZATION_ERROR, "TX decode failed");

  UniValue result(UniValue::VOBJ);

  PerformNameRawtx (request.params[1].getInt<int> (),
                    request.params[2].get_obj (), mtx);

  result.pushKV ("hex", EncodeHexTx (CTransaction (mtx)));
  return result;
}
  );
}

RPCHelpMan
namepsbt ()
{
  return RPCHelpMan ("namepsbt",
      "\nAdds a name operation to an existing PSBT.\n"
      "\nUse createpsbt first to create the basic transaction, including the required inputs and outputs also for the name.\n",
      {
          {"psbt", RPCArg::Type::STR, RPCArg::Optional::NO, "A base64 string of a PSBT"},
          {"vout", RPCArg::Type::NUM, RPCArg::Optional::NO, "The vout of the desired name output"},
          {"nameop", RPCArg::Type::OBJ, RPCArg::Optional::NO, "The name operation to create",
              {
                  {"op", RPCArg::Type::STR, RPCArg::Optional::NO, "The operation to perform, can be \"name_register\" and \"name_update\""},
                  {"name", RPCArg::Type::STR, RPCArg::Optional::NO, "The name to operate on"},
                  {"value", RPCArg::Type::STR, RPCArg::Optional::NO, "The new value for the name"},
              },
          },
      },
      RPCResult {RPCResult::Type::OBJ, "", "",
          {
              {RPCResult::Type::STR_HEX, "psbt", "The serialised, updated PSBT"},
          },
      },
      RPCExamples {
          HelpExampleCli ("namepsbt", R"("psbt" 1 "{\"op\":\"name_register\",\"name\":\"my-name\",\"value\":\"first value\")")
        + HelpExampleCli ("namepsbt", R"("psbt" 1 "{\"op\":\"name_update\",\"name\":\"my-name\",\"value\":\"new value\")")
        + HelpExampleRpc ("namepsbt", R"("psbt", 1, "{\"op\":\"name_update\",\"name\":\"my-name\",\"value\":\"new value\")")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  RPCTypeCheck (request.params,
                {UniValue::VSTR, UniValue::VNUM, UniValue::VOBJ});

  PartiallySignedTransaction psbtx;
  std::string error;
  if (!DecodeBase64PSBT (psbtx, request.params[0].get_str (), error))
    throw JSONRPCError (RPC_DESERIALIZATION_ERROR,
                        strprintf ("TX decode failed %s", error));

  UniValue result(UniValue::VOBJ);

  PerformNameRawtx (request.params[1].getInt<int> (),
                    request.params[2].get_obj (), *psbtx.tx);

  CDataStream ssTx(SER_NETWORK, PROTOCOL_VERSION);
  ssTx << psbtx;
  result.pushKV ("psbt", EncodeBase64 (MakeUCharSpan (ssTx)));

  return result;
}
  );
}

/* ************************************************************************** */

RPCHelpMan
name_checkdb ()
{
  return RPCHelpMan ("name_checkdb",
      "\nValidates the name DB's consistency.\n"
      "\nRoughly between blocks 139,000 and 180,000, this call is expected to fail due to the historic 'name stealing' bug.\n",
      {},
      RPCResult {RPCResult::Type::BOOL, "", "whether the state is valid"},
      RPCExamples {
          HelpExampleCli ("name_checkdb", "")
        + HelpExampleRpc ("name_checkdb", "")
      },
      [&] (const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
{
  node::NodeContext& node = EnsureAnyNodeContext (request);
  ChainstateManager& chainman = EnsureChainman (node);

  LOCK (cs_main);
  auto& coinsTip = chainman.ActiveChainstate ().CoinsTip ();
  coinsTip.Flush ();
  return coinsTip.ValidateNameDB (chainman.ActiveChainstate (),
                                  node.rpc_interruption_point);
}
  );
}

} // namespace
/* ************************************************************************** */

Span<const CRPCCommand> GetNameRPCCommands()
{
static const CRPCCommand commands[] =
{ //  category               actor (function)
  //  ---------------------  -----------------------
    { "names",               &name_show,               },
    { "names",               &name_history,            },
    { "names",               &name_scan,               },
    { "names",               &name_pending,            },
    { "names",               &name_checkdb,            },
    { "rawtransactions",     &namerawtransaction,      },
    { "rawtransactions",     &namepsbt,                },
};

  return Span {commands};
}

void RegisterNameRPCCommands(CRPCTable &t)
{
  for (const auto& c : GetNameRPCCommands ())
    t.appendCommand(c.name, &c);
}
