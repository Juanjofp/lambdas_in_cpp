#pragma once

#include <string>

namespace jjfp::functors {
bool max(const double& a, const double& b) { return a > b; }

bool min(const double& a, const double& b) { return a < b; }

bool max_string(const std::string& a, const std::string& b) {
  return a.length() > b.length();
}

bool min_string(const std::string& a, const std::string& b) {
  return a.length() < b.length();
}

class MaxValue {
 public:
  bool operator()(const double& a, const double& b) const { return a > b; }
  bool operator()(const int& a, const int& b) const { return a > b; }
  bool operator()(const std::string& a, const std::string& b) const {
    return a.length() > b.length();
  }
};

class MinValue {
 public:
  bool operator()(const double& a, const double& b) const { return a < b; }
  bool operator()(const int& a, const int& b) const { return a < b; }
  bool operator()(const std::string& a, const std::string& b) const {
    return a.length() < b.length();
  }
};
}  // namespace jjfp::functors