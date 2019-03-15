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
const uint64_t TycheCash_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 *2;
const uint64_t TycheCash_BLOCK_FUTURE_TIME_LIMIT_V1	    = 60 *60 * 2;

const size_t   TycheCash_HARDFORK_HEIGHT_V2                 = 12998;
const size_t   TycheCash_HARDFORK_HEIGHT_V3		    = 61010;
const size_t   TycheCash_HARDFORK_HEIGHT_V4		    = 75900;
const size_t   TycheCash_HARDFORK_HEIGHT_V5		    = 83453;
const size_t   TycheCash_HARDFORK_HEIGHT_V6                 = 100000;//Planned

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW            = 30;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V6         = 11;

const uint64_t MONEY_SUPPLY                                 = UINT64_C(8000000000000000000);
const unsigned EMISSION_SPEED_FACTOR                        = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   TycheCash_REWARD_BLOCKS_WINDOW               = 100;
const size_t   TycheCash_BLOCK_GRANTED_FULL_REWARD_ZONE     = 300000; //size of block (bytes) after which reward for block calculated using block size
const size_t   TycheCash_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   TycheCash_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                   = TycheCash_BLOCK_GRANTED_FULL_REWARD_ZONE / 14 - TycheCash_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t MINIMUM_FEE                                  = UINT64_C(1000000);
const uint64_t DEFAULT_DUST_THRESHOLD                       = UINT64_C(1000000);

const uint64_t DIFFICULTY_TARGET = 120; // seconds
const uint64_t TycheCah_BLOCK_FUTURE_TIME_LIMIT_V2 = 7 * DIFFICULTY_TARGET;
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
const size_t   DIFFICULTY_WINDOW_V1 = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
const size_t   DIFFICULTY_WINDOW_V2 = 70;
const size_t   DIFFICULTY_WINDOW_V3 = 70;
const size_t   DIFFICULTY_WINDOW_V4 = 60;// not used 
const size_t   DIFFICULTY_WINDOW_V5 = 60;

const size_t   DIFFICULTY_CUT = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

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

const uint8_t  TRANSACTION_VERSION_1						= 1;
const uint8_t  TRANSACTION_VERSION_2						= 2;
const uint8_t  CURRENT_TRANSACTION_VERSION					= TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1						= 1;
const uint8_t  BLOCK_MAJOR_VERSION_2						= 2;
const uint8_t  BLOCK_MAJOR_VERSION_3						= 3;
const uint8_t  BLOCK_MINOR_VERSION_0						= 0;
const uint8_t  BLOCK_MINOR_VERSION_1						= 1;


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
  "node1.tychecash.net:17017",
  "node2.tychecash.net:17017",
  "node3.tychecash.net:17017",
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
  { 25000, "be8f6197fcec9a2f61961582e944daf02d5c8dc284826754b382573ccb51f63d" },
  { 30000, "841d815eefa01d463ed2a026543cc4b4a6ac6650efcbf4d22e1fb3d9bee57b54" },
  { 35000, "66cb0e1660c486a17a7d80971e312a9ce28b59a9629cb3048d809deed81a3bad" },
  { 40000, "0ff15f0d2e33fe37c15ebdf8fdeadc65b76ccf9fb48b8e4b6337901afcf049c6" },
  { 45000, "613703a52949ecc33814d8f2cc854d27f853987ca68546bb445ce98cdd720f7c" },
  { 50000, "22ad335fdfe8aed6d7c6755f49a9f453cf694eb3817d41b13cc9790d6687b856" },
  { 55000, "63dd33763a6a3a674923831320b27d1eab6b1cf27ec824a41a4b107822f8fcc5" },
  { 60000, "e2b71ee7f992434081d2ed8d2d6b03f0ea887cd2b58421035e2aff9a5715f73d" },
  { 61388, "f3289e186dfbc41f9349074311f9b309478fc47668fc6bd1e24a2275f1fa28d7" },
  { 65000, "0dbff646445601e51eff2a42a6196a3cdc0b0623056b3eb8d66134fea2ac35a7" },
  { 70000, "df183aeccfc35621014e16f5714266cbdcaef0e9ec046d18046c3c18f27268ee" },
  { 74945, "4b569259621685a069daa07d4a9782590df2708363be117ebc25655d2315a6b5" },
  { 75000, "7f6b124b673c7d14a9698c238f3cf0504e230ab6301ce43fef3b83055bcacf93" },
  { 80000, "67faaa1bf4ffd8e48076deaa8e922aade138adda4f42551942fcc991c0c43ea1" },
  { 85000, "9f8d8af68d29aad340323e94dd44b6549899188c95858f6ef27805036f3b781d" },
  { 90000, "fd9ee78cb5e884c80385559268a3293b80d45062ad78d0bd48596d6044ea7f02" },
  { 100000, "3bf386985ed7140fed13152da1edb01635a4c2e565e8f534864d19c0672a089d" },
  { 110000, "413d8d2409b761c181bb70549f4b8587d5730eed86fdaa5e861c6589bc0b0e9e" },
  { 120000, "fc1818c7c96b5c8293d2748b9cebfa27f40a7500839544de8e6c9ea278ec7622" },
  { 130000, "23e6c661867c16e51c7e96f5909e7e32a7436ada622f6d21ed2e376495eee51b" },
  { 131869, "50d40cfdd4ca9f5c63bea2b99c39bbf72a6b36d1c1b4e3e373f5cc5a0433a249" },
  { 140000, "a8180f9f314a4f5d7ddb4ecf320d8c2e94c7003d736c2dc8081c0df249d9aa7a" },
  { 148639, "d2af0d9b041b8d96913c00c22fa3b777a0633864779b190e6bc33f9313dc156a" },
  { 150000, "b239d2b4eece4c18e53ddb4338a321f59bf869b02686fdd842a01b3f0fc0ef59" },
  { 160000, "b0d7d16825d552f0c164e3a58bde51846841c138ee5fed3a8f9e90db94abe843" },
  { 170000, "5ad36e81630ede3e8b1bbafaca771d131e8df9a50ce2d93abe0e150944249e6b" },
  { 180000, "c45d142155fdecee0e7414df52fb170e680f1958c5c04f8a4ace2df9d3b2322e" },
  { 190000, "57853ba960e1850111d14a19720724f1cfb9527900acc8d756ef5102d4c3fc4d" },
  { 199223, "957ee184df574c27306bee9ee10879333f74442981fcd8ac6659071db5611c6a" },
  { 200000, "0c6cd8a16b53b2de7b139b58e96765f373cf0ff7e4d65345bb281481bb2f3b15" },
  { 200100, "8fddc28fb0e3d98ec0ecf7affdc6d526851442d8d75c251ccd5b031131e4551a" },
  { 201000, "c90cc1c9fc08460082fe7717153116cc00e32a177424a5e69b4769338465e2ad" },
  { 202000, "b4a4b85a6fef0eb2bcdb8b74211bbfc7c8f9ae6fa38a3223ebe555467a09a883" },
  { 202105, "cab2ecb36f22a5938c146f953fa1677db47b052509efdcc5c52db2df82ddf051" },
  { 202111, "611033168644ec7eded3b4ffe0ed7d37a224246a5b021ebfa5dfc3c4a429ae0b" },
  { 213683, "3ab0fd4e9ace15ccefdd38235560863d97232aa4a5c0bfe4b90ac530ac9a00a5" },
  { 217886, "fcf4e41d80b5cdc1ece079d7ac80586d4baf5dd45820b354b22b0ed979f0bcca" },
};

} // TycheCash

#define ALLOW_DEBUG_COMMANDS
