// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include "IOutputStream.h"

namespace Common {

class StringOutputStream : public IOutputStream {
public:
  StringOutputStream(std::string& out);
  size_t writeSome(const void* data, size_t size) override;

private:
  std::string& out;
};

}
