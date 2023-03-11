# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(various-operation-in-different-data-structures)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files to a library target
add_library(various-operation-in-different-data-structures-lib src/dynamic-array/dynamic-array.cpp src/dynamic-array/dynamic-array.h src/two-way-list/two-way-list.cpp src/two-way-list/two-way-list.h src/two-way-list/two-way-list-node.cpp src/two-way-list/two-way-list-node.h)

# Add the executable target and link to the library
add_executable(various-operation-in-different-data-structures src/main.cpp)
target_link_libraries(various-operation-in-different-data-structures various-operation-in-different-data-structures-lib)

# Set include directories for the library target
target_include_directories(various-operation-in-different-data-structures-lib PUBLIC src)