cmake_minimum_required(VERSION 3.21) 
project(boost)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

add_library(utilities STATIC ./src/utils.cpp)
target_include_directories(utilities PRIVATE ./include)
add_executable(main ./src/main.cpp)
target_include_directories(main PRIVATE ./include)
target_link_libraries(main PRIVATE utilities)

enable_testing()

add_executable(util_test tests.cpp)
target_link_libraries(util_test PRIVATE utilities GTest::gtest_main)
target_include_directories(util_test PRIVATE ./include)

include(GoogleTest)
gtest_discover_tests(util_test)