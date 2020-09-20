cmake_minimum_required(VERSION 3.17)
project(splay_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(splay_tree tree/splay_tree.h tree/node.h tree/splay_tree.cpp main.cpp)