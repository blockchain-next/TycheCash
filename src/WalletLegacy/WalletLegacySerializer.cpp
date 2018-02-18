// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "WalletLegacySerializer.h"

#include <stdexcept>

#include "Common/MemoryInputStream.h"
#include "Common/StdInputStream.h"
#include "Common/StdOutputStream.h"
#include "Serialization/BinaryOutputStreamSerializer.h"
#include "Serialization/BinaryInputStreamSerializer.h"
#include "TycheCashCore/Account.h"
#include "TycheCashCore/TycheCashSerialization.h"
#include "WalletLegacy/WalletUserTransactionsCache.h"
#include "Wallet/WalletErrors.h"
#include "WalletLegacy/KeysStorage.h"

using namespace Common;

namespace {

bool verifyKeys(const Crypto::SecretKey& sec, const Crypto::PublicKey& expected_pub) {
  Crypto::PublicKey pub;
  bool r = Crypto::secret_key_to_public_key(sec, pub);
  return r && expected_pub == pub;
}

void throwIfKeysMissmatch(const Crypto::SecretKey& sec, const Crypto::PublicKey& expected_pub) {
  if (!verifyKeys(sec, expected_pub))
    throw std::system_error(make_error_code(TycheCash::error::WRONG_PASSWORD));
}

}

namespace TycheCash {

WalletLegacySerializer::WalletLegacySerializer(TycheCash::AccountBase& account, WalletUserTransactionsCache& transactionsCache) :
  account(account),
  transactionsCache(transactionsCache),
  walletSerializationVersion(1)
{
}

void WalletLegacySerializer::serialize(std::ostream& stream, const std::string& password, bool saveDetailed, const std::string& cache) {
  std::stringstream plainArchive;
  StdOutputStream plainStream(plainArchive);
  TycheCash::BinaryOutputStreamSerializer serializer(plainStream);
  saveKeys(serializer);

  serializer(saveDetailed, "has_details");

  if (saveDetailed) {
    serializer(transactionsCache, "details");
  }

  serializer.binary(const_cast<std::string&>(cache), "cache");

  std::string plain = plainArchive.str();
  std::string cipher;

  Crypto::chacha8_iv iv = encrypt(plain, password, cipher);

  uint32_t version = walletSerializationVersion;
  StdOutputStream output(stream);
  TycheCash::BinaryOutputStreamSerializer s(output);
  s.beginObject("wallet");
  s(version, "version");
  s(iv, "iv");
  s(cipher, "data");
  s.endObject();

  stream.flush();
}

void WalletLegacySerializer::saveKeys(TycheCash::ISerializer& serializer) {
  TycheCash::KeysStorage keys;
  TycheCash::AccountKeys acc = account.getAccountKeys();

  keys.creationTimestamp = account.get_createtime();
  keys.spendPublicKey = acc.address.spendPublicKey;
  keys.spendSecretKey = acc.spendSecretKey;
  keys.viewPublicKey = acc.address.viewPublicKey;
  keys.viewSecretKey = acc.viewSecretKey;

  keys.serialize(serializer, "keys");
}

Crypto::chacha8_iv WalletLegacySerializer::encrypt(const std::string& plain, const std::string& password, std::string& cipher) {
  Crypto::chacha8_key key;
  Crypto::cn_context context;
  Crypto::generate_chacha8_key(context, password, key);

  cipher.resize(plain.size());

  Crypto::chacha8_iv iv = Crypto::rand<Crypto::chacha8_iv>();
  Crypto::chacha8(plain.data(), plain.size(), key, iv, &cipher[0]);

  return iv;
}


void WalletLegacySerializer::deserialize(std::istream& stream, const std::string& password, std::string& cache) {
  StdInputStream stdStream(stream);
  TycheCash::BinaryInputStreamSerializer serializerEncrypted(stdStream);

  serializerEncrypted.beginObject("wallet");

  uint32_t version;
  serializerEncrypted(version, "version");

  Crypto::chacha8_iv iv;
  serializerEncrypted(iv, "iv");

  std::string cipher;
  serializerEncrypted(cipher, "data");

  serializerEncrypted.endObject();

  std::string plain;
  decrypt(cipher, plain, iv, password);

  MemoryInputStream decryptedStream(plain.data(), plain.size()); 
  TycheCash::BinaryInputStreamSerializer serializer(decryptedStream);

  loadKeys(serializer);
  throwIfKeysMissmatch(account.getAccountKeys().viewSecretKey, account.getAccountKeys().address.viewPublicKey);

  if (account.getAccountKeys().spendSecretKey != NULL_SECRET_KEY) {
    throwIfKeysMissmatch(account.getAccountKeys().spendSecretKey, account.getAccountKeys().address.spendPublicKey);
  } else {
    if (!Crypto::check_key(account.getAccountKeys().address.spendPublicKey)) {
      throw std::system_error(make_error_code(TycheCash::error::WRONG_PASSWORD));
    }
  }

  bool detailsSaved;

  serializer(detailsSaved, "has_details");

  if (detailsSaved) {
    serializer(transactionsCache, "details");
  }

  serializer.binary(cache, "cache");
}

void WalletLegacySerializer::decrypt(const std::string& cipher, std::string& plain, Crypto::chacha8_iv iv, const std::string& password) {
  Crypto::chacha8_key key;
  Crypto::cn_context context;
  Crypto::generate_chacha8_key(context, password, key);

  plain.resize(cipher.size());

  Crypto::chacha8(cipher.data(), cipher.size(), key, iv, &plain[0]);
}

void WalletLegacySerializer::loadKeys(TycheCash::ISerializer& serializer) {
  TycheCash::KeysStorage keys;

  keys.serialize(serializer, "keys");

  TycheCash::AccountKeys acc;
  acc.address.spendPublicKey = keys.spendPublicKey;
  acc.spendSecretKey = keys.spendSecretKey;
  acc.address.viewPublicKey = keys.viewPublicKey;
  acc.viewSecretKey = keys.viewSecretKey;

  account.setAccountKeys(acc);
  account.set_createtime(keys.creationTimestamp);
}

}
