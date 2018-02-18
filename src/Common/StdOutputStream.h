// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <ostream>
#include "IOutputStream.h"

namespace Common {

class StdOutputStream : public IOutputStream {
public:
  StdOutputStream(std::ostream& out);
  StdOutputStream& operator=(const StdOutputStream&) = delete;
  size_t writeSome(const void* data, size_t size) override;

private:
  std::ostream& out;
};

}
