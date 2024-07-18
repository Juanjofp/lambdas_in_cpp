#include "compare.h"

namespace jjfp::fn_pointers {

void find_max_or_min(std::vector<double>& values,
                     bool (*predicate)(double, double)) {
  if (values.empty()) {
    throw std::invalid_argument("Values cannot be empty");
  }

  double result = values.front();

  for (const auto& value : values) {
    if (predicate(value, result)) {
      result = value;
    }
  }

  std::cout << "Result: " << result << std::endl;
}

void find_max_or_min_alias(std::vector<double>& values, Predicate predicate) {
  if (values.empty()) {
    throw std::invalid_argument("Values cannot be empty");
  }

  double result = values.front();

  for (const auto& value : values) {
    if (predicate(value, result)) {
      result = value;
    }
  }

  std::cout << "Result: " << result << std::endl;
}

}  // namespace jjfp::fn_pointers