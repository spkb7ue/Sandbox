cmake_minimum_required(VERSION 2.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/tests)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(TestUtils TestUtils.cpp)
target_link_libraries(TestUtils  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(TestData TestData.cpp)
target_link_libraries(TestData ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
