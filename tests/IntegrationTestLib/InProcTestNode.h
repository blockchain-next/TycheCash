// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TestNode.h"
#include "NetworkConfiguration.h"

#include <future>
#include <memory>
#include <thread>

#include <System/Dispatcher.h>


namespace TycheCash {
class core;
class TycheCashProtocolHandler;
class NodeServer;
class Currency;
}

namespace Tests {

class InProcTestNode : public TestNode {
public:
  InProcTestNode(const TestNodeConfiguration& cfg, const TycheCash::Currency& currency);
  ~InProcTestNode();

  virtual bool startMining(size_t threadsCount, const std::string &address) override;
  virtual bool stopMining() override;
  virtual bool stopDaemon() override;
  virtual bool getBlockTemplate(const std::string &minerAddress, TycheCash::Block &blockTemplate, uint64_t &difficulty) override;
  virtual bool submitBlock(const std::string& block) override;
  virtual bool getTailBlockId(Crypto::Hash &tailBlockId) override;
  virtual bool makeINode(std::unique_ptr<TycheCash::INode>& node) override;
  virtual uint64_t getLocalHeight() override;

private:

  void workerThread(std::promise<std::string>& initPromise);

  std::unique_ptr<TycheCash::core> core;
  std::unique_ptr<TycheCash::TycheCashProtocolHandler> protocol;
  std::unique_ptr<TycheCash::NodeServer> p2pNode;

  std::thread m_thread;
  const TycheCash::Currency& m_currency;
  TestNodeConfiguration m_cfg;
};

}
