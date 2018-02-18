// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCash.h"
#include "P2pProtocolTypes.h"

namespace TycheCash {

  struct TycheCashConnectionContext;

  struct IP2pEndpoint {
    virtual void relay_notify_to_all(int command, const BinaryArray& data_buff, const net_connection_id* excludeConnection) = 0;
    virtual bool invoke_notify_to_peer(int command, const BinaryArray& req_buff, const TycheCash::TycheCashConnectionContext& context) = 0;
    virtual uint64_t get_connections_count()=0;
    virtual void for_each_connection(std::function<void(TycheCash::TycheCashConnectionContext&, PeerIdType)> f) = 0;
    // can be called from external threads
    virtual void externalRelayNotifyToAll(int command, const BinaryArray& data_buff) = 0;
  };

  struct p2p_endpoint_stub: public IP2pEndpoint {
    virtual void relay_notify_to_all(int command, const BinaryArray& data_buff, const net_connection_id* excludeConnection) override {}
    virtual bool invoke_notify_to_peer(int command, const BinaryArray& req_buff, const TycheCash::TycheCashConnectionContext& context) override { return true; }
    virtual void for_each_connection(std::function<void(TycheCash::TycheCashConnectionContext&, PeerIdType)> f) override {}
    virtual uint64_t get_connections_count() override { return 0; }   
    virtual void externalRelayNotifyToAll(int command, const BinaryArray& data_buff) override {}
  };
}
