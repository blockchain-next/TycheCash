// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <future>
#include <map>
#include <mutex>

#include "crypto/hash.h"
#include "IWalletLegacy.h"

namespace TycheCash {
namespace WalletHelper {

class SaveWalletResultObserver : public TycheCash::IWalletLegacyObserver {
public:
  std::promise<std::error_code> saveResult;
  virtual void saveCompleted(std::error_code result) override { saveResult.set_value(result); }
};

class InitWalletResultObserver : public TycheCash::IWalletLegacyObserver {
public:
  std::promise<std::error_code> initResult;
  virtual void initCompleted(std::error_code result) override { initResult.set_value(result); }
};

class SendCompleteResultObserver : public TycheCash::IWalletLegacyObserver {
public:
  virtual void sendTransactionCompleted(TycheCash::TransactionId transactionId, std::error_code result) override;
  std::error_code wait(TycheCash::TransactionId transactionId);

private:
  std::mutex m_mutex;
  std::condition_variable m_condition;
  std::map<TycheCash::TransactionId, std::error_code> m_finishedTransactions;
  std::error_code m_result;
};

class IWalletRemoveObserverGuard {
public:
  IWalletRemoveObserverGuard(TycheCash::IWalletLegacy& wallet, TycheCash::IWalletLegacyObserver& observer);
  ~IWalletRemoveObserverGuard();

  void removeObserver();

private:
  TycheCash::IWalletLegacy& m_wallet;
  TycheCash::IWalletLegacyObserver& m_observer;
  bool m_removed;
};

void prepareFileNames(const std::string& file_path, std::string& keys_file, std::string& wallet_file);
void storeWallet(TycheCash::IWalletLegacy& wallet, const std::string& walletFilename);

}
}
