cmake_minimum_required(VERSION 3.23)
project(lab5_circular_queue C)

set(CMAKE_C_STANDARD 23)

add_executable(lab5_circular_queue main.c sources/circular_queue.c headers/circular_queue.h)

include_directories(headers)