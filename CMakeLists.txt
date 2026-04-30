cmake_minimum_required(VERSION 3.16)

project(http-beastie LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Avoid mixing MinGW Boost headers with MSVC on this machine.
if (WIN32 AND EXISTS "C:/boost_1_66_0/boost/asio.hpp")
  set(BOOST_INCLUDE_DIR "C:/boost_1_66_0")
else()
  set(Boost_NO_BOOST_CMAKE ON)
  find_package(Boost REQUIRED)
  set(BOOST_INCLUDE_DIR "${Boost_INCLUDE_DIRS}")
endif()

add_executable(http-beastie
  src/main.cpp
  src/utils.cpp
)

target_include_directories(http-beastie PRIVATE include ${BOOST_INCLUDE_DIR})
target_compile_definitions(http-beastie PRIVATE
  BOOST_ALL_NO_LIB
  BOOST_SYSTEM_NO_LIB
  BOOST_ERROR_CODE_HEADER_ONLY
)

if (WIN32)
  target_link_libraries(http-beastie PRIVATE ws2_32 mswsock)
endif()
