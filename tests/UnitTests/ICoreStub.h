// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <unordered_map>

#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/ICore.h"
#include "TycheCashCore/ICoreObserver.h"
#include "TycheCashProtocol/TycheCashProtocolDefinitions.h"
#include "Rpc/CoreRpcServerCommandsDefinitions.h"

class ICoreStub: public TycheCash::ICore {
public:
  ICoreStub();
  ICoreStub(const TycheCash::Block& genesisBlock);

  virtual bool addObserver(TycheCash::ICoreObserver* observer) override;
  virtual bool removeObserver(TycheCash::ICoreObserver* observer) override;
  virtual void get_blockchain_top(uint32_t& height, Crypto::Hash& top_id) override;
  virtual std::vector<Crypto::Hash> findBlockchainSupplement(const std::vector<Crypto::Hash>& remoteBlockIds, size_t maxCount,
    uint32_t& totalBlockCount, uint32_t& startBlockIndex) override;
  virtual bool get_random_outs_for_amounts(const TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_request& req,
      TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_response& res) override;
  virtual bool get_tx_outputs_gindexs(const Crypto::Hash& tx_id, std::vector<uint32_t>& indexs) override;
  virtual TycheCash::i_TycheCash_protocol* get_protocol() override;
  virtual bool handle_incoming_tx(TycheCash::BinaryArray const& tx_blob, TycheCash::tx_verification_context& tvc, bool keeped_by_block) override;
  virtual std::vector<TycheCash::Transaction> getPoolTransactions() override;
  virtual bool getPoolChanges(const Crypto::Hash& tailBlockId, const std::vector<Crypto::Hash>& knownTxsIds,
                              std::vector<TycheCash::Transaction>& addedTxs, std::vector<Crypto::Hash>& deletedTxsIds) override;
  virtual bool getPoolChangesLite(const Crypto::Hash& tailBlockId, const std::vector<Crypto::Hash>& knownTxsIds,
          std::vector<TycheCash::TransactionPrefixInfo>& addedTxs, std::vector<Crypto::Hash>& deletedTxsIds) override;
  virtual void getPoolChanges(const std::vector<Crypto::Hash>& knownTxsIds, std::vector<TycheCash::Transaction>& addedTxs,
                              std::vector<Crypto::Hash>& deletedTxsIds) override;
  virtual bool queryBlocks(const std::vector<Crypto::Hash>& block_ids, uint64_t timestamp,
    uint32_t& start_height, uint32_t& current_height, uint32_t& full_offset, std::vector<TycheCash::BlockFullInfo>& entries) override;
  virtual bool queryBlocksLite(const std::vector<Crypto::Hash>& block_ids, uint64_t timestamp,
    uint32_t& start_height, uint32_t& current_height, uint32_t& full_offset, std::vector<TycheCash::BlockShortInfo>& entries) override;

  virtual bool have_block(const Crypto::Hash& id) override;
  std::vector<Crypto::Hash> buildSparseChain() override;
  std::vector<Crypto::Hash> buildSparseChain(const Crypto::Hash& startBlockId) override;
  virtual bool get_stat_info(TycheCash::core_stat_info& st_inf) override { return false; }
  virtual bool on_idle() override { return false; }
  virtual void pause_mining() override {}
  virtual void update_block_template_and_resume_mining() override {}
  virtual bool handle_incoming_block_blob(const TycheCash::BinaryArray& block_blob, TycheCash::block_verification_context& bvc, bool control_miner, bool relay_block) override { return false; }
  virtual bool handle_get_objects(TycheCash::NOTIFY_REQUEST_GET_OBJECTS::request& arg, TycheCash::NOTIFY_RESPONSE_GET_OBJECTS::request& rsp) override { return false; }
  virtual void on_synchronized() override {}
  virtual bool getOutByMSigGIndex(uint64_t amount, uint64_t gindex, TycheCash::MultisignatureOutput& out) override { return true; }
  virtual size_t addChain(const std::vector<const TycheCash::IBlock*>& chain) override;

