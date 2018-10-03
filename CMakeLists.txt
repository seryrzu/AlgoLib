cmake_minimum_required(VERSION 3.9)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(prevent_in_source_builds)

###################
project(AlgoLib CXX)

set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/bin)
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cmake-release-debug/bin)
endif()

include(check)
include(compiler_deps)
include(libs)

set(ALGORITHMS_MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR "${ALGORITHMS_MAIN_DIR}/src")
set(EXT_DIR "${ALGORITHMS_MAIN_DIR}/ext")
set(TEST_DIR "${ALGORITHMS_MAIN_DIR}/test")

add_subdirectory("${EXT_DIR}")
add_subdirectory("${TEST_DIR}")


add_library(AlgoLib INTERFACE)
target_include_directories(AlgoLib INTERFACE ${SRC_DIR})
