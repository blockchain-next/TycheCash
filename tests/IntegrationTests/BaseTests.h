// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <gtest/gtest.h>
#include <future>

#include <Logging/ConsoleLogger.h>
#include <System/Dispatcher.h>
#include "TycheCashCore/Currency.h"

#include "../IntegrationTestLib/TestNetwork.h"

namespace Tests {

class BaseTest : public testing::Test {
public:

  BaseTest() :
    currency(TycheCash::CurrencyBuilder(logger).testnet(true).currency()),
    network(dispatcher, currency) {
  }

protected:

  virtual void TearDown() override {
    network.shutdown();
  }

  System::Dispatcher& getDispatcher() {
    return dispatcher;
  }

  System::Dispatcher dispatcher;
  Logging::ConsoleLogger logger;
  TycheCash::Currency currency;
  TestNetwork network;
};

}
