cmake_minimum_required(VERSION 3.29)
project(M5_Assignment1_Burger_static_copy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M5_Assignment1_Burger_static_copy
    burger.cpp
    burger.h
    main.cpp)
