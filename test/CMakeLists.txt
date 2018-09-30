project(tests)

link_libraries(gtest gtest_main AlgoLib)

add_executable(test_test test.cpp)
target_link_libraries(test_test AlgoLib)

add_subdirectory(sorting)