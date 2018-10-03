add_definitions(-Wall -Wextra -Wconversion -Wno-sign-conversion -Wno-long-long -Wwrite-strings)
add_definitions(-Wall
                -Wextra
                -Wshadow
                -Wformat=2
                -Wfloat-equal
                -Wconversion
                -Wno-sign-conversion
                -Wno-long-long
                -Wwrite-strings)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message("Making Debug Configuration...")

    add_definitions(-g3)
    add_definitions(-D_GLIBCXX_DEBUG)
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
    message("Making Release Configuration...")

    add_definitions(-g0)
    add_definitions(-O2)
endif()
