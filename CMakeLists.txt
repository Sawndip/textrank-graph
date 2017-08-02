cmake_minimum_required(VERSION 3.0)
project(helium)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Werror")

##############################################################################
# Helium Library
##############################################################################

# Find main sources in `lib` directory.
file(GLOB_RECURSE LIBRARY lib/*.cc lib/*.h)

# Add library for the source files.
add_library(lib ${LIBRARY})

##############################################################################
# Helium Main
##############################################################################

# Find main sources in `src` directory.
file(GLOB_RECURSE SOURCES src/*.cc src/*.h)

# Add library for the source files.
add_library(src ${SOURCES})

# Create executable and link libraries.
add_executable(helium src/main.cc)
target_link_libraries(helium lib src)

##############################################################################
# Helium Testing
##############################################################################

# Enable testing and add test command.
enable_testing()

# Find test files in `tests` directory.
file(GLOB_RECURSE TESTS tests/*.cc)

# Include Threads (required for Gtest).
find_package(Threads REQUIRED)

# Include GoogleTest.
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create executable for testing and link libraries.
add_executable(test-helium tests/test_main.cc ${TESTS})
target_link_libraries(test-helium lib src pthread ${GTEST_BOTH_LIBRARIES})

add_test(NAME tests COMMAND test-helium)
