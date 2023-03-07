# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(other)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files to a library target
add_library(other-1-lib src/one-way-list-node.cpp src/one-way-list.cpp src/one-way-list-node.h src/one-way-list.h)

# Add the executable target and link to the library
add_executable(other-1 src/main.cpp)
target_link_libraries(other-1 other-1-lib)

# Set include directories for the library target
target_include_directories(other-1-lib PUBLIC src)