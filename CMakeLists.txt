cmake_minimum_required(VERSION 3.10.0)
project(leak_detection_test VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(leak_detection_test main.cpp)

include(CTest)
enable_testing()

