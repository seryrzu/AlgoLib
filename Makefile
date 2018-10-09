# Default build type. Available: Debug, Release
build_type?=Debug

####################
# Check build type #
####################

ifeq ($(build_type), Debug)
    cmake_build_dir:="cmake-build-debug"
else
    ifeq ($(build_type), Release)
        cmake_build_dir:="cmake-build-release"
    else
        $(error Wrong build_type provided $(build_type). Only Debug and Release are supported.)
    endif
endif

################
# Run Makefile #
################

.PHONY: cmake clean check_python_version


all: check_requirenments cmake 


check_requirenments:
	python check_requirements.py


cmake:
	-mkdir ${cmake_build_dir}
	cd ${cmake_build_dir} && cmake .. -DCMAKE_BUILD_TYPE=${build_type}
	ln -sf ${cmake_build_dir}/compile_commands.json .


.tests_generated:
	find test -name 'tests_generator.py' -print0 | xargs -I {} -n 1 -0 python "{}"
	touch .tests_generated


test: all .tests_generated
	$(MAKE) -C ${cmake_build_dir} all
	# $(MAKE) -C ${cmake_build_dir} test
	cd ${cmake_build_dir} && ctest -VV


clean:
	-@rm -r cmake-build-debug 2>/dev/null||:
	-@rm -r cmake-build-release 2>/dev/null||:
	-@rm compile_commands.json 2>/dev/null||:
	-@rm .tests_generated 2>/dev/null||:
	-@rm -r test/sorting/tests 2>/dev/null||:
	-@rm -r test/sorting/tests_filenames.hpp 2>/dev/null||:
