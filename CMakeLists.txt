cmake_minimum_required(VERSION 3.12)
project(http_beastie LANGUAGES CXX)

# Force C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost REQUIRED)

set(SOURCES
    src/main.cpp
    src/utils.cpp
    include/utils.hpp
)

add_executable(http-beastie ${SOURCES})

target_include_directories(http-beastie PRIVATE 
    include
    ${Boost_INCLUDE_DIRS}
)

# tell CMake to use the C++ not C  linker for this target since it wasnt woking
set_target_properties(http-beastie PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(http-beastie PRIVATE 
    Boost::boost
)
