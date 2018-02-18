// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "Serialization/JsonInputStreamSerializer.h"

#include <ctype.h>
#include <exception>

namespace TycheCash {

namespace {

Common::JsonValue getJsonValueFromStreamHelper(std::istream& stream) {
  Common::JsonValue value;
  stream >> value;
  return value;
}

}

JsonInputStreamSerializer::JsonInputStreamSerializer(std::istream& stream) : JsonInputValueSerializer(getJsonValueFromStreamHelper(stream)) {
}

JsonInputStreamSerializer::~JsonInputStreamSerializer() {
}

} //namespace TycheCash
