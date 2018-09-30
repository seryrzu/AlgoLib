cmake_minimum_required(VERSION 3.9)
project(AlgoLib CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/bin)

set(CMAKE_CXX_STANDARD 17)

set(ALGORITHMS_MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_DIR "${ALGORITHMS_MAIN_DIR}/lib")
set(EXT_DIR "${ALGORITHMS_MAIN_DIR}/ext")
set(TEST_DIR "${ALGORITHMS_MAIN_DIR}/test")

add_subdirectory("${EXT_DIR}")
add_subdirectory("${TEST_DIR}")


add_library(AlgoLib INTERFACE)
target_include_directories(AlgoLib INTERFACE ${LIB_DIR})