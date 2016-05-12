cmake_minimum_required(VERSION 2.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/tests)
include_directories(${GTEST_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

add_executable(TestLock TestLock.cpp)
add_test(TestLock ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestLock)
target_link_libraries(TestLock
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${STATIC_LIBRARY_OUTPUT_DIR}/libparallel.a)

add_executable(TestDCTree TestDCTree.cpp)
add_test(TestDCTree ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestDCTree)
target_link_libraries(TestDCTree
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(TestSyncObject TestSyncObject.cpp)
add_test(TestSyncObject ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestSyncObject)
target_link_libraries(TestSyncObject
                      ${GTEST_LIB_DIR}/libgtest.a
                      ${GTEST_LIB_DIR}/libgtest_main.a
                      pthread
                      ${STATIC_LIBRARY_OUTPUT_DIR}/libparallel.a)
