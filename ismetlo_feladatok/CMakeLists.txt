cmake_minimum_required(VERSION 3.23)
project(ismetlo_feladatok C)

set(CMAKE_C_STANDARD 23)

add_executable(ismetlo_feladatok main.c sources/patient.c headers/patient.h)

include_directories(headers)