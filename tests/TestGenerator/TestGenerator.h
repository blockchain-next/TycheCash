// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <list>
#include <vector>
#include <unordered_map>

#include "crypto/hash.h"
#include "TycheCashCore/TycheCashBasic.h"
#include "TycheCashCore/TycheCashBasicImpl.h"
#include "TycheCashCore/TycheCashFormatUtils.h"
#include "TycheCashCore/Currency.h"
#include "TycheCashCore/Difficulty.h"


class test_generator
{
public:
  struct BlockInfo {
    BlockInfo()
      : previousBlockHash()
      , alreadyGeneratedCoins(0)
      , blockSize(0) {
    }

    BlockInfo(Crypto::Hash aPrevId, uint64_t anAlreadyGeneratedCoins, size_t aBlockSize)
      : previousBlockHash(aPrevId)
      , alreadyGeneratedCoins(anAlreadyGeneratedCoins)
      , blockSize(aBlockSize) {
    }

    Crypto::Hash previousBlockHash;
    uint64_t alreadyGeneratedCoins;
    size_t blockSize;
  };

  enum BlockFields {
    bf_none      = 0,
    bf_major_ver = 1 << 0,
    bf_minor_ver = 1 << 1,
    bf_timestamp = 1 << 2,
    bf_prev_id   = 1 << 3,
    bf_miner_tx  = 1 << 4,
    bf_tx_hashes = 1 << 5,
    bf_diffic    = 1 << 6
  };

  test_generator(const TycheCash::Currency& currency, uint8_t majorVersion = TycheCash::BLOCK_MAJOR_VERSION_1,
                 uint8_t minorVersion = TycheCash::BLOCK_MINOR_VERSION_0)
    : m_currency(currency), defaultMajorVersion(majorVersion), defaultMinorVersion(minorVersion) {
  }


  uint8_t defaultMajorVersion;
  uint8_t defaultMinorVersion;

  const TycheCash::Currency& currency() const { return m_currency; }

  void getBlockchain(std::vector<BlockInfo>& blockchain, const Crypto::Hash& head, size_t n) const;
  void getLastNBlockSizes(std::vector<size_t>& blockSizes, const Crypto::Hash& head, size_t n) const;
  uint64_t getAlreadyGeneratedCoins(const Crypto::Hash& blockId) const;
  uint64_t getAlreadyGeneratedCoins(const TycheCash::Block& blk) const;

  void addBlock(const TycheCash::Block& blk, size_t tsxSize, uint64_t fee, std::vector<size_t>& blockSizes,
    uint64_t alreadyGeneratedCoins);
  bool constructBlock(TycheCash::Block& blk, uint32_t height, const Crypto::Hash& previousBlockHash,
    const TycheCash::AccountBase& minerAcc, uint64_t timestamp, uint64_t alreadyGeneratedCoins,
    std::vector<size_t>& blockSizes, const std::list<TycheCash::Transaction>& txList);
  bool constructBlock(TycheCash::Block& blk, const TycheCash::AccountBase& minerAcc, uint64_t timestamp);
  bool constructBlock(TycheCash::Block& blk, const TycheCash::Block& blkPrev, const TycheCash::AccountBase& minerAcc,
    const std::list<TycheCash::Transaction>& txList = std::list<TycheCash::Transaction>());

  bool constructBlockManually(TycheCash::Block& blk, const TycheCash::Block& prevBlock,
    const TycheCash::AccountBase& minerAcc, int actualParams = bf_none, uint8_t majorVer = 0,
    uint8_t minorVer = 0, uint64_t timestamp = 0, const Crypto::Hash& previousBlockHash = Crypto::Hash(),
    const TycheCash::difficulty_type& diffic = 1, const TycheCash::Transaction& baseTransaction = TycheCash::Transaction(),
    const std::vector<Crypto::Hash>& transactionHashes = std::vector<Crypto::Hash>(), size_t txsSizes = 0, uint64_t fee = 0);
  bool constructBlockManuallyTx(TycheCash::Block& blk, const TycheCash::Block& prevBlock,
    const TycheCash::AccountBase& minerAcc, const std::vector<Crypto::Hash>& transactionHashes, size_t txsSize);
  bool constructMaxSizeBlock(TycheCash::Block& blk, const TycheCash::Block& blkPrev,
    const TycheCash::AccountBase& minerAccount, size_t medianBlockCount = 0,
    const std::list<TycheCash::Transaction>& txList = std::list<TycheCash::Transaction>());

private:
  const TycheCash::Currency& m_currency;
  std::unordered_map<Crypto::Hash, BlockInfo> m_blocksInfo;
};

inline TycheCash::difficulty_type getTestDifficulty() { return 1; }
void fillNonce(TycheCash::Block& blk, const TycheCash::difficulty_type& diffic);

bool constructMinerTxManually(const TycheCash::Currency& currency, uint32_t height, uint64_t alreadyGeneratedCoins,
  const TycheCash::AccountPublicAddress& minerAddress, TycheCash::Transaction& tx, uint64_t fee,
  TycheCash::KeyPair* pTxKey = 0);
bool constructMinerTxBySize(const TycheCash::Currency& currency, TycheCash::Transaction& baseTransaction, uint32_t height,
  uint64_t alreadyGeneratedCoins, const TycheCash::AccountPublicAddress& minerAddress,
  std::vector<size_t>& blockSizes, size_t targetTxSize, size_t targetBlockSize, uint64_t fee = 0);
