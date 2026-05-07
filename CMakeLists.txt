cmake_minimum_required(VERSION 3.10)

project(http_beastie)


find_package(Boost REQUIRED COMPONENTS filesystem)

add_executable(http_beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http_beastie PRIVATE include)

target_link_libraries(http_beastie Boost::filesystem)

