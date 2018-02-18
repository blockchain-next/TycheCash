// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once 

#include "Chaingen.h"

struct GetRandomOutputs : public test_chain_unit_base
{
  GetRandomOutputs();

  // bool check_tx_verification_context(const TycheCash::tx_verification_context& tvc, bool tx_added, size_t event_idx, const TycheCash::Transaction& tx);
  // bool check_block_verification_context(const TycheCash::block_verification_context& bvc, size_t event_idx, const TycheCash::Block& block);
  // bool mark_last_valid_block(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

  bool generate(std::vector<test_event_entry>& events) const;


private:

  bool checkHalfUnlocked(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool checkFullyUnlocked(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

  bool request(TycheCash::core& c, uint64_t amount, size_t mixin, TycheCash::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_response& resp);

};
