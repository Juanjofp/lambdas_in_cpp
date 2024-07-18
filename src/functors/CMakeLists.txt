message(STATUS "Building functors...")

# Add library
add_library(
  libfunctors
  src/functors.cpp
)

target_include_directories(
  libfunctors
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  libfunctors
  PRIVATE
  libcommon
)