cmake_minimum_required(VERSION 3.26)
project(Introduction)

set(CMAKE_CXX_STANDARD 17)

add_executable(Introduction main.cpp
        Calculator.h)

add_subdirectory(tests)
