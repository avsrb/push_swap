cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libft/)
add_executable(push_swap main.c utils.c validation.c ft_libft.c)
target_link_libraries (push_swap ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a)
#add_library(./libft/libft.a)