#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace jjfp::common {
class Print {
 public:
  static void print_header(const std::string& header);
  static void print_message(const std::string& message);
  static void print_separator();

  template <typename T>
  static void print_values(const std::vector<T>& values) {
    for (const auto& value : values) {
      std::cout << value << " ";
    }

    std::cout << std::endl;
  }
};
}  // namespace jjfp::common