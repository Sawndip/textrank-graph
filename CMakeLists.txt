cmake_minimum_required(VERSION 3.0)
project(helium)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Werror")

# Include `include` directory.
include_directories(include)

##############################################################################
# Helium
##############################################################################

# Find main sources in `src` directory.
file(GLOB_RECURSE SOURCES src/*.cc src/*.h)

# Add library for the source files.
add_library(src ${SOURCES})

# Create executable and link libraries.
add_executable(helium src/main.cc)
target_link_libraries(helium src)

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
target_link_libraries(test-helium src pthread ${GTEST_BOTH_LIBRARIES})

add_test(NAME tests COMMAND test-helium)

##############################################################################
# Helium Documentation
##############################################################################

# Include Doxygen.
find_package(Doxygen)

if(DOXYGEN_FOUND)
    # Copy Doxyfile from source dir to binary dir.
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    )

    # Add target to build docs.
    add_custom_target(docs
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(DOXYGEN_FOUND)
