cmake_minimum_required(VERSION 3.28)

project(functional_cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Common functions
add_subdirectory(src/common)

# Libraries
add_subdirectory(src/lambdas)
add_subdirectory(src/fn_pointers)
add_subdirectory(src/functors)

# Executable
add_executable(functional_cpp src/main.cpp)

# Add libcommon in the last postion to avoid linking errors
# because libcommon is a dependency for librawpointers and libuniquepointer and other libraries
target_link_libraries(
  functional_cpp
  PRIVATE
  liblambdas
  libfunctors
  libfnpointers
  libcommon
)