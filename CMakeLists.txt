cmake_minimum_required(VERSION 3.17)
project(splay_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(splay_tree splay_tree.h node.h splay_tree.cpp main.cpp)