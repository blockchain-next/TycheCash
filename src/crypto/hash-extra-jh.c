// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "jh.h"
#include "hash-ops.h"

void hash_extra_jh(const void *data, size_t length, char *hash) {
  int r = jh_hash(HASH_SIZE * 8, data, 8 * length, (uint8_t*)hash);
  assert(SUCCESS == r);
}
