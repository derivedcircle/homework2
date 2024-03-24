cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Homework2 main.cpp sensor.cpp sensor.h)