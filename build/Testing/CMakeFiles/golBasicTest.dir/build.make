# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/PHAS0100Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/PHAS0100Assignment1/build

# Include any dependencies generated for this target.
include Testing/CMakeFiles/golBasicTest.dir/depend.make

# Include the progress variables for this target.
include Testing/CMakeFiles/golBasicTest.dir/progress.make

# Include the compile flags for this target's objects.
include Testing/CMakeFiles/golBasicTest.dir/flags.make

Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o: Testing/CMakeFiles/golBasicTest.dir/flags.make
Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o: ../Testing/golBasicTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/PHAS0100Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o -c /workspaces/PHAS0100Assignment1/Testing/golBasicTest.cpp

Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/golBasicTest.dir/golBasicTest.cpp.i"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/PHAS0100Assignment1/Testing/golBasicTest.cpp > CMakeFiles/golBasicTest.dir/golBasicTest.cpp.i

Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/golBasicTest.dir/golBasicTest.cpp.s"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/PHAS0100Assignment1/Testing/golBasicTest.cpp -o CMakeFiles/golBasicTest.dir/golBasicTest.cpp.s

Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o: Testing/CMakeFiles/golBasicTest.dir/flags.make
Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o: ../Testing/golCatchMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/PHAS0100Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o -c /workspaces/PHAS0100Assignment1/Testing/golCatchMain.cpp

Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/golBasicTest.dir/golCatchMain.cpp.i"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/PHAS0100Assignment1/Testing/golCatchMain.cpp > CMakeFiles/golBasicTest.dir/golCatchMain.cpp.i

Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/golBasicTest.dir/golCatchMain.cpp.s"
	cd /workspaces/PHAS0100Assignment1/build/Testing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/PHAS0100Assignment1/Testing/golCatchMain.cpp -o CMakeFiles/golBasicTest.dir/golCatchMain.cpp.s

# Object files for target golBasicTest
golBasicTest_OBJECTS = \
"CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o" \
"CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o"

# External object files for target golBasicTest
golBasicTest_EXTERNAL_OBJECTS =

bin/golBasicTest: Testing/CMakeFiles/golBasicTest.dir/golBasicTest.cpp.o
bin/golBasicTest: Testing/CMakeFiles/golBasicTest.dir/golCatchMain.cpp.o
bin/golBasicTest: Testing/CMakeFiles/golBasicTest.dir/build.make
bin/golBasicTest: bin/libPHAS0100ASSIGNMENT1.a
bin/golBasicTest: Testing/CMakeFiles/golBasicTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/PHAS0100Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/golBasicTest"
	cd /workspaces/PHAS0100Assignment1/build/Testing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/golBasicTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Testing/CMakeFiles/golBasicTest.dir/build: bin/golBasicTest

.PHONY : Testing/CMakeFiles/golBasicTest.dir/build

Testing/CMakeFiles/golBasicTest.dir/clean:
	cd /workspaces/PHAS0100Assignment1/build/Testing && $(CMAKE_COMMAND) -P CMakeFiles/golBasicTest.dir/cmake_clean.cmake
.PHONY : Testing/CMakeFiles/golBasicTest.dir/clean

Testing/CMakeFiles/golBasicTest.dir/depend:
	cd /workspaces/PHAS0100Assignment1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/PHAS0100Assignment1 /workspaces/PHAS0100Assignment1/Testing /workspaces/PHAS0100Assignment1/build /workspaces/PHAS0100Assignment1/build/Testing /workspaces/PHAS0100Assignment1/build/Testing/CMakeFiles/golBasicTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Testing/CMakeFiles/golBasicTest.dir/depend
