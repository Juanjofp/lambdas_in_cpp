#include "auto_lambdas.h"

#include <iostream>
#include <numeric>
#include <vector>

void jjfp::lambdas::run_auto_lambdas() {
  // Auto lambda

  auto accumalate_lambda = [](const auto& a, const auto& b) { return a + b; };

  // Test auto lambda

  // With integer values

  std::vector<int> values{1, 2, 3, 4, 5};

  int sum = std::accumulate(values.begin(), values.end(), 0, accumalate_lambda);

  std::cout << "Sum of values: " << sum << std::endl;

  // With double values
  std::vector<double> values_double{1.1, 2.2, 3.3, 4.4, 5.5};

  double sum_double = std::accumulate(
      values_double.begin(), values_double.end(), 0.0, accumalate_lambda);

  std::cout << "Sum of values: " << sum_double << std::endl;

  // With string values
  std::vector<std::string> values_string{"1", "2", "3", "4", "5"};

  std::string sum_string =
      std::accumulate(values_string.begin(), values_string.end(), std::string{},
                      accumalate_lambda);

  std::cout << "Sum of values: " << sum_string << std::endl;
}