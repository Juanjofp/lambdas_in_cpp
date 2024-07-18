#include "print.h"

#include <iostream>

void jjfp::common::Print::print_header(const std::string& header) {
  std::cout << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << header << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << std::endl;
}

void jjfp::common::Print::print_message(const std::string& message) {
  std::cout << message << std::endl;
}

void jjfp::common::Print::print_separator() {
  std::cout << "------------------------------" << std::endl;
}