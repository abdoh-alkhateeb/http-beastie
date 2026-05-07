cmake_minimum_required(VERSION 3.10)
project (BeastieProject)

find_package (Boost REQUIRED)

add_executable (beastie src/main.cpp src/utils.cpp)

target_include_directories(beastie PRIVATE include)
target_link_libraries (beastie PRIVATE Boost::boost)
