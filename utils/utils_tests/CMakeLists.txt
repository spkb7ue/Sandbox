cmake_minimum_required(VERSION 2.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/tests)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(TestUtils TestUtils.cpp)
add_test(TestLock ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestUtils)
target_link_libraries(TestUtils
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
