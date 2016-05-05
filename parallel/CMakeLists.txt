cmake_minimum_required (VERSION 2.6)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB parallel_src *.cpp)
file(GLOB parallel_inc *.h)
add_library(parallel ${parallel_src})
file(COPY ${parallel_inc} DESTINATION ${STATIC_LIBRARY_HEADERS_DIR})

set_target_properties(parallel PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${STATIC_LIBRARY_OUTPUT_DIR})

add_subdirectory(parallel_tests)
add_subdirectory(examples)
