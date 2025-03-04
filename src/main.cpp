#include "fn_pointers.h"
#include "functors.h"
#include "lambdas.h"
#include "print.h"

using namespace jjfp;

const char* TAG = "MAIN";

int main() {
  common::Print::print_header("Functional Programming in C++");

  fn_pointers::run_sample();

  functors::run_sample();

  lambdas::run_sample();

  return 0;
}