// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/Account.h"
#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/TycheCashFormatUtils.h"

#include <Logging/LoggerGroup.h>

class single_tx_test_base
{
public:
  bool init()
  {
    using namespace TycheCash;

    Currency currency = CurrencyBuilder(m_nullLog).currency();
    m_bob.generate();

    if (!currency.constructMinerTx(0, 0, 0, 2, 0, m_bob.getAccountKeys().address, m_tx))
      return false;

    m_tx_pub_key = getTransactionPublicKeyFromExtra(m_tx.extra);
    return true;
  }

protected:

  Logging::LoggerGroup m_nullLog;
  TycheCash::AccountBase m_bob;
  TycheCash::Transaction m_tx;
  Crypto::PublicKey m_tx_pub_key;
};
