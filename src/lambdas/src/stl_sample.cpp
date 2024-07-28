#include "stl_sample.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

#include "print.h"

void jjfp::lambdas::run_stl_sample() {
  std::vector<int> values{1, 99, 2, 76, 3, 23, 4, 5, 15, 56, 21, 7, 8, 9, 10};

  common::Print::print_message("Values:");
  common::Print::print_values(values);

  // Iterate over the valuees

  std::for_each(values.begin(), values.end(), [](int& value) { value++; });

  common::Print::print_message("Values after increment:");
  common::Print::print_values(values);

  // Sort values

  std::sort(values.begin(), values.end(),
            [](const int& a, const int& b) { return a < b; });

  common::Print::print_message("Values after sort:");
  common::Print::print_values(values);

  // Remove values

  values.erase(std::remove_if(values.begin(), values.end(),
                              [](const int& value) { return value > 80; }),
               values.end());

  common::Print::print_message("Values after remove:");
  common::Print::print_values(values);

  // Accumulate values

  int sum = std::accumulate(values.begin(), values.end(), 0,
                            [](const int& a, const int& b) { return a + b; });
  common::Print::print_message("Sum of values: " + std::to_string(sum));

  // Count values

  int count = std::count_if(values.begin(), values.end(),
                            [](const int& value) { return value < 10; });
  common::Print::print_message("Count of values less than 10: " +
                               std::to_string(count));

  // Find values

  auto it = std::find_if(values.begin(), values.end(),
                         [](const int& value) { return value == 11; });
  if (it != values.end()) {
    common::Print::print_message("Value found 11: " + std::to_string(*it));
  }

  // Find values

  auto it2 = std::find_if(values.begin(), values.end(),
                          [](const int& value) { return value == 200; });
  if (it2 == values.end()) {
    common::Print::print_message("Value 200 not found");
  }

  // All of values

  bool all = std::all_of(values.begin(), values.end(),
                         [](const int& value) { return value < 100; });
  common::Print::print_message(
      std::format("All values are less than 100: {}", all ? "true" : "false"));

  // Any of values

  bool any = std::any_of(values.begin(), values.end(),
                         [](const int& value) { return value > 50; });
  common::Print::print_message(
      std::format("Any value is greater than 50:  {}", any ? "true" : "false"));

  // None of values

  bool none = std::none_of(values.begin(), values.end(),
                           [](const int& value) { return value > 100; });
  common::Print::print_message(
      std::format("None value is greater than 100: {}", std::to_string(none)));

  // Generate values

  std::vector<int> generated_values{};

  generated_values.resize(10);

  std::generate(generated_values.begin(), generated_values.end(),
                []() { return std::rand() % 10; });

  common::Print::print_message("Values after generate:");
  common::Print::print_values(generated_values);

  // Transform values

  std::vector<int> transformed_values{};

  transformed_values.resize(generated_values.size());

  std::transform(generated_values.begin(), generated_values.end(),
                 transformed_values.begin(),
                 [](const int& value) { return value * 2; });

  common::Print::print_message("Values after transform:");
  common::Print::print_values(transformed_values);

  // Copy values

  std::vector<int> copied_values{};

  copied_values.resize(transformed_values.size());

  std::copy(transformed_values.begin(), transformed_values.end(),
            copied_values.begin());

  common::Print::print_message("Values after copy:");
  common::Print::print_values(copied_values);

  // Replace values

  std::replace_if(
      copied_values.begin(), copied_values.end(),
      [](const int& value) { return value > 10; }, 0);

  common::Print::print_message("Values after replace:");
  common::Print::print_values(copied_values);

  // Fill values

  std::fill(copied_values.begin(), copied_values.end(), 100);

  common::Print::print_message("Values after fill:");
  common::Print::print_values(copied_values);

  // Reverse values

  std::reverse(generated_values.begin(), generated_values.end());

  common::Print::print_message("Values after reverse:");
  common::Print::print_values(generated_values);

  // Unique values

  std::vector<int> unique_values{1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

  std::sort(unique_values.begin(), unique_values.end());

  common::Print::print_message("Values sort unique:");

  common::Print::print_values(unique_values);

  auto last = std::unique(unique_values.begin(), unique_values.end());

  common::Print::print_message("Values after unique:");

  common::Print::print_values(unique_values);

  unique_values.erase(last, unique_values.end());

  common::Print::print_message("Values after unique:");

  common::Print::print_values(unique_values);
}