function(check_in_source_build)
    get_filename_component(src "${CMAKE_SOURCE_DIR}" REALPATH)
    get_filename_component(bin "${CMAKE_BINARY_DIR}" REALPATH)

    if("${src}" STREQUAL "${bin}")
        message("CMake should not be used to build in the source directory")
        message("Please use Makefile in the root folder to build and run the code")
        message("CMake already created some files in the root dir (probably CMakeCache.txt and CMakeFiles/)")
        message("You can check with 'git status' command and remove them")
        message(FATAL_ERROR "Exiting")
    endif()
endfunction()

check_in_source_build()