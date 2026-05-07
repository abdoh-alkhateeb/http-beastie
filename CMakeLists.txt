cmake_minimum_required(VERSION 3.10)
project(http_beastie)

find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

add_executable(http-beastie src/main.cpp src/utils.cpp)

target_include_directories(http-beastie PRIVATE include ${Boost_INCLUDE_DIRS})
target_link_libraries(http-beastie PRIVATE Threads::Threads)
