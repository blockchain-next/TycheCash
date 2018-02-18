// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/Account.h"
#include "TycheCashCore/TycheCashFormatUtils.h"
#include "TycheCashCore/Currency.h"

class TransactionBuilder {
public:

  typedef std::vector<TycheCash::AccountKeys> KeysVector;
  typedef std::vector<Crypto::Signature> SignatureVector;
  typedef std::vector<SignatureVector> SignatureMultivector;

  struct MultisignatureSource {
    TycheCash::MultisignatureInput input;
    KeysVector keys;
    Crypto::PublicKey srcTxPubKey;
    size_t srcOutputIndex;
  };

  TransactionBuilder(const TycheCash::Currency& currency, uint64_t unlockTime = 0);

  // regenerate transaction keys
  TransactionBuilder& newTxKeys();
  TransactionBuilder& setTxKeys(const TycheCash::KeyPair& txKeys);

  // inputs
  TransactionBuilder& setInput(const std::vector<TycheCash::TransactionSourceEntry>& sources, const TycheCash::AccountKeys& senderKeys);
  TransactionBuilder& addMultisignatureInput(const MultisignatureSource& source);

  // outputs
  TransactionBuilder& setOutput(const std::vector<TycheCash::TransactionDestinationEntry>& destinations);
  TransactionBuilder& addOutput(const TycheCash::TransactionDestinationEntry& dest);
  TransactionBuilder& addMultisignatureOut(uint64_t amount, const KeysVector& keys, uint32_t required);

  TycheCash::Transaction build() const;

  std::vector<TycheCash::TransactionSourceEntry> m_sources;
  std::vector<TycheCash::TransactionDestinationEntry> m_destinations;

private:

  void fillInputs(TycheCash::Transaction& tx, std::vector<TycheCash::KeyPair>& contexts) const;
  void fillOutputs(TycheCash::Transaction& tx) const;
  void signSources(const Crypto::Hash& prefixHash, const std::vector<TycheCash::KeyPair>& contexts, TycheCash::Transaction& tx) const;

  struct MultisignatureDestination {
    uint64_t amount;
    uint32_t requiredSignatures;
    KeysVector keys;
  };

  TycheCash::AccountKeys m_senderKeys;

  std::vector<MultisignatureSource> m_msigSources;
  std::vector<MultisignatureDestination> m_msigDestinations;

  size_t m_version;
  uint64_t m_unlockTime;
  TycheCash::KeyPair m_txKey;
  const TycheCash::Currency& m_currency;
};
