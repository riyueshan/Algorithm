cmake_minimum_required(VERSION 3.29)
project(Algorithm C)

set(CMAKE_C_STANDARD 11)
include_directories(tuto_list)
include_directories(tuto_stack)
include_directories(tuto_queue)
include_directories(tuto_tree)
include_directories(tuto_str)

add_executable(list_normal
        tuto_list/tuto_list_normal/list_normal.c
        tuto_list/tuto_list_normal/main_list_normal.c)

add_executable(permutate
        tuto_stack/stack_list/stack_list.c
        tuto_stack/main_permutate.c)

add_executable(stack_sq
        tuto_stack/stack_sq/stack_sq.c
        tuto_stack/stack_sq/stack_sq.h
        tuto_stack/stack_sq/main_stack_sq.c)

add_executable(tree_bi
        tuto_tree/tree_bi/tree_bi.c)

add_executable(queue_list
        tuto_queue/queue_list/queue_list.c)

add_executable(KMP
        tuto_str/KMP.c)