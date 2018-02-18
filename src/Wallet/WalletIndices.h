// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <map>
#include <unordered_map>

#include "ITransfersContainer.h"
#include "IWallet.h"
#include "IWalletLegacy.h" //TODO: make common types for all of our APIs (such as PublicKey, KeyPair, etc)

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/member.hpp>

namespace TycheCash {

const uint64_t ACCOUNT_CREATE_TIME_ACCURACY = 60 * 60 * 24;

struct WalletRecord {
  Crypto::PublicKey spendPublicKey;
  Crypto::SecretKey spendSecretKey;
  TycheCash::ITransfersContainer* container = nullptr;
  uint64_t pendingBalance = 0;
  uint64_t actualBalance = 0;
  time_t creationTimestamp;
};

struct RandomAccessIndex {};
struct KeysIndex {};
struct TransfersContainerIndex {};

struct WalletIndex {};
struct TransactionOutputIndex {};
struct BlockHeightIndex {};

struct TransactionHashIndex {};
struct TransactionIndex {};
struct BlockHashIndex {};

typedef boost::multi_index_container <
  WalletRecord,
  boost::multi_index::indexed_by <
    boost::multi_index::random_access < boost::multi_index::tag <RandomAccessIndex> >,
    boost::multi_index::hashed_unique < boost::multi_index::tag <KeysIndex>,
    BOOST_MULTI_INDEX_MEMBER(WalletRecord, Crypto::PublicKey, spendPublicKey)>,
    boost::multi_index::hashed_unique < boost::multi_index::tag <TransfersContainerIndex>,
      BOOST_MULTI_INDEX_MEMBER(WalletRecord, TycheCash::ITransfersContainer*, container) >
  >
> WalletsContainer;

struct UnlockTransactionJob {
  uint32_t blockHeight;
  TycheCash::ITransfersContainer* container;
  Crypto::Hash transactionHash;
};

typedef boost::multi_index_container <
  UnlockTransactionJob,
  boost::multi_index::indexed_by <
    boost::multi_index::ordered_non_unique < boost::multi_index::tag <BlockHeightIndex>,
    BOOST_MULTI_INDEX_MEMBER(UnlockTransactionJob, uint32_t, blockHeight)
    >,
    boost::multi_index::hashed_non_unique < boost::multi_index::tag <TransactionHashIndex>,
      BOOST_MULTI_INDEX_MEMBER(UnlockTransactionJob, Crypto::Hash, transactionHash)
    >
  >
> UnlockTransactionJobs;

typedef boost::multi_index_container <
  TycheCash::WalletTransaction,
  boost::multi_index::indexed_by <
    boost::multi_index::random_access < boost::multi_index::tag <RandomAccessIndex> >,
    boost::multi_index::hashed_unique < boost::multi_index::tag <TransactionIndex>,
      boost::multi_index::member<TycheCash::WalletTransaction, Crypto::Hash, &TycheCash::WalletTransaction::hash >
    >,
    boost::multi_index::ordered_non_unique < boost::multi_index::tag <BlockHeightIndex>,
      boost::multi_index::member<TycheCash::WalletTransaction, uint32_t, &TycheCash::WalletTransaction::blockHeight >
    >
  >
> WalletTransactions;

typedef std::pair<size_t, TycheCash::WalletTransfer> TransactionTransferPair;
typedef std::vector<TransactionTransferPair> WalletTransfers;
typedef std::map<size_t, TycheCash::Transaction> UncommitedTransactions;

typedef boost::multi_index_container<
  Crypto::Hash,
  boost::multi_index::indexed_by <
    boost::multi_index::random_access<
      boost::multi_index::tag<BlockHeightIndex>
    >,
    boost::multi_index::hashed_unique<
      boost::multi_index::tag<BlockHashIndex>,
      boost::multi_index::identity<Crypto::Hash>
    >
  >
> BlockHashesContainer;

}
