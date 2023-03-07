# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(other)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files to a library target
add_library(1-queues-lib src/table-queue.cpp src/table-queue.h)

# Add the executable target and link to the library
add_executable(1-queues src/main.cpp)
target_link_libraries(1-queues 1-queues-lib)

# Set include directories for the library target
target_include_directories(1-queues-lib PUBLIC src)