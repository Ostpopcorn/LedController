cmake_minimum_required(VERSION 3.16)
project(led_matrix_control)

set(CMAKE_CXX_STANDARD 17)

add_executable(led_matrix_control main.cpp led.cpp led.h)
