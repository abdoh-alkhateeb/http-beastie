cmake_minimum_required(VERSION 3.16)

project(http_beastie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

add_executable(http_beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http_beastie PRIVATE include)

target_link_libraries(http_beastie PRIVATE Boost::system Threads::Threads)
