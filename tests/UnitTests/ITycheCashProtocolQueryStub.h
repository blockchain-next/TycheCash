// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>

#include "TycheCashProtocol/ITycheCashProtocolObserver.h"
#include "TycheCashProtocol/ITycheCashProtocolQuery.h"

class ITycheCashProtocolQueryStub: public TycheCash::ITycheCashProtocolQuery {
public:
  ITycheCashProtocolQueryStub() : peers(0), observedHeight(0), synchronized(false) {}

  virtual bool addObserver(TycheCash::ITycheCashProtocolObserver* observer) override;
  virtual bool removeObserver(TycheCash::ITycheCashProtocolObserver* observer) override;
  virtual uint32_t getObservedHeight() const override;
  virtual size_t getPeerCount() const override;
  virtual bool isSynchronized() const override;

  void setPeerCount(uint32_t count);
  void setObservedHeight(uint32_t height);

  void setSynchronizedStatus(bool status);

private:
  size_t peers;
  uint32_t observedHeight;

  bool synchronized;
};
