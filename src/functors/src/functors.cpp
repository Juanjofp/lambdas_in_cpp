#include "functors.h"

#include <vector>

#include "base_functor.h"
#include "functor_template.h"
#include "log.h"
#include "operation_functor.h"
#include "predicates.h"
#include "print.h"
#include "transform_cases.h"

using namespace jjfp;

void jjfp::functors::run_sample() {
  common::Print::print_header("Running sample functors");

  const std::string message{"HeLlo WoRld"};

  functors::UpperCase upper_case;

  common::Print::print_message("Hello World in upper case: " +
                               upper_case(message));

  functors::LowerCase lower_case;

  common::Print::print_message("Hello World in lower case: " +
                               lower_case(message));

  // Using complete signature for call operator

  common::Print::print_message(
      "Hello World in upper case upper_case.operator()(message): " +
      upper_case.operator()(message));

  common::Print::print_separator();

  functors::UpperCaseFunctor upper_case_functor;

  functors::LowerCaseFunctor lower_case_functor;

  functors::transform_cases(upper_case_functor, message);

  functors::transform_cases(lower_case_functor, message);

  common::Print::print_separator();

  functors::MultiplyBy multiply_by_two{2};

  common::Print::print_message("Multiply 5 by 2: " +
                               std::to_string(multiply_by_two(5)));

  functors::DivideBy divide_by_two{2};

  common::Print::print_message("Divide 5 by 2: " +
                               std::to_string(divide_by_two(5)));

  try {
    functors::DivideBy divide_by_zero{0};
  } catch (const std::invalid_argument& e) {
    common::Log::error(TAG, e.what());
  }

  common::Print::print_separator();

  const std::vector<int> data{1, 2, 3, 4, 5};

  common::Print::print_message("Original data:");
  functors::print_vector(data);

  const auto multiplied_data = functors::apply_transform(data, multiply_by_two);

  common::Print::print_message("Data multiplied by 2:");
  functors::print_vector(multiplied_data);

  const auto divided_data = functors::apply_transform(data, divide_by_two);

  common::Print::print_message("Data divided by 2:");
  functors::print_vector(divided_data);

  common::Print::print_separator();

  // Using lambda

  auto max_value = functors::find_max_or_min_template(
      data, [](int a, int b) { return a > b ? a : b; });

  common::Print::print_message("Max value in data with lambda: " +
                               std::to_string(max_value));

  max_value = functors::find_max_or_min_template(data, functors::MaxValue{});
  common::Print::print_message("Max value in data with MaxValue functor: " +
                               std::to_string(max_value));

  std::vector<double> double_data{1.1, 2.2, 3.3, 4.4, 5.5};

  max_value = functors::find_max_or_min_template(double_data, functors::max);
  common::Print::print_message("Max value in data with max function pointer: " +
                               std::to_string(max_value));

  max_value = functors::find_max_or_min_template(data, functors::MaxValue{});
  common::Print::print_message("Max value in data with MaxValue functor: " +
                               std::to_string(max_value));

  auto min_value = functors::find_max_or_min_template(data, functors::min);
  common::Print::print_message("Min value in data with min function pointer:" +
                               std::to_string(min_value));

  min_value = functors::find_max_or_min_template(data, functors::MinValue{});
  common::Print::print_message("Min value in data with MinValue functor: " +
                               std::to_string(min_value));

  std::vector<std::string> data_string{"Hello", "World", "C++", "Functors",
                                       "SuperLongString"};

  auto result = functors::find_max_or_min_template(
      data_string, [](const std::string& a, const std::string& b) {
        return a.length() > b.length();
      });
  common::Print::print_message("Max value in data_string with lambda: " +
                               result);

  result =
      functors::find_max_or_min_template(data_string, functors::max_string);
  common::Print::print_message(
      "Max value in data_string with max function pointer: " + result);

  result =
      functors::find_max_or_min_template(data_string, functors::MaxValue{});
  common::Print::print_message(
      "Max value in data_string with MaxValue functor: " + result);

  result =
      functors::find_max_or_min_template(data_string, functors::min_string);
  common::Print::print_message(
      "Min value in data_string with min function pointer: " + result);

  result =
      functors::find_max_or_min_template(data_string, functors::MinValue{});
  common::Print::print_message(
      "Min value in data_string with MinValue functor: " + result);

  // Uncomment to see compilation error. The functor does not have a call
  // operator that takes two arguments and returns a bool

  // auto invalid = functors::find_max_or_min_template(data, divide_by_two);

  common::Log::info(TAG, "Sample functors completed");
}