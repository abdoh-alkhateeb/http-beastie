cmake_minimum_required(VERSION 3.15)
project(BeastProject)

set(CMAKE_PREFIX_PATH "/opt/homebrew")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.90.0 REQUIRED OPTIONAL_COMPONENTS system)

add_executable(myapp src/main.cpp src/utils.cpp)
target_include_directories(myapp PUBLIC include)

target_link_libraries(myapp PRIVATE Boost::headers)