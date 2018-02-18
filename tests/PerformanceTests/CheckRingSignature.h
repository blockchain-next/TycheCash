// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>

#include "TycheCashCore/Account.h"
#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/TycheCashFormatUtils.h"
#include "TycheCashCore/TycheCashTools.h"
#include "crypto/crypto.h"

#include "MultiTransactionTestBase.h"

template<size_t a_ring_size>
class test_check_ring_signature : private multi_tx_test_base<a_ring_size>
{
  static_assert(0 < a_ring_size, "ring_size must be greater than 0");

public:
  static const size_t loop_count = a_ring_size < 100 ? 100 : 10;
  static const size_t ring_size = a_ring_size;

  typedef multi_tx_test_base<a_ring_size> base_class;

  bool init()
  {
    using namespace TycheCash;

    if (!base_class::init())
      return false;

    m_alice.generate();

    std::vector<TransactionDestinationEntry> destinations;
    destinations.push_back(TransactionDestinationEntry(this->m_source_amount, m_alice.getAccountKeys().address));

    if (!constructTransaction(this->m_miners[this->real_source_idx].getAccountKeys(), this->m_sources, destinations, std::vector<uint8_t>(), m_tx, 0, this->m_logger))
      return false;

    getObjectHash(*static_cast<TransactionPrefix*>(&m_tx), m_tx_prefix_hash);

    return true;
  }

  bool test()
  {
    const TycheCash::KeyInput& txin = boost::get<TycheCash::KeyInput>(m_tx.inputs[0]);
    return Crypto::check_ring_signature(m_tx_prefix_hash, txin.keyImage, this->m_public_key_ptrs, ring_size, m_tx.signatures[0].data());
  }

private:
  TycheCash::AccountBase m_alice;
  TycheCash::Transaction m_tx;
  Crypto::Hash m_tx_prefix_hash;
};
