// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "FileLogger.h"

namespace Logging {

FileLogger::FileLogger(Level level) : StreamLogger(level) {
}

void FileLogger::init(const std::string& fileName) {
  fileStream.open(fileName, std::ios::app);
  StreamLogger::attachToStream(fileStream);
}

}
