#pragma once

#include <vector>

namespace jjfp::lambdas {
template <typename T, typename Comparison>
T max_or_min(const std::vector<T>& values, Comparison comparison) {
  T result = values.front();

  for (const auto& value : values) {
    if (comparison(value, result)) {
      result = value;
    }
  }

  return result;
}
}  // namespace jjfp::lambdas