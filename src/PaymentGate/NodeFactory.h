// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "INode.h"

#include <string>

namespace PaymentService {

class NodeFactory {
public:
  static TycheCash::INode* createNode(const std::string& daemonAddress, uint16_t daemonPort);
  static TycheCash::INode* createNodeStub();
private:
  NodeFactory();
  ~NodeFactory();

  TycheCash::INode* getNode(const std::string& daemonAddress, uint16_t daemonPort);

  static NodeFactory factory;
};

} //namespace PaymentService
