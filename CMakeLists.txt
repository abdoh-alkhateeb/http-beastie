cmake_minimum_required(VERSION 3.16)

project(http-beastie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(http-beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http-beastie PRIVATE include)

target_compile_definitions(http-beastie PRIVATE
    BOOST_ERROR_CODE_HEADER_ONLY
)

target_link_libraries(http-beastie PRIVATE Threads::Threads)
