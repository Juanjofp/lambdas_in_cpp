message(STATUS "Building functions pointers...")

# Add library
add_library(
  libfnpointers
  src/fn_pointers.cpp
  src/predicates.cpp
  src/compare.cpp
)

target_include_directories(
  libfnpointers
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  libfnpointers
  PRIVATE
  libcommon
)