cmake_minimum_required(VERSION 3.23)
project(lab4 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab4 main.c sources/array.c headers/array.h)

include_directories(headers)