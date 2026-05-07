cmake_minimum_required(VERSION 3.10)
project(http_beastie)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(include)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(http_beastie ${SOURCES})

target_link_libraries(http_beastie PRIVATE Boost::system pthread)