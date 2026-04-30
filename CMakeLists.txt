cmake_minimum_required(VERSION 3.10)
project(assignment3)

find_package(Boost REQUIRED)

add_executable(app
	src/main.cpp
	src/utils.cpp)
target_include_directories(app PRIVATE
	 ${Boost_INCLUDE_DIRS}
	 ${CMAKE_CURRENT_SOURCE_DIR}/include)
