cmake_minimum_required(VERSION 3.10)
project(HttpServer LANGUAGES CXX)

find_package(Boost REQUIRED)

add_executable(server
    src/main.cpp
    src/utils.cpp
)

target_include_directories(server PRIVATE include ${Boost_INCLUDE_DIRS})
target_link_libraries(server PRIVATE ${Boost_LIBRARIES})
target_compile_features(server PRIVATE cxx_std_17)
