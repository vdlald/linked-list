cmake_minimum_required(VERSION 3.16)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linked_list main.cpp LinkedList.cpp LinkedList.h List.h Vectorable.h)
