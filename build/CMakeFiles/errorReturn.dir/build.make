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
include CMakeFiles/errorReturn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/errorReturn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/errorReturn.dir/flags.make

CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o: CMakeFiles/errorReturn.dir/flags.make
CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o: ../utils/errorReturn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o -c /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/errorReturn.cpp

CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/errorReturn.cpp > CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.i

CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/casper/src/saxion/2.3CompOSs/M9Shell/utils/errorReturn.cpp -o CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.s

# Object files for target errorReturn
errorReturn_OBJECTS = \
"CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o"

# External object files for target errorReturn
errorReturn_EXTERNAL_OBJECTS =

errorReturn: CMakeFiles/errorReturn.dir/utils/errorReturn.cpp.o
errorReturn: CMakeFiles/errorReturn.dir/build.make
errorReturn: CMakeFiles/errorReturn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable errorReturn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/errorReturn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/errorReturn.dir/build: errorReturn

.PHONY : CMakeFiles/errorReturn.dir/build

CMakeFiles/errorReturn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/errorReturn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/errorReturn.dir/clean

CMakeFiles/errorReturn.dir/depend:
	cd /Users/casper/src/saxion/2.3CompOSs/M9Shell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/casper/src/saxion/2.3CompOSs/M9Shell /Users/casper/src/saxion/2.3CompOSs/M9Shell /Users/casper/src/saxion/2.3CompOSs/M9Shell/build /Users/casper/src/saxion/2.3CompOSs/M9Shell/build /Users/casper/src/saxion/2.3CompOSs/M9Shell/build/CMakeFiles/errorReturn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/errorReturn.dir/depend

