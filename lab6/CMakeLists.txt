cmake_minimum_required(VERSION 3.23)
project(lab6 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab6 main.c sources/linked_list.c headers/linked_list.h)

include_directories(headers)