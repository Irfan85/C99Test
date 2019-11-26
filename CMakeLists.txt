cmake_minimum_required(VERSION 3.15)
project(C99Test C)

set(CMAKE_C_STANDARD 99)

add_executable(C99Test FIleIO/CopyPaste.c Structures/SimpleStructure.c Structures/DeckOfCards.c Excercises/CircularPrime.c Misc/ExternalStorageClass.c Excercises/MatrixMaxProduct.c Excercises/DayCounter.c)