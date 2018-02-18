// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "Common/ObserverManager.h"

namespace TycheCash {

template <typename Observer, typename Base>
class IObservableImpl : public Base {
public:

  virtual void addObserver(Observer* observer) override {
    m_observerManager.add(observer);
  }

  virtual void removeObserver(Observer* observer) override {
    m_observerManager.remove(observer);
  }

protected:
  Tools::ObserverManager<Observer> m_observerManager;
};

}
