# Set build type to Release
set(CMAKE_BUILD_TYPE Release)

# Set optimization to O3
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(various-operation-in-different-data-structures)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files to a library target
add_library(dynamic-array-lib src/dynamic-array/dynamic-array.cpp src/dynamic-array/dynamic-array.h)
add_library(two-way-list-lib src/two-way-list/two-way-list.cpp src/two-way-list/two-way-list.h src/two-way-list/two-way-list-node.cpp src/two-way-list/two-way-list-node.h)
add_library(maximum-heap-lib src/maximum-heap/maximum-heap.cpp src/maximum-heap/maximum-heap.h)
add_library(binary-search-tree-lib src/binary-search-tree/binary-search-tree.cpp src/binary-search-tree/binary-search-tree.h src/binary-search-tree/binary-search-tree-node.cpp src/binary-search-tree/binary-search-tree-node.h)
add_library(red-black-tree-lib src/red-black-tree/red-black-tree.cpp src/red-black-tree/red-black-tree.h src/red-black-tree/red-black-tree-node.cpp src/red-black-tree/red-black-tree-node.h src/red-black-tree/red-black-tree-colors.h)
add_library(helper-lib src/helpers/random-helper.cpp src/helpers/random-helper.h)

# Add the executable target and link to the library
add_executable(various-operation-in-different-data-structures src/main.cpp)
target_link_libraries(various-operation-in-different-data-structures dynamic-array-lib two-way-list-lib maximum-heap-lib binary-search-tree-lib red-black-tree-lib helper-lib)

# Set include directories for the library target
target_include_directories(dynamic-array-lib PUBLIC src/dynamic-array)
target_include_directories(two-way-list-lib PUBLIC src/two-way-list)
target_include_directories(maximum-heap-lib PUBLIC src/maximum-heap)
target_include_directories(binary-search-tree-lib PUBLIC src/binary-search-tree)
target_include_directories(red-black-tree-lib PUBLIC src/red-black-tree)
target_include_directories(helper-lib PUBLIC src/helpers)