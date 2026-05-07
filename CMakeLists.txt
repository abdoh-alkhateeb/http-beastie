cmake_minimum_required(VERSION 3.16)

project(http-beastie)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(http-beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http-beastie PRIVATE include)

target_link_libraries(http-beastie PRIVATE
    Boost::system
    pthread
)

file(COPY static DESTINATION ${CMAKE_BINARY_DIR})
