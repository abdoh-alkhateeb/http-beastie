cmake_minimum_required(VERSION 3.10)

project(http_beastie)

set(CMAKE_CXX_STANDARD 17)



add_executable(http-beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http-beastie PRIVATE include)
