cmake_minimum_required(VERSION 3.23)
project(test C)

set(CMAKE_C_STANDARD 23)

add_executable(test main.c sources/functions.c headers/functions.h)

include_directories(headers)