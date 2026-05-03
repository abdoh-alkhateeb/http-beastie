cmake_minimum_required(VERSION 3.21)
project(http_beastie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_executable(http_beastie src/main.cpp src/utils.cpp)

target_include_directories(http_beastie PRIVATE
 include #{Boost_INCLUDE_DIRS}
)
