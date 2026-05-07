cmake_minimum_required(VERSION 3.17) 
project(Proj)

find_package(Boost REQUIRED)
add_executable(Assignment3 src/main.cpp src/utils.cpp include/utils.hpp)
target_include_directories(Assignment3 PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include ) 
