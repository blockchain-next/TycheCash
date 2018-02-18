// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "TycheCashCore/Account.h"
#include "TycheCashBoostSerialization.h"

//namespace TycheCash {
namespace boost
{
  namespace serialization
  {
    template <class Archive>
    inline void serialize(Archive &a, TycheCash::AccountKeys &x, const boost::serialization::version_type ver)
    {
      a & x.address;
      a & x.spendSecretKey;
      a & x.viewSecretKey;
    }

    template <class Archive>
    inline void serialize(Archive &a, TycheCash::AccountPublicAddress &x, const boost::serialization::version_type ver)
    {
      a & x.spendPublicKey;
      a & x.viewPublicKey;
    }

  }
}
