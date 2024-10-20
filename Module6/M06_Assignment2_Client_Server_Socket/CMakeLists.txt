cmake_minimum_required(VERSION 3.29)
project(socket)

set(CMAKE_CXX_STANDARD 17)

add_executable(client client.cpp)
add_executable(server server.cpp)
