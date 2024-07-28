#pragma once

#include <iostream>
#include <vector>

namespace jjfp::lambdas {
// Simple function

double add10(const double& b) { return 10 + b; }

// Functor

class AddFunctor {
 public:
  AddFunctor(const double& a) : a{a} {}

  double operator()(const double& b) const { return a + b; }

 private:
  double a;
};

// Lambda

auto add10_lambda = [](const double& a) -> double { return 10 + a; };

// Transform function

template <typename T, typename Predicate>
std::vector<T> apply_transform(const std::vector<T>& values,
                               Predicate predicate) {
  std::vector<T> result;

  for (const auto& value : values) {
    result.push_back(predicate(value));
  }

  return result;
}

// Print values
template <typename T>
void print_values(const std::vector<T>& values) {
  for (const auto& value : values) {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

}  // namespace jjfp::lambdas