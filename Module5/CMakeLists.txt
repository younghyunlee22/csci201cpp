cmake_minimum_required(VERSION 3.29)
project(Module5)

set(CMAKE_CXX_STANDARD 14)

include_directories(M5_Assignment1_Burger_static)

add_executable(Module5
    M5_Assignment1_Burger_static/burger.cpp
    M5_Assignment1_Burger_static/burger.h
    M5_Assignment1_Burger_static/main.cpp)
