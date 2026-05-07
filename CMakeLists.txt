cmake_minimum_required(VERSION 3.21) 
project(boost)

add_executable(main ./src/main.cpp ./src/utils.cpp)
target_include_directories(main PRIVATE include)