// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <list>
#include <vector>

#include "TycheCashCore/TycheCashBasic.h"
#include "IWalletLegacy.h"
#include "ITransfersContainer.h"

namespace TycheCash {

struct TxDustPolicy
{
  uint64_t dustThreshold;
  bool addToFee;
  TycheCash::AccountPublicAddress addrForDust;

  TxDustPolicy(uint64_t a_dust_threshold = 0, bool an_add_to_fee = true, TycheCash::AccountPublicAddress an_addr_for_dust = TycheCash::AccountPublicAddress())
    : dustThreshold(a_dust_threshold), addToFee(an_add_to_fee), addrForDust(an_addr_for_dust) {}
};

struct SendTransactionContext
{
  TransactionId transactionId;
  std::vector<TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount> outs;
  uint64_t foundMoney;
  std::list<TransactionOutputInformation> selectedTransfers;
  TxDustPolicy dustPolicy;
  uint64_t mixIn;
};

} //namespace TycheCash
