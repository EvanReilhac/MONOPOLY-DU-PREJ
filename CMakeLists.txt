cmake_minimum_required(VERSION 3.20)
project(MONOPOLY C)

set(CMAKE_C_STANDARD 99)

add_executable(MONOPOLY main.c EXO.c EXO.h FONCTION.c FONCTION.h MACRO.h STRUCTURE.c STRUCTURE.h)
