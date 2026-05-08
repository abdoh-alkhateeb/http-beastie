cmake_minimum_required(VERSION 3.10)
project(my_app)

add_executable(test src/main.cpp src/utils.cpp)
target_include_directories(test PRIVATE include)
