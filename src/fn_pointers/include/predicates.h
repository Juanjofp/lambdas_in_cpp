#pragma once

#include <string>

namespace jjfp::fn_pointers {
bool max(double a, double b);
bool min(double a, double b);

bool max(const double &a, const double &b);
bool min(const double &a, const double &b);

bool max(const std::string &a, const std::string &b);
bool min(const std::string &a, const std::string &b);

}  // namespace jjfp::fn_pointers