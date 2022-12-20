// Copyright (c) 2018 The Playchain developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/* Command-line utility to compute the PoW hash of a block header given in hex.
   This is used for the regtests to access Neoscrypt from Python.  */

#include <core_io.h>
#include <powdata.h>
#include <primitives/pureheader.h>
#include <uint256.h>

#include <cstdlib>
#include <iostream>

int main (int argc, char** argv)
{
  if (argc != 3)
    {
      std::cerr << "USAGE: playchain-hash ALGO BLOCK-HEADER-HEX" << std::endl;
      return EXIT_FAILURE;
    }
  const std::string algoStr(argv[1]);
  const std::string hex(argv[2]);

  CPureBlockHeader header;
  if (!DecodeHexPureHeader (header, hex))
    {
      std::cerr << "Failed to decode block header." << std::endl;
      return EXIT_FAILURE;
    }

  try
    {
      const uint256 hash = header.GetPowHash (PowAlgoFromString (algoStr));
      std::cout << hash.GetHex () << std::endl;
    }
  catch (const std::exception& exc)
    {
      std::cerr << "Error: " << exc.what () << std::endl;
      return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
