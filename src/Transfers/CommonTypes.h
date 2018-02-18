// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <array>
#include <memory>
#include <cstdint>

#include <boost/optional.hpp>

#include "INode.h"
#include "ITransaction.h"

namespace TycheCash {

struct BlockchainInterval {
  uint32_t startHeight;
  std::vector<Crypto::Hash> blocks;
};

struct CompleteBlock {
  Crypto::Hash blockHash;
  boost::optional<TycheCash::Block> block;
  // first transaction is always coinbase
  std::list<std::shared_ptr<ITransactionReader>> transactions;
};

}
