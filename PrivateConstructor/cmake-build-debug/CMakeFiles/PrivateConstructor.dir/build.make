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
CMAKE_SOURCE_DIR = /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PrivateConstructor.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PrivateConstructor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrivateConstructor.dir/flags.make

CMakeFiles/PrivateConstructor.dir/main.cpp.o: CMakeFiles/PrivateConstructor.dir/flags.make
CMakeFiles/PrivateConstructor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrivateConstructor.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PrivateConstructor.dir/main.cpp.o -c /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/main.cpp

CMakeFiles/PrivateConstructor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrivateConstructor.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/main.cpp > CMakeFiles/PrivateConstructor.dir/main.cpp.i

CMakeFiles/PrivateConstructor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrivateConstructor.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/main.cpp -o CMakeFiles/PrivateConstructor.dir/main.cpp.s

# Object files for target PrivateConstructor
PrivateConstructor_OBJECTS = \
"CMakeFiles/PrivateConstructor.dir/main.cpp.o"

# External object files for target PrivateConstructor
PrivateConstructor_EXTERNAL_OBJECTS =

PrivateConstructor: CMakeFiles/PrivateConstructor.dir/main.cpp.o
PrivateConstructor: CMakeFiles/PrivateConstructor.dir/build.make
PrivateConstructor: CMakeFiles/PrivateConstructor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrivateConstructor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrivateConstructor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrivateConstructor.dir/build: PrivateConstructor
.PHONY : CMakeFiles/PrivateConstructor.dir/build

CMakeFiles/PrivateConstructor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrivateConstructor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrivateConstructor.dir/clean

CMakeFiles/PrivateConstructor.dir/depend:
	cd /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug /Users/janghyeonjun/Desktop/CPP_Programming/PrivateConstructor/cmake-build-debug/CMakeFiles/PrivateConstructor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PrivateConstructor.dir/depend

