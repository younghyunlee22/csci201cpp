cmake_minimum_required(VERSION 3.29)
project(M06_Assignment1_Exception_Handling)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M06_Assignment1_Exception_Handling
    date.cpp
    date.h
    dateExcept.cpp
    dateExcept.h
    main.cpp)
