// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/TycheCashFormatUtils.h"

#include "SingleTransactionTestBase.h"

class test_is_out_to_acc : public single_tx_test_base
{
public:
  static const size_t loop_count = 1000;

  bool test()
  {
    const TycheCash::KeyOutput& tx_out = boost::get<TycheCash::KeyOutput>(m_tx.outputs[0].target);
    return TycheCash::is_out_to_acc(m_bob.getAccountKeys(), tx_out, m_tx_pub_key, 0);
  }
};
