include(CTest)

enable_testing()

set(TEST_LIBRARIES gmock_main gtest gmock)
set(TEST_COMMAND_ARGS --gtest_color=yes)

function(make_test test)
    if (NOT TARGET ${test})
        add_executable(${test} ${ARGN})
        target_link_libraries(${test} ${TEST_LIBRARIES})
        add_test(NAME ${test}
                COMMAND ${test} ${TEST_COMMAND_ARGS})
    endif(NOT TARGET ${test})
endfunction(make_test)