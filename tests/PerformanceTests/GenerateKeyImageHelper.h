// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/TycheCashFormatUtils.h"

#include "SingleTransactionTestBase.h"

class test_generate_key_image_helper : public single_tx_test_base
{
public:
  static const size_t loop_count = 500;

  bool test()
  {
    TycheCash::KeyPair in_ephemeral;
    Crypto::KeyImage ki;
    return TycheCash::generate_key_image_helper(m_bob.getAccountKeys(), m_tx_pub_key, 0, in_ephemeral, ki);
  }
};
