#pragma once

#include <string>

#include "print.h"

namespace jjfp::functors {

class BaseFunctor {
 public:
  virtual ~BaseFunctor() = default;

  virtual std::string operator()(const std::string& str) const = 0;
};

class UpperCaseFunctor : public BaseFunctor {
 public:
  std::string operator()(const std::string& str) const override {
    std::string result;

    for (const auto& c : str) {
      result += toupper(c);
    }

    return result;
  }
};

class LowerCaseFunctor : public BaseFunctor {
 public:
  std::string operator()(const std::string& str) const override {
    std::string result;

    for (const auto& c : str) {
      result += tolower(c);
    }

    return result;
  }
};

void transform_cases(const BaseFunctor& functor, const std::string& str) {
  common::Print::print_message("Transforming string: " + str +
                               " using functor");

  common::Print::print_message("Result: " + functor(str));
}

}  // namespace jjfp::functors