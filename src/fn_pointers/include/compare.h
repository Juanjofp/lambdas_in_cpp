#pragma once

#include <iostream>
#include <vector>

namespace jjfp::fn_pointers {

void find_max_or_min(std::vector<double>& values,
                     bool (*predicate)(double, double));

using Predicate = bool (*)(double, double);

template <typename T>
using PredicateTemplate = bool (*)(const T&, const T&);

void find_max_or_min_alias(std::vector<double>& values, Predicate predicate);

template <typename T>
T find_max_or_min_with_templates(std::vector<T>& values,
                                 PredicateTemplate<T> predicate) {
  if (values.empty()) {
    throw std::invalid_argument("Values cannot be empty");
  }

  T result = values.front();

  for (const auto& value : values) {
    if (predicate(value, result)) {
      result = value;
    }
  }

  return result;
}

}  // namespace jjfp::fn_pointers