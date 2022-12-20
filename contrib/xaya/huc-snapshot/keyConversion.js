/*
Copyright (c) 2018 The Playchain developers
Distributed under the MIT software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
*/

/* Very basic JavaScript code that converts WIF private keys from Huntercoin
   to the key format used by Playchain (with the same underlying PKH).  It is based
   on the bs58check Node module for the base58check logic.

   The code is used to build a stand-alone HTML file that can be used
   online or offline to convert the keys.  This will be useful for claiming
   BITS balances from the Huntercoin snapshot.  */

let bs58check = require ('bs58check');

function convertWifKey (huc)
{
  const chiPrivkeyVersion = 130;
  data = bs58check.decode (huc);
  data[0] = chiPrivkeyVersion;
  return bs58check.encode (data);
}

function update ()
{
  const domIdHuc = "huc-privkey";
  const domIdChi = "bits-privkey";

  let huc = document.getElementById (domIdHuc).value;
  let bits;
  try
    {
      bits = convertWifKey (huc);
    }
  catch (err)
    {
      bits = "<invalid Huntercoin private key>";
    }
  let chiField = document.getElementById (domIdChi);
  chiField.value = bits;
}

function init ()
{
  const domIdForm = "conversion-form";
  document.getElementById (domIdForm).onsubmit = function ()
    {
      update ();

      /* Don't actually submit the form.  */
      return false;
    };
}

window.addEventListener ("load", init);
