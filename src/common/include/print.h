#pragma once

#include <string>

namespace jjfp::common {
class Print {
 public:
  static void print_header(const std::string& header);
  static void print_message(const std::string& message);
  static void print_separator();
};
}  // namespace jjfp::common