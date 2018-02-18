// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <list>
#include <ostream>
#include <unordered_set>

#include <boost/uuid/uuid.hpp>
#include "Common/StringTools.h"
#include "crypto/hash.h"

namespace TycheCash {

struct TycheCashConnectionContext {
  uint8_t version;
  boost::uuids::uuid m_connection_id;
  uint32_t m_remote_ip = 0;
  uint32_t m_remote_port = 0;
  bool m_is_income = false;
  time_t m_started = 0;

  enum state {
    state_befor_handshake = 0, //default state
    state_synchronizing,
    state_idle,
    state_normal,
    state_sync_required,
    state_pool_sync_required,
    state_shutdown
  };

  state m_state = state_befor_handshake;
  std::list<Crypto::Hash> m_needed_objects;
  std::unordered_set<Crypto::Hash> m_requested_objects;
  uint32_t m_remote_blockchain_height = 0;
  uint32_t m_last_response_height = 0;
};

inline std::string get_protocol_state_string(TycheCashConnectionContext::state s) {
  switch (s)  {
  case TycheCashConnectionContext::state_befor_handshake:
    return "state_befor_handshake";
  case TycheCashConnectionContext::state_synchronizing:
    return "state_synchronizing";
  case TycheCashConnectionContext::state_idle:
    return "state_idle";
  case TycheCashConnectionContext::state_normal:
    return "state_normal";
  case TycheCashConnectionContext::state_sync_required:
    return "state_sync_required";
  case TycheCashConnectionContext::state_pool_sync_required:
    return "state_pool_sync_required";
  case TycheCashConnectionContext::state_shutdown:
    return "state_shutdown";
  default:
    return "unknown";
  }
}

}

namespace std {
inline std::ostream& operator << (std::ostream& s, const TycheCash::TycheCashConnectionContext& context) {
  return s << "[" << Common::ipAddressToString(context.m_remote_ip) << ":" << 
    context.m_remote_port << (context.m_is_income ? " INC" : " OUT") << "] ";
}
}
