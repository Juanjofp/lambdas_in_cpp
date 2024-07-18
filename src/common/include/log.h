#pragma once

namespace jjfp::common {
class Log {
 public:
  static void info(const char* tag, const char* message);
  static void error(const char* tag, const char* message);
  static void debug(const char* tag, const char* message);
};
}  // namespace jjfp::common