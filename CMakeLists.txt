cmake_minimum_required(VERSION 3.0)
project(helium)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Werror")

# Find main sources in `lib` directories.
file(GLOB_RECURSE LIBRARY lib/*.cc lib/*.h)

# Add source and library.
add_library(lib ${LIBRARY})

# Enable testing and add test command.
enable_testing()

# Find test files in `tests` directory.
file(GLOB_RECURSE TESTS tests/*.cc)

# Include GTest.
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create executable for testing and link libraries.
add_executable(test-helium tests/test_main.cc ${TESTS})
target_link_libraries(test-helium lib pthread ${GTEST_BOTH_LIBRARIES})

add_test(NAME tests COMMAND test-helium)
