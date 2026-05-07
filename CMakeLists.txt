
cmake_minimum_required(VERSION 3.21)
project(app)

add_executable(app src/main.cpp src/utils.cpp include/utils.hpp)
target_include_directories(app PRIVATE include)
