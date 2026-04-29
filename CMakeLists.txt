cmake_minimum_required(VERSION 3.10)
project(http-beastie)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(include)

add_executable(http-beastie 
    src/main.cpp 
    src/utils.cpp
)

target_link_libraries(http-beastie PRIVATE Boost::system)


