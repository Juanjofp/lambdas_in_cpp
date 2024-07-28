#pragma once

#include <vector>

namespace jjfp::lambdas::closures {

template <typename T, typename Transform>
std::vector<T> apply_transform(const std::vector<T>& values,
                               Transform transform) {
  std::vector<T> result;

  for (const auto& value : values) {
    result.push_back(transform(value));
  }

  return result;
}

void run_closure_samples();
}  // namespace jjfp::lambdas::closures