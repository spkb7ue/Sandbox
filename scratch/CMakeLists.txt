cmake_minimum_required (VERSION 2.6)

project(Scratch C CXX)
#file(GLOB scratch_src "${SCRATCH_SOURCE_DIR}" *.cpp)
add_executable(scratch thread_ex.cpp)
target_link_libraries(scratch pthread)
