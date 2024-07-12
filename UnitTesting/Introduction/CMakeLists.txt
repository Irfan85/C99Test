cmake_minimum_required(VERSION 3.26)
project(Introduction C)

set(CMAKE_C_STANDARD 11)

add_executable(Introduction main.c)

add_subdirectory(calculator)
add_subdirectory(tests)

target_link_libraries(Introduction calculator_lib)