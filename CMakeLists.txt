cmake_minimum_required(VERSION 3.24)
project(c_2022_2_allocator C)

set(CMAKE_C_STANDARD 11)

add_executable(c_2022_2_allocator main.c allocator.h allocator.c)
