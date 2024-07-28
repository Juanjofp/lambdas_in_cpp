#include "closures.h"

#include <vector>

#include "print.h"

void jjfp::lambdas::closures::run_closure_samples() {
  // Closure
  // A closure is a lambda that captures variables from the surrounding scope.
  // The lambda can capture variables by value or by reference.
  // The lambda can also capture variables by move.

  // Capture by value
  // The lambda captures the variable by value.
  // The lambda creates a copy of the variable.
  // The lambda does not modify the original variable.
  // The lambda captures the variable at the time of the lambda creation

  int x = 10;

  std::vector<int> values{1, 2, 3, 4, 5};

  common::Print::print_message("Values:");

  common::Print::print_values(values);

  auto result = apply_transform(values, [x](int value) { return value + x; });

  common::Print::print_message(
      "Values after apply transform with capture by value:");

  common::Print::print_values(result);

  // Capture all variables by value

  int y = 20;

  auto result2 =
      apply_transform(values, [=](int value) { return value + x + y; });

  common::Print::print_message(
      "Values after apply transform with capture all "
      "variables by value:");

  common::Print::print_values(result2);

  // Capture by reference
  // The lambda captures the variable by reference.
  // The lambda does not create a copy of the variable.
  // The lambda modifies the original variable.
  // The lambda captures the variable at the time of the lambda execution

  auto result3 = apply_transform(values, [&x](int value) {
    x++;

    return value + x;
  });

  common::Print::print_message(
      "Values after apply transform with capture by reference:");

  common::Print::print_values(result3);

  // Capture all variables by reference

  auto result4 =
      apply_transform(values, [&](int value) { return value + x + y; });

  common::Print::print_message(
      "Values after apply transform with capture all "
      "variables by reference:");

  common::Print::print_values(result4);

  // Capture by move
  // The lambda captures the variable by move.
  // The lambda does not create a copy of the variable.
  // The variable is moved to the lambda so it is no longer available in the
  // surrounding scope.
  // The lambda captures the variable at the time of the lambda creation

  auto pointer = std::make_unique<int>(30);

  auto result5 = apply_transform(
      values,
      [pointer = std::move(pointer)](int value) { return value + *pointer; });

  common::Print::print_message(
      "Values after apply transform with capture by "
      "move:");

  common::Print::print_values(result5);

  if (pointer == nullptr) {
    common::Print::print_message("Pointer is null after move");
  } else {
    common::Print::print_message("Pointer is not null");
  }

  // Mix capture by value and by reference

  // All by copy, except y by reference
  auto result6 = apply_transform(values, [=, &y](int value) {
    y++;

    return value + x + y;
  });

  // All by reference, except x by copy
  auto result7 = apply_transform(values, [&, x](int value) {
    y++;

    return value + x + y;
  });
}