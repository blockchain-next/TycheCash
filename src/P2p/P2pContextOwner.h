// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <list>
#include <memory>

namespace TycheCash {

class P2pContext;

class P2pContextOwner {
public:

  typedef std::list<std::unique_ptr<P2pContext>> ContextList;

  P2pContextOwner(P2pContext* ctx, ContextList& contextList);
  P2pContextOwner(P2pContextOwner&& other);
  P2pContextOwner(const P2pContextOwner& other) = delete;
  ~P2pContextOwner();

  P2pContext& get();
  P2pContext* operator -> ();

private:

  ContextList& contextList;
  ContextList::iterator contextIterator;
};

}
