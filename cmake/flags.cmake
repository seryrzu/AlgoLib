add_definitions(-Wall
                -Wextra
                -pedantic
                -Wshadow
                -Wformat=2
                -Wuninitialized -Winit-self
                -Wmissing-include-dirs
                -Wswitch-default
                -Wswitch-enum
                -Wunused
                -Wstrict-overflow=5
                -Wfloat-equal
                -Wcast-qual
                -Wcast-align
                -Wconversion
                -Wsign-conversion
                -Wmissing-declarations
                -Wmissing-noreturn
                -Wunreachable-code
                -Winline
                -Wdisabled-optimization)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message("Making Debug Configuration")

    add_definitions(-g3)
    add_definitions(-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC)
    add_definitions(-fsanitize=address)
    add_definitions(-fsanitize=undefined)
    add_definitions(-fno-sanitize-recover=all)

    SET(GCC_COVERAGE_LINK_FLAGS  "-fsanitize=address")
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    message("Making Release Configuration")

    add_definitions(-g0)
    add_definitions(-O2)
endif()