  virtual Crypto::Hash getBlockIdByHeight(uint32_t height) override;
  virtual bool getBlockByHash(const Crypto::Hash &h, TycheCash::Block &blk) override;
  virtual bool getBlockHeight(const Crypto::Hash& blockId, uint32_t& blockHeight) override;
  virtual void getTransactions(const std::vector<Crypto::Hash>& txs_ids, std::list<TycheCash::Transaction>& txs, std::list<Crypto::Hash>& missed_txs, bool checkTxPool = false) override;
  virtual bool getBackwardBlocksSizes(uint32_t fromHeight, std::vector<size_t>& sizes, size_t count) override;
  virtual bool getBlockSize(const Crypto::Hash& hash, size_t& size) override;
  virtual bool getAlreadyGeneratedCoins(const Crypto::Hash& hash, uint64_t& generatedCoins) override;
  virtual bool getBlockReward(size_t medianSize, size_t currentBlockSize, uint64_t alreadyGeneratedCoins, uint64_t fee,
      uint64_t& reward, int64_t& emissionChange) override;
  virtual bool scanOutputkeysForIndices(const TycheCash::KeyInput& txInToKey, std::list<std::pair<Crypto::Hash, size_t>>& outputReferences) override;
  virtual bool getBlockDifficulty(uint32_t height, TycheCash::difficulty_type& difficulty) override;
  virtual bool getBlockContainingTx(const Crypto::Hash& txId, Crypto::Hash& blockId, uint32_t& blockHeight) override;
  virtual bool getMultisigOutputReference(const TycheCash::MultisignatureInput& txInMultisig, std::pair<Crypto::Hash, size_t>& outputReference) override;

  virtual bool getGeneratedTransactionsNumber(uint32_t height, uint64_t& generatedTransactions) override;
  virtual bool getOrphanBlocksByHeight(uint32_t height, std::vector<TycheCash::Block>& blocks) override;
  virtual bool getBlocksByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t blocksNumberLimit, std::vector<TycheCash::Block>& blocks, uint32_t& blocksNumberWithinTimestamps) override;
  virtual bool getPoolTransactionsByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t transactionsNumberLimit, std::vector<TycheCash::Transaction>& transactions, uint64_t& transactionsNumberWithinTimestamps) override;
  virtual bool getTransactionsByPaymentId(const Crypto::Hash& paymentId, std::vector<TycheCash::Transaction>& transactions) override;
  virtual std::unique_ptr<TycheCash::IBlock> getBlock(const Crypto::Hash& blockId) override;
  virtual bool handleIncomingTransaction(const TycheCash::Transaction& tx, const Crypto::Hash& txHash, size_t blobSize, TycheCash::tx_verification_context& tvc, bool keptByBlock) override;
  virtual std::error_code executeLocked(const std::function<std::error_code()>& func) override;

  virtual bool addMessageQueue(TycheCash::MessageQueue<TycheCash::BlockchainMessage>& messageQueuePtr) override;
  virtual bool removeMessageQueue(TycheCash::MessageQueue<TycheCash::BlockchainMessage>& messageQueuePtr) override;


  void set_blockchain_top(uint32_t height, const Crypto::Hash& top_id);
  void set_outputs_gindexs(const std::vector<uint32_t>& indexs, bool result);
  void set_random_outs(const TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_response& resp, bool result);

  void addBlock(const TycheCash::Block& block);
  void addTransaction(const TycheCash::Transaction& tx);

  void setPoolTxVerificationResult(bool result);
  void setPoolChangesResult(bool result);

private:
  uint32_t topHeight;
  Crypto::Hash topId;

  std::vector<uint32_t> globalIndices;
  bool globalIndicesResult;

  TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_response randomOuts;
  bool randomOutsResult;

  std::unordered_map<Crypto::Hash, TycheCash::Block> blocks;
  std::unordered_map<uint32_t, Crypto::Hash> blockHashByHeightIndex;
  std::unordered_map<Crypto::Hash, Crypto::Hash> blockHashByTxHashIndex;

  std::unordered_map<Crypto::Hash, TycheCash::Transaction> transactions;
  std::unordered_map<Crypto::Hash, TycheCash::Transaction> transactionPool;
  bool poolTxVerificationResult;
  bool poolChangesResult;
};
