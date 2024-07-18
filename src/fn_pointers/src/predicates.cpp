#include "predicates.h"

bool jjfp::fn_pointers::max(double a, double b) { return a > b; }

bool jjfp::fn_pointers::min(double a, double b) { return a < b; }

bool jjfp::fn_pointers::max(const double& a, const double& b) { return a > b; }

bool jjfp::fn_pointers::min(const double& a, const double& b) { return a < b; }

bool jjfp::fn_pointers::max(const std::string& a, const std::string& b) {
  return a.length() > b.length();
}

bool jjfp::fn_pointers::min(const std::string& a, const std::string& b) {
  return a.length() < b.length();
}
