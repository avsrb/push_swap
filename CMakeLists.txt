cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libft/)
add_executable(push_swap ./src/main.c ./src/utils.c ./src/validation.c ./src/sort.c ./action/swap.c ./action/rotate.c ./action/reverce_rotate.c ./action/push.c)
target_link_libraries (push_swap ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a)
#add_library(./libft/libft.a)