#include "lambdas.h"

#include <string>
#include <vector>

#include "auto_lambdas.h"
#include "class_with_lambda_sample.h"
#include "closures.h"
#include "integration_fpointers_functors_lambas.h"
#include "log.h"
#include "max_min_lambdas.h"
#include "print.h"
#include "stl_sample.h"

using namespace jjfp::common;

void simple_lambda() {
  auto lambda_basic = []() { Print::print_message("Simple lambda"); };

  lambda_basic();

  // Lambda with parameters

  auto lambda_with_params = [](std::string& message) {
    Print::print_message(message);
  };

  std::string message = "Lambda with parameters";
  lambda_with_params(message);

  // Lambda with return value

  auto lambda_with_return = [](int a, int b) -> int { return a + b; };

  int result = lambda_with_return(2, 3);
  Print::print_message("Lambda with return value: " + std::to_string(result));

  // Lambda with capture

  int x = 10;
  int y = 20;

  auto lambda_with_capture = [x, y]() { return x + y; };

  result = lambda_with_capture();

  Print::print_message("Lambda with capture: " + std::to_string(result));
}

void jjfp::lambdas::run_sample() {
  Print::print_header("Lambdas samples");

  Log::info(TAG, "Lambdas samples");

  // Simple lambda

  simple_lambda();

  Print::print_separator();

  // Integrate lambdas with functions and functors

  std::vector<double> values{1.1, 2.2, 3.3, 4.4, 5.5};

  Print::print_message("Values:");

  print_values(values);

  // Apply transform with function

  Print::print_message("Apply transform with function add10:");

  auto result = apply_transform(values, add10);

  print_values(result);

  // Apply transform with functor

  Print::print_message("Apply transform with functor AddFunctor:");

  AddFunctor add_functor{10};

  result = apply_transform(values, add_functor);

  print_values(result);

  // Apply transform with lambda

  Print::print_message("Apply transform with lambda add10_lambda:");

  result = apply_transform(values, add10_lambda);

  print_values(result);

  result =
      apply_transform(values, [](const double& a) -> double { return 10 + a; });

  print_values(result);

  Print::print_separator();

  // Max or min with lambdas

  const std::vector<int> int_values{1, 2, 3, 4, 5};

  Print::print_message("Int values:");

  print_values(int_values);

  int max_value = max_or_min(int_values, [](int a, int b) { return a > b; });

  Print::print_message("Max value: " + std::to_string(max_value));

  int min_value = max_or_min(int_values, [](int a, int b) { return a < b; });

  Print::print_message("Min value: " + std::to_string(min_value));

  const std::vector<std::string> string_values{"a", "ab", "abc", "abcd"};

  Print::print_message("String values:");

  print_values(string_values);

  std::string max_string = max_or_min(
      string_values,
      [](const std::string& a,
         const std::string& b) -> bool /* return type is optional */ {
        return a.size() > b.size();
      });

  Print::print_message("Max string: " + max_string);

  std::string min_string =
      max_or_min(string_values, [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
      });

  Print::print_message("Min string: " + min_string);

  Print::print_separator();

  // STL sample

  run_stl_sample();

  Print::print_separator();

  // Auto lambdas

  run_auto_lambdas();

  Print::print_separator();

  // Closures

  closures::run_closure_samples();

  Print::print_separator();

  // Lambdas with classes

  closures::run_class_with_lambda_sample();
}