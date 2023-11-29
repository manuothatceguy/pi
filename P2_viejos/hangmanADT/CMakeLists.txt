cmake_minimum_required(VERSION 3.24)
project(hangmanADT C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -std=c99 -fsanitize=address")

add_executable(hangmanADT main.c hangmanADT.c hangmanADT.h)
