# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/casper/src/saxion/2.3CompOSs/M9Shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/casper/src/saxion/2.3CompOSs/M9Shell/build

# Include any dependencies generated for this target.
include CMakeFiles/outputs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/outputs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/outputs.dir/flags.make

CMakeFiles/outputs.dir/utils/outputs.cpp.o: CMakeFiles/outputs.dir/flags.make
CMakeFiles/outputs.dir/utils/outputs.cpp.o: ../utils/outputs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/outputs.dir/utils/outputs.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/outputs.dir/utils/outputs.cpp.o -c /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/outputs.cpp

CMakeFiles/outputs.dir/utils/outputs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs.dir/utils/outputs.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/outputs.cpp > CMakeFiles/outputs.dir/utils/outputs.cpp.i

CMakeFiles/outputs.dir/utils/outputs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs.dir/utils/outputs.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/outputs.cpp -o CMakeFiles/outputs.dir/utils/outputs.cpp.s

# Object files for target outputs
outputs_OBJECTS = \
"CMakeFiles/outputs.dir/utils/outputs.cpp.o"

# External object files for target outputs
outputs_EXTERNAL_OBJECTS =

outputs: CMakeFiles/outputs.dir/utils/outputs.cpp.o
outputs: CMakeFiles/outputs.dir/build.make
outputs: CMakeFiles/outputs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable outputs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/outputs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/outputs.dir/build: outputs

.PHONY : CMakeFiles/outputs.dir/build

CMakeFiles/outputs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/outputs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/outputs.dir/clean

CMakeFiles/outputs.dir/depend:
	cd /Users/casper/src/saxion/2.3CompOSs/M9Shell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/casper/src/saxion/2.3CompOSs/M9Shell /Users/casper/src/saxion/2.3CompOSs/M9Shell /Users/casper/src/saxion/2.3CompOSs/M9Shell/build /Users/casper/src/saxion/2.3CompOSs/M9Shell/build /Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles/outputs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/outputs.dir/depend

