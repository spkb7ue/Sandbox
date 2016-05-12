cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/tests)

add_executable(TestNode TestNode.cpp)
add_test(TestNode ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestNode)

add_executable(TestTree TestTree.cpp)
add_test(TestTree ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestTree)

add_executable(TestBTree TestBTree.cpp)
add_test(TestBTree ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestBTree)

target_link_libraries(TestNode ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(TestTree ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(TestBTree  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
