cmake_minimum_required(VERSION 3.29)
project(Algorithm C)

set(CMAKE_C_STANDARD 11)
include_directories(tuto_list)

add_executable(Algorithm Algorithm.c)

add_executable(list_normal
        tuto_list/tuto_list_normal/list_normal.c
        tuto_list/tuto_list_normal/main_list_normal.c)