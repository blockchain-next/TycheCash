// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ITycheCashProtocolQueryStub.h"

bool ITycheCashProtocolQueryStub::addObserver(TycheCash::ITycheCashProtocolObserver* observer) {
  return false;
}

bool ITycheCashProtocolQueryStub::removeObserver(TycheCash::ITycheCashProtocolObserver* observer) {
  return false;
}

uint32_t ITycheCashProtocolQueryStub::getObservedHeight() const {
  return observedHeight;
}

size_t ITycheCashProtocolQueryStub::getPeerCount() const {
  return peers;
}

bool ITycheCashProtocolQueryStub::isSynchronized() const {
  return synchronized;
}

void ITycheCashProtocolQueryStub::setPeerCount(uint32_t count) {
  peers = count;
}

void ITycheCashProtocolQueryStub::setObservedHeight(uint32_t height) {
  observedHeight = height;
}

void ITycheCashProtocolQueryStub::setSynchronizedStatus(bool status) {
    synchronized = status;
}
