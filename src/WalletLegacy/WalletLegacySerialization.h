// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <stdexcept>
#include <algorithm>
#include <string>

#include "IWalletLegacy.h"

namespace TycheCash {
class ISerializer;

struct UnconfirmedTransferDetails;
struct WalletLegacyTransaction;
struct WalletLegacyTransfer;

void serialize(UnconfirmedTransferDetails& utd, ISerializer& serializer);
void serialize(WalletLegacyTransaction& txi, ISerializer& serializer);
void serialize(WalletLegacyTransfer& tr, ISerializer& serializer);

}
