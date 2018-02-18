// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "IInputStream.h"

namespace Common {

  class MemoryInputStream : public IInputStream {
  public:
    MemoryInputStream(const void* buffer, size_t bufferSize);
    size_t getPosition() const;
    bool endOfStream() const;
    
    // IInputStream
    virtual size_t readSome(void* data, size_t size) override;

  private:
    const char* buffer;
    size_t bufferSize;
    size_t position;
  };
}
