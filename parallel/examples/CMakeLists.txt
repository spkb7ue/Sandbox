cmake_minimum_required (VERSION 2.6)

include_directories(${STATIC_LIBRARY_HEADERS_DIR})
add_executable(ExProducerConsumer ExProducerConsumer.cpp)
add_executable(FlagsCompareSpeed FlagsCompareSpeed.cpp)