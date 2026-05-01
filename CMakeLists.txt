cmake_minimum_required(VERSION 3.10)
project(http_beastie)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

include_directories(include ${Boost_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")

add_executable(server ${SOURCES})
target_link_libraries(server Boost::boost)
