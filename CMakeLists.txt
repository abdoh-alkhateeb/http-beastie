cmake_minimum_required(VERSION 3.10)
project(beastie)

find_package(Boost REQUIRED)

add_executable(Beast src/main.cpp src/utils.cpp)
target_include_directories(Beast PRIVATE include ${Boost_INCLUDE_DIRS})
