cmake_minimum_required (VERSION 2.6)

project(Olympus C CXX)

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread")
endif()

set(CMAKE_BUILD_TYPE debug)
set(STATIC_LIBRARY_OUTPUT_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
set(STATIC_LIBRARY_HEADERS_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/include)
set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest-1.7.0/include)
set(GTEST_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gtest-1.7.0/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)

enable_testing()

find_package(Boost)
find_package(Threads)

add_subdirectory(container)
add_subdirectory(parallel)
add_subdirectory(scratch)
