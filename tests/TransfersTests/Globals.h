// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "../IntegrationTestLib/BaseFunctionalTests.h"
#include "../IntegrationTestLib/Logger.h"
#include "gtest/gtest.h"

extern System::Dispatcher globalSystem;
extern TycheCash::Currency currency;
extern Tests::Common::BaseFunctionalTestsConfig config;

class TransfersTest :
  public Tests::Common::BaseFunctionalTests,
  public ::testing::Test {

public:
  TransfersTest() : BaseFunctionalTests(currency, globalSystem, config) {
  }
};
