cmake_minimum_required(VERSION 3.14)
project(csce1102_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS} include)

add_executable(server
    src/main.cpp
    src/utils.cpp
)

target_link_libraries(server
    Boost::system
)

file(COPY static DESTINATION ${CMAKE_BINARY_DIR})