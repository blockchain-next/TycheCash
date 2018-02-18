// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <memory>

#include <TycheCash.h>

namespace TycheCash {

struct P2pMessage {
  uint32_t type;
  BinaryArray data;
};

class IP2pConnection {
public:
  virtual ~IP2pConnection();
  virtual void read(P2pMessage &message) = 0;
  virtual void write(const P2pMessage &message) = 0;
  virtual void ban() = 0;
  virtual void stop() = 0;
};

class IP2pNode {
public:
  virtual std::unique_ptr<IP2pConnection> receiveConnection() = 0;
  virtual void stop() = 0;
};

}
