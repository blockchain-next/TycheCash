// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <vector>

#include "crypto/hash.h"

namespace TycheCash
{
  typedef std::uint64_t difficulty_type;

  bool check_hash(const Crypto::Hash &hash, difficulty_type difficulty);
}
