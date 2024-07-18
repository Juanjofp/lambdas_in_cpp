#pragma once

namespace jjfp::functors {
class MultiplyBy {
 public:
  MultiplyBy(int times) : times{times} {}

  int operator()(int a) const { return times * a; }

 private:
  int times;
};

class DivideBy {
 public:
  DivideBy(int times) : times{times} {
    if (times == 0) {
      throw std::invalid_argument("Divide by zero");
    }
  }

  int operator()(int a) const { return a / times; }

 private:
  int times;
};
}  // namespace jjfp::functors