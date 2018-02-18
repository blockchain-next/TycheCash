// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/TycheCashBasic.h"

namespace TycheCash {

  struct BlockInfo {
    uint32_t height;
    Crypto::Hash id;

    BlockInfo() {
      clear();
    }

    void clear() {
      height = 0;
      id = TycheCash::NULL_HASH;
    }

    bool empty() const {
      return id == TycheCash::NULL_HASH;
    }
  };

  class ITransactionValidator {
  public:
    virtual ~ITransactionValidator() {}
    
    virtual bool checkTransactionInputs(const TycheCash::Transaction& tx, BlockInfo& maxUsedBlock) = 0;
    virtual bool checkTransactionInputs(const TycheCash::Transaction& tx, BlockInfo& maxUsedBlock, BlockInfo& lastFailed) = 0;
    virtual bool haveSpentKeyImages(const TycheCash::Transaction& tx) = 0;
    virtual bool checkTransactionSize(size_t blobSize) = 0;
  };

}
