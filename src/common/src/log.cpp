#include "log.h"

#include <iostream>

void jjfp::common::Log::info(const char* tag, const char* message) {
  std::cout << "[INFO] " << tag << ": " << message << std::endl;
}

void jjfp::common::Log::error(const char* tag, const char* message) {
  std::cerr << "[ERROR] " << tag << ": " << message << std::endl;
}

void jjfp::common::Log::debug(const char* tag, const char* message) {
  std::cout << "[DEBUG] " << tag << ": " << message << std::endl;
}
