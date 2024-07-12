project(calculator C)

set(CMAKE_C_STANDARD 11)

set(HEADER_FILES Calculator.h)
set(SOURCE_FILES Calculator.c)

add_library(calculator_lib ${HEADER_FILES} ${SOURCE_FILES})
