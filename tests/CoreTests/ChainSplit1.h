// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once 
#include "Chaingen.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_simple_chain_split_1 : public test_chain_unit_base 
{
public: 
  gen_simple_chain_split_1();
  bool generate(std::vector<test_event_entry> &events) const; 
  bool check_split_not_switched(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_not_switched2(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_not_switched_back(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched_back_1(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched_back_2(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_mempool_1(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_mempool_2(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  /*bool check_orphaned_chain_1(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_switched_to_alternative(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_2(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_switched_to_main(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_38(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_39(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_40(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_41(TycheCash::core& c, size_t ev_index, const std::vector<test_event_entry> &events); */
private:
};
