// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "PaymentServiceJsonRpcMessages.h"
#include "Serialization/SerializationOverloads.h"

namespace PaymentService {

void Reset::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(viewSecretKey, "viewSecretKey");
}

void Reset::Response::serialize(TycheCash::ISerializer& serializer) {
}

void GetViewKey::Request::serialize(TycheCash::ISerializer& serializer) {
}

void GetViewKey::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(viewSecretKey, "viewSecretKey");
}

void GetStatus::Request::serialize(TycheCash::ISerializer& serializer) {
}

void GetStatus::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(blockCount, "blockCount");
  serializer(knownBlockCount, "knownBlockCount");
  serializer(lastBlockHash, "lastBlockHash");
  serializer(peerCount, "peerCount");
}

void GetAddresses::Request::serialize(TycheCash::ISerializer& serializer) {
}

void GetAddresses::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(addresses, "addresses");
}

void CreateAddress::Request::serialize(TycheCash::ISerializer& serializer) {
  bool hasSecretKey = serializer(spendSecretKey, "spendSecretKey");
  bool hasPublicKey = serializer(spendPublicKey, "spendPublicKey");

  if (hasSecretKey && hasPublicKey) {
    //TODO: replace it with error codes
    throw RequestSerializationError();
  }
}

void CreateAddress::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(address, "address");
}

void DeleteAddress::Request::serialize(TycheCash::ISerializer& serializer) {
  if (!serializer(address, "address")) {
    throw RequestSerializationError();
  }
}

void DeleteAddress::Response::serialize(TycheCash::ISerializer& serializer) {
}

void GetSpendKeys::Request::serialize(TycheCash::ISerializer& serializer) {
  if (!serializer(address, "address")) {
    throw RequestSerializationError();
  }
}

void GetSpendKeys::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(spendSecretKey, "spendSecretKey");
  serializer(spendPublicKey, "spendPublicKey");
}

void GetBalance::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(address, "address");
}

void GetBalance::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(availableBalance, "availableBalance");
  serializer(lockedAmount, "lockedAmount");
}

void GetBlockHashes::Request::serialize(TycheCash::ISerializer& serializer) {
  bool r = serializer(firstBlockIndex, "firstBlockIndex");
  r &= serializer(blockCount, "blockCount");

  if (!r) {
    throw RequestSerializationError();
  }
}

void GetBlockHashes::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(blockHashes, "blockHashes");
}

void TransactionHashesInBlockRpcInfo::serialize(TycheCash::ISerializer& serializer) {
  serializer(blockHash, "blockHash");
  serializer(transactionHashes, "transactionHashes");
}

void GetTransactionHashes::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(addresses, "addresses");

  if (serializer(blockHash, "blockHash") == serializer(firstBlockIndex, "firstBlockIndex")) {
    throw RequestSerializationError();
  }

  if (!serializer(blockCount, "blockCount")) {
    throw RequestSerializationError();
  }

  serializer(paymentId, "paymentId");
}

void GetTransactionHashes::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(items, "items");
}

void TransferRpcInfo::serialize(TycheCash::ISerializer& serializer) {
  serializer(type, "type");
  serializer(address, "address");
  serializer(amount, "amount");
}

void TransactionRpcInfo::serialize(TycheCash::ISerializer& serializer) {
  serializer(state, "state");
  serializer(transactionHash, "transactionHash");
  serializer(blockIndex, "blockIndex");
  serializer(timestamp, "timestamp");
  serializer(isBase, "isBase");
  serializer(unlockTime, "unlockTime");
  serializer(amount, "amount");
  serializer(fee, "fee");
  serializer(transfers, "transfers");
  serializer(extra, "extra");
  serializer(paymentId, "paymentId");
}

void GetTransaction::Request::serialize(TycheCash::ISerializer& serializer) {
  if (!serializer(transactionHash, "transactionHash")) {
    throw RequestSerializationError();
  }
}

void GetTransaction::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(transaction, "transaction");
}

void TransactionsInBlockRpcInfo::serialize(TycheCash::ISerializer& serializer) {
  serializer(blockHash, "blockHash");
  serializer(transactions, "transactions");
}

void GetTransactions::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(addresses, "addresses");

  if (serializer(blockHash, "blockHash") == serializer(firstBlockIndex, "firstBlockIndex")) {
    throw RequestSerializationError();
  }

  if (!serializer(blockCount, "blockCount")) {
    throw RequestSerializationError();
  }

  serializer(paymentId, "paymentId");
}

void GetTransactions::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(items, "items");
}

void GetUnconfirmedTransactionHashes::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(addresses, "addresses");
}

void GetUnconfirmedTransactionHashes::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(transactionHashes, "transactionHashes");
}

void WalletRpcOrder::serialize(TycheCash::ISerializer& serializer) {
  bool r = serializer(address, "address");
  r &= serializer(amount, "amount");

  if (!r) {
    throw RequestSerializationError();
  }
}

void SendTransaction::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(sourceAddresses, "addresses");

  if (!serializer(transfers, "transfers")) {
    throw RequestSerializationError();
  }

  serializer(changeAddress, "changeAddress");

  if (!serializer(fee, "fee")) {
    throw RequestSerializationError();
  }

  if (!serializer(anonymity, "anonymity")) {
    throw RequestSerializationError();
  }

  bool hasExtra = serializer(extra, "extra");
  bool hasPaymentId = serializer(paymentId, "paymentId");

  if (hasExtra && hasPaymentId) {
    throw RequestSerializationError();
  }

  serializer(unlockTime, "unlockTime");
}

void SendTransaction::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(transactionHash, "transactionHash");
}

void CreateDelayedTransaction::Request::serialize(TycheCash::ISerializer& serializer) {
  serializer(addresses, "addresses");

  if (!serializer(transfers, "transfers")) {
    throw RequestSerializationError();
  }

  serializer(changeAddress, "changeAddress");

  if (!serializer(fee, "fee")) {
    throw RequestSerializationError();
  }

  if (!serializer(anonymity, "anonymity")) {
    throw RequestSerializationError();
  }

  bool hasExtra = serializer(extra, "extra");
  bool hasPaymentId = serializer(paymentId, "paymentId");

  if (hasExtra && hasPaymentId) {
    throw RequestSerializationError();
  }

  serializer(unlockTime, "unlockTime");
}

void CreateDelayedTransaction::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(transactionHash, "transactionHash");
}

void GetDelayedTransactionHashes::Request::serialize(TycheCash::ISerializer& serializer) {
}

void GetDelayedTransactionHashes::Response::serialize(TycheCash::ISerializer& serializer) {
  serializer(transactionHashes, "transactionHashes");
}

void DeleteDelayedTransaction::Request::serialize(TycheCash::ISerializer& serializer) {
  if (!serializer(transactionHash, "transactionHash")) {
    throw RequestSerializationError();
  }
}

void DeleteDelayedTransaction::Response::serialize(TycheCash::ISerializer& serializer) {
}

void SendDelayedTransaction::Request::serialize(TycheCash::ISerializer& serializer) {
  if (!serializer(transactionHash, "transactionHash")) {
    throw RequestSerializationError();
  }
}

void SendDelayedTransaction::Response::serialize(TycheCash::ISerializer& serializer) {
}

}
