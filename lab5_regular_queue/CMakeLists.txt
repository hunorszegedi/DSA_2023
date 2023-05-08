cmake_minimum_required(VERSION 3.23)
project(lab5_regular_queue C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5_regular_queue main.c sources/functions.c headers/functions.h)

include_directories(headers)