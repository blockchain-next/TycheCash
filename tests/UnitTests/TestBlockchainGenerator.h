// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>
#include <unordered_map>

#include "TycheCashCore/Account.h"
#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/Currency.h"
#include "TycheCashCore/BlockchainIndices.h"
#include "crypto/hash.h"

#include "../TestGenerator/TestGenerator.h"

class TestBlockchainGenerator
{
public:
  TestBlockchainGenerator(const TycheCash::Currency& currency);

  //TODO: get rid of this method
  std::vector<TycheCash::Block>& getBlockchain();
  std::vector<TycheCash::Block> getBlockchainCopy();
  void generateEmptyBlocks(size_t count);
  bool getBlockRewardForAddress(const TycheCash::AccountPublicAddress& address);
  bool generateTransactionsInOneBlock(const TycheCash::AccountPublicAddress& address, size_t n);
  bool getSingleOutputTransaction(const TycheCash::AccountPublicAddress& address, uint64_t amount);
  void addTxToBlockchain(const TycheCash::Transaction& transaction);
  bool getTransactionByHash(const Crypto::Hash& hash, TycheCash::Transaction& tx, bool checkTxPool = false);
  const TycheCash::AccountBase& getMinerAccount() const;
  bool generateFromBaseTx(const TycheCash::AccountBase& address);

  void putTxToPool(const TycheCash::Transaction& tx);
  void getPoolSymmetricDifference(std::vector<Crypto::Hash>&& known_pool_tx_ids, Crypto::Hash known_block_id, bool& is_bc_actual,
    std::vector<TycheCash::Transaction>& new_txs, std::vector<Crypto::Hash>& deleted_tx_ids);
  void putTxPoolToBlockchain();
  void clearTxPool();

  void cutBlockchain(uint32_t height);

  bool addOrphan(const Crypto::Hash& hash, uint32_t height);
  bool getGeneratedTransactionsNumber(uint32_t height, uint64_t& generatedTransactions);
  bool getOrphanBlockIdsByHeight(uint32_t height, std::vector<Crypto::Hash>& blockHashes);
  bool getBlockIdsByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t blocksNumberLimit, std::vector<Crypto::Hash>& hashes, uint32_t& blocksNumberWithinTimestamps);
  bool getPoolTransactionIdsByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t transactionsNumberLimit, std::vector<Crypto::Hash>& hashes, uint64_t& transactionsNumberWithinTimestamps);
  bool getTransactionIdsByPaymentId(const Crypto::Hash& paymentId, std::vector<Crypto::Hash>& transactionHashes);

  bool getTransactionGlobalIndexesByHash(const Crypto::Hash& transactionHash, std::vector<uint32_t>& globalIndexes);
  bool getMultisignatureOutputByGlobalIndex(uint64_t amount, uint32_t globalIndex, TycheCash::MultisignatureOutput& out);
  void setMinerAccount(const TycheCash::AccountBase& account);

private:
  struct MultisignatureOutEntry {
    Crypto::Hash transactionHash;
    uint16_t indexOut;
  };

  struct KeyOutEntry {
    Crypto::Hash transactionHash;
    uint16_t indexOut;
  };
  
  void addGenesisBlock();
  void addMiningBlock();

  const TycheCash::Currency& m_currency;
  test_generator generator;
  TycheCash::AccountBase miner_acc;
  std::vector<TycheCash::Block> m_blockchain;
  std::unordered_map<Crypto::Hash, TycheCash::Transaction> m_txs;
  std::unordered_map<Crypto::Hash, std::vector<uint32_t>> transactionGlobalOuts;
  std::unordered_map<uint64_t, std::vector<MultisignatureOutEntry>> multisignatureOutsIndex;
  std::unordered_map<uint64_t, std::vector<KeyOutEntry>> keyOutsIndex;

  std::unordered_map<Crypto::Hash, TycheCash::Transaction> m_txPool;
  mutable std::mutex m_mutex;

  TycheCash::PaymentIdIndex m_paymentIdIndex;
  TycheCash::TimestampTransactionsIndex m_timestampIndex;
  TycheCash::GeneratedTransactionsIndex m_generatedTransactionsIndex;
  TycheCash::OrphanBlocksIndex m_orthanBlocksIndex;

  void addToBlockchain(const TycheCash::Transaction& tx);
  void addToBlockchain(const std::vector<TycheCash::Transaction>& txs);
  void addToBlockchain(const std::vector<TycheCash::Transaction>& txs, const TycheCash::AccountBase& minerAddress);
  void addTx(const TycheCash::Transaction& tx);

  bool doGenerateTransactionsInOneBlock(TycheCash::AccountPublicAddress const &address, size_t n);
};
