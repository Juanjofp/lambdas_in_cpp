#include "fn_pointers.h"

#include <iostream>

#include "compare.h"
#include "log.h"
#include "predicates.h"
#include "print.h"

using namespace std;
using namespace jjfp;

void sample_assginment() {
  // Function pointer
  double (*operation)(double, double) = nullptr;

  operation = fn_pointers::add;

  cout << "Addition: " << operation(1.0, 2.0) << endl;

  operation = fn_pointers::subtract;

  cout << "Subtraction: " << operation(2.0, 1.0) << endl;
}

void sample_initialization() {
  // Function pointer initialization

  double (*operation)(double, double){fn_pointers::add};

  cout << "Addition: " << operation(1.0, 2.0) << endl;

  operation = fn_pointers::subtract;

  cout << "Subtraction: " << operation(2.0, 1.0) << endl;
}

void sample_with_auto() {
  auto* operation{&fn_pointers::add};  // More explicit using &
  // auto operation{fn_pointers::add}; // Valid but less explicit

  cout << "Addition: " << operation(1.0, 2.0) << endl;

  operation = fn_pointers::subtract;

  cout << "Subtraction: " << operation(2.0, 1.0) << endl;
}

auto* return_function_pointer_with_auto(char op) {
  double (*operation)(double, double){nullptr};

  if (op == '+') {
    operation = &fn_pointers::add;
  } else if (op == '-') {
    operation = &fn_pointers::subtract;
  }

  return operation;
}

void sample_return_function_pointer_with_auto() {
  auto* operation = return_function_pointer_with_auto('+');

  cout << "Addition: " << operation(1.0, 2.0) << endl;

  operation = return_function_pointer_with_auto('-');

  cout << "Subtraction: " << operation(2.0, 1.0) << endl;

  operation = return_function_pointer_with_auto('*');

  if (operation == nullptr) {
    cout << "Invalid operation" << endl;
  }
}

// typedef double (*ArithmeticFn)(double, double); // ANSI C style
using ArithmeticFn = double (*)(double, double);  // C++ style (preferred)

ArithmeticFn return_funcion_pointer_without_auto(char op) {
  if (op == '+') {
    return &fn_pointers::add;
  } else if (op == '-') {
    return &fn_pointers::subtract;
  }

  return nullptr;
}

void sample_return_function_pointer_without_auto() {
  // auto operation = return_funcion_pointer_without_auto('+');
  ArithmeticFn operation = return_funcion_pointer_without_auto('+');

  cout << "Addition: " << operation(1.0, 2.0) << endl;

  operation = return_funcion_pointer_without_auto('-');

  cout << "Subtraction: " << operation(2.0, 1.0) << endl;

  operation = return_funcion_pointer_without_auto('*');

  if (operation == nullptr) {
    cout << "Invalid operation" << endl;
  }
}

void sample_callbacks_with_function_pointers() {
  vector<double> values{1.0, 2.0, 3.0, 4.0, 5.0};

  fn_pointers::find_max_or_min(values, fn_pointers::max);

  fn_pointers::find_max_or_min(values, fn_pointers::min);

  fn_pointers::find_max_or_min_alias(values, fn_pointers::max);

  fn_pointers::find_max_or_min_alias(values, fn_pointers::min);

  vector<double> empty_values;

  try {
    fn_pointers::find_max_or_min(empty_values, fn_pointers::max);
  } catch (const invalid_argument& e) {
    cout << e.what() << endl;
  }
}

void sample_callbacks_with_templates() {
  vector<double> double_values{1.0, 2.0, 3.0, 4.0, 5.0};

  fn_pointers::PredicateTemplate<double> max_predicate{fn_pointers::max};
  auto result =
      fn_pointers::find_max_or_min_with_templates(double_values, max_predicate);

  cout << "Max: " << result << endl;

  fn_pointers::PredicateTemplate<double> min_predicate{fn_pointers::min};
  result =
      fn_pointers::find_max_or_min_with_templates(double_values, min_predicate);

  cout << "Min: " << result << endl;

  vector<double> empty_values;

  try {
    fn_pointers::find_max_or_min_with_templates(empty_values, fn_pointers::max);
  } catch (const invalid_argument& e) {
    cout << e.what() << endl;
  }

  common::Print::print_separator();

  vector<string> string_values{"one", "two", "three", "four", "five"};

  fn_pointers::PredicateTemplate<string> str_predicate{fn_pointers::max};

  auto str_result =
      fn_pointers::find_max_or_min_with_templates(string_values, str_predicate);

  cout << "Max: " << str_result << endl;

  str_predicate = fn_pointers::min;

  str_result =
      fn_pointers::find_max_or_min_with_templates(string_values, str_predicate);

  cout << "Min: " << str_result << endl;
}

void fn_pointers::run_sample() {
  common::Print::print_header("Function Pointers");

  common::Log::info(fn_pointers::TAG, "Function Pointers samples");

  // Function pointer

  sample_assginment();

  common::Print::print_separator();

  sample_initialization();

  common::Print::print_separator();

  sample_with_auto();

  common::Print::print_separator();

  sample_return_function_pointer_with_auto();

  common::Print::print_separator();

  sample_return_function_pointer_without_auto();

  common::Print::print_separator();

  sample_callbacks_with_function_pointers();

  sample_callbacks_with_templates();

  common::Log::info(fn_pointers::TAG, "Function Pointers samples end");
}

double jjfp::fn_pointers::add(double a, double b) { return a + b; }

double jjfp::fn_pointers::subtract(double a, double b) { return a - b; }
