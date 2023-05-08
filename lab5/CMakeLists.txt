cmake_minimum_required(VERSION 3.23)
project(lab5 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5 main.c sources/functions.c headers/functions.h)

include_directories(headers)
