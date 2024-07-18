message(STATUS "Common utilies")

# Add library
add_library(
  libcommon
  src/log.cpp
  src/print.cpp
)

target_include_directories(
  libcommon
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
