message(STATUS "Building lambdas...")

# Add library
add_library(
  liblambdas
  src/lambdas.cpp
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