#pragma once

#include <iostream>
#include <vector>

namespace jjfp::functors {
template <typename T, typename Functor>
std::vector<T> apply_transform(const std::vector<T>& data,
                               const Functor& functor) {
  std::vector<T> result;

  for (const auto& item : data) {
    result.push_back(functor(item));
  }

  return result;
}

template <typename T>
void print_vector(const std::vector<T>& data) {
  for (const auto& item : data) {
    std::cout << item << " ";
  }

  std::cout << std::endl;
}

template <typename T, typename Functor>
const T find_max_or_min_template(const std::vector<T>& data,
                                 const Functor& functor) {
  if (data.empty()) {
    throw std::invalid_argument("Empty data");
  }

  T result = data.front();

  for (const T& item : data) {
    if (functor(item, result)) {
      result = item;
    }
  }

  return result;
}
}  // namespace jjfp::functors