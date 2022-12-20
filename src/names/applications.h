// Copyright (c) 2021 Jeremy Rand
// Copyright (c) 2022 The Playchain developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef H_BITCOIN_NAMES_APPLICATIONS
#define H_BITCOIN_NAMES_APPLICATIONS

#include <script/script.h>

#include <string>

enum class NameNamespace
{
    Game,
    Player,
    NonStandard,
};

NameNamespace NamespaceFromName (const std::string& name);
NameNamespace NamespaceFromName (const valtype& data);

std::string DescFromName (const valtype& name, NameNamespace ns);

#endif // H_BITCOIN_NAMES_APPLICATIONS
