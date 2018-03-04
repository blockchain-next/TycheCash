// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "TycheCashBasicImpl.h"
#include "TycheCashFormatUtils.h"
#include "TycheCashTools.h"
#include "TycheCashSerialization.h"

#include "Common/Base58.h"
#include "crypto/hash.h"
#include "Common/int-util.h"

using namespace Crypto;
using namespace Common;

namespace TycheCash {

  /************************************************************************/
  /* TycheCash helper functions                                          */
  /************************************************************************/
  //-----------------------------------------------------------------------------------------------
  uint64_t getPenalizedAmount(uint64_t amount, size_t medianSize, size_t currentBlockSize) {
    static_assert(sizeof(size_t) >= sizeof(uint32_t), "size_t is too small");
    assert(currentBlockSize <= 2 * medianSize);
    assert(medianSize <= std::numeric_limits<uint32_t>::max());
    assert(currentBlockSize <= std::numeric_limits<uint32_t>::max());

    if (amount == 0) {
      return 0;
    }

    if (currentBlockSize <= medianSize) {
      return amount;
    }

    uint64_t productHi;
    // BUGFIX: 32-bit saturation bug (e.g. ARM7), the result was being
    // treated as 32-bit by default.
    uint64_t multiplicand = 2 * medianSize - currentBlockSize;
    multiplicand *= currentBlockSize;
    uint64_t productLo = mul128(amount, multiplicand, &productHi);

    uint64_t penalizedAmountHi;
    uint64_t penalizedAmountLo;
    div128_32(productHi, productLo, static_cast<uint32_t>(medianSize), &penalizedAmountHi, &penalizedAmountLo);
    div128_32(penalizedAmountHi, penalizedAmountLo, static_cast<uint32_t>(medianSize), &penalizedAmountHi, &penalizedAmountLo);

    assert(penalizedAmountHi == 0);
    assert(penalizedAmountLo < amount);

    return penalizedAmountLo;
  }
  //-----------------------------------------------------------------------
  std::string getAccountAddressAsStr(uint64_t prefix, const AccountPublicAddress& adr) {
    BinaryArray ba;
    bool r = toBinaryArray(adr, ba);
    assert(r);
    return Tools::Base58::encode_addr(prefix, Common::asString(ba));
  }
  //-----------------------------------------------------------------------
  bool is_coinbase(const Transaction& tx) {
    if(tx.inputs.size() != 1) {
      return false;
    }

    if(tx.inputs[0].type() != typeid(BaseInput)) {
      return false;
    }

    return true;
  }
  //-----------------------------------------------------------------------
  bool parseAccountAddressString(uint64_t& prefix, AccountPublicAddress& adr, const std::string& str) {
    std::string data;

    return
      Tools::Base58::decode_addr(str, prefix, data) &&
      fromBinaryArray(adr, asBinaryArray(data)) &&
      // ::serialization::parse_binary(data, adr) &&
      check_key(adr.spendPublicKey) &&
      check_key(adr.viewPublicKey);
  }
  //-----------------------------------------------------------------------
  bool operator ==(const TycheCash::Transaction& a, const TycheCash::Transaction& b) {
    return getObjectHash(a) == getObjectHash(b);
  }
  //-----------------------------------------------------------------------
  bool operator ==(const TycheCash::Block& a, const TycheCash::Block& b) {
    return TycheCash::get_block_hash(a) == TycheCash::get_block_hash(b);
  }
}

//--------------------------------------------------------------------------------
bool parse_hash256(const std::string& str_hash, Crypto::Hash& hash) {
  return Common::podFromHex(str_hash, hash);
}
