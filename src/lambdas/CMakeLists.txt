message(STATUS "Building lambdas...")

# Add library
add_library(
  liblambdas
  src/lambdas.cpp
  src/stl_sample.cpp
  src/auto_lambdas.cpp
  src/closures.cpp
  src/class_with_lambda_sample.cpp
)

target_include_directories(
  liblambdas
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  liblambdas
  PRIVATE
  libcommon
)