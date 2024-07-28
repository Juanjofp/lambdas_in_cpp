#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace jjfp::lambdas::class_with_lambda {
template <typename T, typename Accumulate>
void apply_accumulate(const std::vector<T>& values, Accumulate accumulate) {
  std::for_each(values.cbegin(), values.cend(), accumulate);
}

class ClassWithLambda {
 public:
  ClassWithLambda() : values{1, 2, 3, 4, 5, 6, 7, 8, 9} {}

  void calculate_statistics() {
    // Para usar la lambda en un método de clase, se debe capturar this
    // para poder acceder a los miembros de la clase.
    // los miembros de la clase son accesibles por referencia.

    apply_accumulate(values, [this](int value) {
      total += value;
      count++;
      average = total / count;
    });
  }

  void print_statistics() const {
    std::cout << "Original values: ";

    for (const auto& value : values) {
      std::cout << value << " ";
    }

    std::cout << std::endl;

    std::cout << "Statistics: " << std::endl;

    std::cout << "Total: " << total << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Average: " << average << std::endl;
  }

 private:
  int total = 0;
  int count = 0;
  int average = 0;

  std::vector<int> values;
};

template <typename T, typename Predicate>
class StoredLambdas {
 public:
  StoredLambdas(Predicate strategy) : strategy{strategy} {}

  void add_value(T value) { values.push_back(value); }

  T apply_strategy() {
    T result = values.front();
    values.erase(values.begin());

    for (const auto& value : values) {
      result = strategy(result, value);
    }

    return result;
  }

 private:
  std::vector<T> values;
  Predicate strategy;
};

template <typename T>
class MoreStoredLambdas {
 public:
  using Predicate = T (*)(const T&, const T&);

  MoreStoredLambdas(Predicate strategy) : strategy{strategy} {}

  void add_value(T value) { values.push_back(value); }

  T apply_strategy() {
    T result = values.front();
    values.erase(values.begin());

    for (const auto& value : values) {
      result = strategy(result, value);
    }

    return result;
  }

 private:
  std::vector<T> values;
  Predicate strategy;
};
}  // namespace jjfp::lambdas::class_with_lambda