cmake_minimum_required(VERSION 3.21)
project(Assigment)
add_executable(server src/main.cpp src/utils.cpp)
target_include_directories(server PUBLIC include)
