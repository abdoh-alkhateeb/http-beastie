cmake_minimum_required(VERSION 3.16)

project(http-beastie LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(Boost REQUIRED COMPONENTS system)

add_executable(http-beastie
    src/main.cpp
    src/utils.cpp
)

target_include_directories(http-beastie PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(http-beastie PRIVATE
    Boost::system
    pthread
)

add_custom_command(
    TARGET http-beastie POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/static
            ${CMAKE_BINARY_DIR}/static
)
