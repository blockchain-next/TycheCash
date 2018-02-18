// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <atomic>

#include <Common/ObserverManager.h>

#include "TycheCashCore/ICore.h"

#include "TycheCashProtocol/TycheCashProtocolDefinitions.h"
#include "TycheCashProtocol/TycheCashProtocolHandlerCommon.h"
#include "TycheCashProtocol/ITycheCashProtocolObserver.h"
#include "TycheCashProtocol/ITycheCashProtocolQuery.h"

#include "P2p/P2pProtocolDefinitions.h"
#include "P2p/NetNodeCommon.h"
#include "P2p/ConnectionContext.h"

#include <Logging/LoggerRef.h>

namespace System {
  class Dispatcher;
}

namespace TycheCash
{
  class Currency;

  class TycheCashProtocolHandler : 
    public i_TycheCash_protocol, 
    public ITycheCashProtocolQuery
  {
  public:

    TycheCashProtocolHandler(const Currency& currency, System::Dispatcher& dispatcher, ICore& rcore, IP2pEndpoint* p_net_layout, Logging::ILogger& log);

    virtual bool addObserver(ITycheCashProtocolObserver* observer) override;
    virtual bool removeObserver(ITycheCashProtocolObserver* observer) override;

    void set_p2p_endpoint(IP2pEndpoint* p2p);
    // ICore& get_core() { return m_core; }
    virtual bool isSynchronized() const override { return m_synchronized; }
    void log_connections();

    // Interface t_payload_net_handler, where t_payload_net_handler is template argument of nodetool::node_server
    void stop();
    bool start_sync(TycheCashConnectionContext& context);
    bool on_idle();
    void onConnectionOpened(TycheCashConnectionContext& context);
    void onConnectionClosed(TycheCashConnectionContext& context);
    bool get_stat_info(core_stat_info& stat_inf);
    bool get_payload_sync_data(CORE_SYNC_DATA& hshd);
    bool process_payload_sync_data(const CORE_SYNC_DATA& hshd, TycheCashConnectionContext& context, bool is_inital);
    int handleCommand(bool is_notify, int command, const BinaryArray& in_buff, BinaryArray& buff_out, TycheCashConnectionContext& context, bool& handled);
    virtual size_t getPeerCount() const override;
    virtual uint32_t getObservedHeight() const override;
    void requestMissingPoolTransactions(const TycheCashConnectionContext& context);

  private:
    //----------------- commands handlers ----------------------------------------------
    int handle_notify_new_block(int command, NOTIFY_NEW_BLOCK::request& arg, TycheCashConnectionContext& context);
    int handle_notify_new_transactions(int command, NOTIFY_NEW_TRANSACTIONS::request& arg, TycheCashConnectionContext& context);
    int handle_request_get_objects(int command, NOTIFY_REQUEST_GET_OBJECTS::request& arg, TycheCashConnectionContext& context);
    int handle_response_get_objects(int command, NOTIFY_RESPONSE_GET_OBJECTS::request& arg, TycheCashConnectionContext& context);
    int handle_request_chain(int command, NOTIFY_REQUEST_CHAIN::request& arg, TycheCashConnectionContext& context);
    int handle_response_chain_entry(int command, NOTIFY_RESPONSE_CHAIN_ENTRY::request& arg, TycheCashConnectionContext& context);
    int handleRequestTxPool(int command, NOTIFY_REQUEST_TX_POOL::request& arg, TycheCashConnectionContext& context);

    //----------------- i_TycheCash_protocol ----------------------------------
    virtual void relay_block(NOTIFY_NEW_BLOCK::request& arg) override;
    virtual void relay_transactions(NOTIFY_NEW_TRANSACTIONS::request& arg) override;

    //----------------------------------------------------------------------------------
    uint32_t get_current_blockchain_height();
    bool request_missing_objects(TycheCashConnectionContext& context, bool check_having_blocks);
    bool on_connection_synchronized();
    void updateObservedHeight(uint32_t peerHeight, const TycheCashConnectionContext& context);
    void recalculateMaxObservedHeight(const TycheCashConnectionContext& context);
    int processObjects(TycheCashConnectionContext& context, const std::vector<block_complete_entry>& blocks);
    Logging::LoggerRef logger;

  private:

    System::Dispatcher& m_dispatcher;
    ICore& m_core;
    const Currency& m_currency;

    p2p_endpoint_stub m_p2p_stub;
    IP2pEndpoint* m_p2p;
    std::atomic<bool> m_synchronized;
    std::atomic<bool> m_stop;

    mutable std::mutex m_observedHeightMutex;
    uint32_t m_observedHeight;

    std::atomic<size_t> m_peersCount;
    Tools::ObserverManager<ITycheCashProtocolObserver> m_observerManager;
  };
}
