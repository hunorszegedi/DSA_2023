cmake_minimum_required(VERSION 3.23)
project(lab1_gyakorlas C)

set(CMAKE_C_STANDARD 23)

add_executable(lab1_gyakorlas main.c sources/functions.c headers/functions.h headers/constatns.h)

include_directories(headers)