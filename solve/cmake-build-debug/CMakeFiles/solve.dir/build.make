# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/janghyeonjun/Desktop/CPP_Programming/solve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/solve.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/solve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/solve.dir/flags.make

CMakeFiles/solve.dir/main.cpp.o: CMakeFiles/solve.dir/flags.make
CMakeFiles/solve.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/solve.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/solve.dir/main.cpp.o -c /Users/janghyeonjun/Desktop/CPP_Programming/solve/main.cpp

CMakeFiles/solve.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solve.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janghyeonjun/Desktop/CPP_Programming/solve/main.cpp > CMakeFiles/solve.dir/main.cpp.i

CMakeFiles/solve.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solve.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janghyeonjun/Desktop/CPP_Programming/solve/main.cpp -o CMakeFiles/solve.dir/main.cpp.s

# Object files for target solve
solve_OBJECTS = \
"CMakeFiles/solve.dir/main.cpp.o"

# External object files for target solve
solve_EXTERNAL_OBJECTS =

solve: CMakeFiles/solve.dir/main.cpp.o
solve: CMakeFiles/solve.dir/build.make
solve: CMakeFiles/solve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable solve"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/solve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/solve.dir/build: solve
.PHONY : CMakeFiles/solve.dir/build

CMakeFiles/solve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/solve.dir/cmake_clean.cmake
.PHONY : CMakeFiles/solve.dir/clean

CMakeFiles/solve.dir/depend:
	cd /Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janghyeonjun/Desktop/CPP_Programming/solve /Users/janghyeonjun/Desktop/CPP_Programming/solve /Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug /Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug /Users/janghyeonjun/Desktop/CPP_Programming/solve/cmake-build-debug/CMakeFiles/solve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/solve.dir/depend

