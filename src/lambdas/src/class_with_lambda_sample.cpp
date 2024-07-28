#include "class_with_lambda_sample.h"

#include <functional>
#include <iostream>
#include <string>

#include "class_with_lambda.h"
#include "print.h"

void jjfp::lambdas::closures::run_class_with_lambda_sample() {
  class_with_lambda::ClassWithLambda class_with_lambda;

  class_with_lambda.print_statistics();

  class_with_lambda.calculate_statistics();

  class_with_lambda.print_statistics();

  using Predicate = std::function<int(const int&, const int&)>;
  auto lambda = [](const int& value, const int& value2) {
    return value + value2;
  };

  class_with_lambda::StoredLambdas<int, Predicate> stored_lambdas{lambda};

  stored_lambdas.add_value(1);
  stored_lambdas.add_value(2);
  stored_lambdas.add_value(3);
  stored_lambdas.add_value(4);
  stored_lambdas.add_value(5);
  stored_lambdas.add_value(6);
  stored_lambdas.add_value(7);

  int result = stored_lambdas.apply_strategy();

  common::Print::print_message("Result of apply strategy: " +
                               std::to_string(result));

  int accumulalted = 0;
  int count = 0;

  auto lambda2 = [&accumulalted, &count](const int& value, const int& value2) {
    accumulalted += value + value2;
    count++;

    return accumulalted / count;
  };

  class_with_lambda::StoredLambdas<int, Predicate> stored_lambdas2{lambda2};

  stored_lambdas2.add_value(1);
  stored_lambdas2.add_value(2);
  stored_lambdas2.add_value(3);
  stored_lambdas2.add_value(4);

  result = stored_lambdas2.apply_strategy();

  common::Print::print_message("Result of apply strategy 2: " +
                               std::to_string(result));

  std::cout << "Accumulated: " << accumulalted << std::endl;
  std::cout << "Count: " << count << std::endl;

  using Predicate2 =
      std::function<std::string(const std::string&, const std::string&)>;

  auto lambda3 = [](const std::string& value, const std::string& value2) {
    std::cout << "Value: " << value << " Value2: " << value2 << std::endl;

    return value + value2;
  };

  class_with_lambda::StoredLambdas<std::string, Predicate2> stored_lambdas3{
      lambda3};

  stored_lambdas3.add_value("Hello");
  stored_lambdas3.add_value(",");
  stored_lambdas3.add_value(" ");
  stored_lambdas3.add_value("world");
  stored_lambdas3.add_value("!");

  std::string result_string = stored_lambdas3.apply_strategy();

  common::Print::print_message("Result of apply strategy 3: " + result_string);

  common::Print::print_separator();

  auto lambda4 = [](const std::string& value, const std::string& value2) {
    std::cout << "Value: " << value << " Value2: " << value2 << std::endl;

    return value + value2;
  };

  class_with_lambda::MoreStoredLambdas<std::string> more_stored_lambdas{
      lambda4};

  more_stored_lambdas.add_value("Hello");
  more_stored_lambdas.add_value(",");
  more_stored_lambdas.add_value(" ");
  more_stored_lambdas.add_value("world");

  result_string = more_stored_lambdas.apply_strategy();

  common::Print::print_message("Result of apply strategy 4: " + result_string);

  common::Print::print_separator();

  // Same using alias from class MoreStoredLambdas

  class_with_lambda::MoreStoredLambdas<std::string>::Predicate lambda5 =
      [](const std::string& value, const std::string& value2) {
        std::cout << "Value: " << value << " Value2: " << value2 << std::endl;

        return value + value2;
      };

  class_with_lambda::MoreStoredLambdas<std::string> more_stored_lambdas2{
      lambda5};

  more_stored_lambdas2.add_value("Hello");
  more_stored_lambdas2.add_value(",");
  more_stored_lambdas2.add_value(" ");
  more_stored_lambdas2.add_value("lambdas");
  more_stored_lambdas2.add_value("!");

  result_string = more_stored_lambdas2.apply_strategy();

  common::Print::print_message("Result of apply strategy 5: " + result_string);
}