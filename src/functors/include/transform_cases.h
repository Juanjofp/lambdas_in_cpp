#pragma once

#include <string>

namespace jjfp::functors {
class UpperCase {
 public:
  std::string operator()(const std::string& str) const {
    std::string result;

    for (const auto& c : str) {
      result += toupper(c);
    }

    return result;
  }
};

class LowerCase {
 public:
  std::string operator()(const std::string& str) const {
    std::string result;

    for (const auto& c : str) {
      result += tolower(c);
    }

    return result;
  }
};
}  // namespace jjfp::functors