cmake_minimum_required(VERSION 3.23)
project(lab3 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab3 main.c sources/student.c headers/student.h sources/compareFunctions.c sources/compareFunctions.h)

include_directories(headers)