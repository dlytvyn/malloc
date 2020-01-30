cmake_minimum_required(VERSION 3.14)
project(malloc-final-printf C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc-final-printf main.c sources/free.c sources/malloc.c sources/malloc_add.c
        sources/realloc.c sources/show_alloc_mem.c)

target_link_libraries(malloc-final-printf ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a)