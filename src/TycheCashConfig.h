// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace TycheCash {
namespace parameters {

const uint64_t TycheCash_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   TycheCash_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   TycheCash_MAX_TX_SIZE                        = 1000000000;
const uint64_t TycheCash_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x31;
const size_t   TycheCash_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t TycheCash_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const size_t   TycheCash_HARDFORK_HEIGHT_V2                 = 12998;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW            = 30;

const uint64_t MONEY_SUPPLY                                 = UINT64_C(8000000000000000000);
const unsigned EMISSION_SPEED_FACTOR                        = 18;

const size_t   TycheCash_REWARD_BLOCKS_WINDOW               = 100;
const size_t   TycheCash_BLOCK_GRANTED_FULL_REWARD_ZONE     = 300000; //size of block (bytes) after which reward for block calculated using block size
const size_t   TycheCash_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   TycheCash_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                   = TycheCash_BLOCK_GRANTED_FULL_REWARD_ZONE / 14 - TycheCash_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t MINIMUM_FEE                                  = UINT64_C(1000000);
const uint64_t DEFAULT_DUST_THRESHOLD                       = UINT64_C(1000000);

const uint64_t DIFFICULTY_TARGET                            = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY            = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                            = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                               = 60; // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                               = 15;

const size_t   MAX_BLOCK_SIZE_INITIAL                       = 20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR        = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR      = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t TycheCash_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t TycheCash_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * TycheCash_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t TycheCash_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24; // seconds, one day
const uint64_t TycheCash_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = TycheCash_MEMPOOL_TX_LIVETIME * 7; // seconds, one week
const uint64_t TycheCash_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // TycheCash_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * TycheCash_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                           = MAX_TRANSACTION_SIZE_LIMIT / 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT                    = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO             = 4;

const char     TycheCash_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     TycheCash_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     TycheCash_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     TycheCash_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                      = "p2pstate.bin";
const char     TycheCash_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                     = "miner_conf.json";
} // parameters

const char     TycheCash_NAME[]                             = "TycheCash";
const char     GENESIS_COINBASE_TX_HEX[]                    = "013c01ff0001c89d9deb96f806029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210143b430e9f6a846103d44de35897dbdf37e320bac29dcf620a3aee0cc6975590d";

const uint8_t  CURRENT_TRANSACTION_VERSION                  = 1;
const uint8_t  BLOCK_MAJOR_VERSION_1                        = 1;
const uint8_t  BLOCK_MINOR_VERSION_0                        = 0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT       = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT           = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT        = 1000;

const int      P2P_DEFAULT_PORT                             = 17017;
const int      RPC_DEFAULT_PORT                             = 26026;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT               = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE         = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT    = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL               = 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                  = 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE               = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT               = 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT          = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                   = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT         = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                   = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

const std::initializer_list<const char*> SEED_NODES = {
  "159.65.196.250:17017",
  "46.101.227.89:17017",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS = {
  { 1, "4066eb2e79be15884c2e68f398e2d5ae68d816914c31cde27d2e380270b3d24d" },
  { 1000, "6cab84eea40d70da8cc9388f34b447f62eb571997e7ba3ecb074ab54883f5fd3" },
  { 2000, "d9a3eb78237494a15fd6c0749d52a3931e484d934e8707709322bdf73fda6005" },
  { 4000, "402857b98b6c13b0aa3368db7bb728b3e41228a400bd4a695a6494d2f9db7ece" },
  { 8000, "a6ad53c7f7edc68147a8cddf3325152b0b2eb93fec1ef6d0dc7525258c604da2" },
  { 12297, "3898d249c97cebac322582a6b3f3ccc5943d6859ad26304e75397d8f0c5921c6" },
  { 15000, "e8a7c64302d8d5ea3d66e17ea36a4a18f7c1334b7d497b328a3db2fca4f753c6" },
  { 20000, "731a4512037b155b8fa1083c9f2b91c7df25b1bb51ec6142fae900954055c6e8" },
};

} // TycheCash

#define ALLOW_DEBUG_COMMANDS
