cmake_minimum_required(VERSION 3.29)
project(Algorithm C)

set(CMAKE_C_STANDARD 11)


add_executable(list
        tuto_list/list/list.c
        tuto_list/list/main_list.c
        tuto_list/list/list.h)

add_executable(permutate
        tuto_stack/permutate.c
        tuto_stack/stack_ls/stack_ls.c)

add_executable(stack_sq
        tuto_stack/stack_sq/main_stack_sq.c
        tuto_stack/stack_sq/stack_sq.c)

add_executable(tree_bi
        tuto_tree/tree_bi/tree_bi.c
        tuto_tree/tree_bi/main_tree_bi.c
        tuto_tree/tree_bi/queue_ls/queue_ls.c)

add_executable(queue_ls
        tuto_queue/queue_ls/queue_ls.c
        tuto_queue/queue_ls/main_queue_ls.c)

add_executable(KMP
        tuto_str/KMP.c
        tuto_stack/stack_ls/stack_ls.c)