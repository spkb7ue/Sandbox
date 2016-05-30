cmake_minimum_required (VERSION 2.6)

project(Olympus C CXX)

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

set(CMAKE_BUILD_TYPE release)
set(STATIC_LIBRARY_OUTPUT_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
set(STATIC_LIBRARY_HEADERS_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
file(COPY runTests DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

enable_testing()

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
add_definitions(-DBOOST_TEST_DYN_LINK)
find_package(Threads)

add_subdirectory(container)
add_subdirectory(parallel)
add_subdirectory(scratch)
