// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include <system_error>

namespace TycheCash {
namespace error {

enum class WalletServiceErrorCode {
  WRONG_KEY_FORMAT = 1,
  WRONG_PAYMENT_ID_FORMAT,
  WRONG_HASH_FORMAT,
  OBJECT_NOT_FOUND
};

// custom category:
class WalletServiceErrorCategory : public std::error_category {
public:
  static WalletServiceErrorCategory INSTANCE;

  virtual const char* name() const throw() override {
    return "WalletServiceErrorCategory";
  }

  virtual std::error_condition default_error_condition(int ev) const throw() override {
    return std::error_condition(ev, *this);
  }

  virtual std::string message(int ev) const override {
    WalletServiceErrorCode code = static_cast<WalletServiceErrorCode>(ev);

    switch (code) {
      case WalletServiceErrorCode::WRONG_KEY_FORMAT: return "Wrong key format";
      case WalletServiceErrorCode::WRONG_PAYMENT_ID_FORMAT: return "Wrong payment id format";
      case WalletServiceErrorCode::WRONG_HASH_FORMAT: return "Wrong block id format";
      case WalletServiceErrorCode::OBJECT_NOT_FOUND: return "Requested object not found";
      default: return "Unknown error";
    }
  }

private:
  WalletServiceErrorCategory() {
  }
};

} //namespace error
} //namespace TycheCash

inline std::error_code make_error_code(TycheCash::error::WalletServiceErrorCode e) {
  return std::error_code(static_cast<int>(e), TycheCash::error::WalletServiceErrorCategory::INSTANCE);
}

namespace std {

template <>
struct is_error_code_enum<TycheCash::error::WalletServiceErrorCode>: public true_type {};

}
