# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build

# Include any dependencies generated for this target.
include CMakeFiles/bubble-sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bubble-sort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bubble-sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bubble-sort.dir/flags.make

CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o: CMakeFiles/bubble-sort.dir/flags.make
CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o: ../bubble-sort.cpp
CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o: CMakeFiles/bubble-sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o -MF CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o.d -o CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o -c /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/bubble-sort.cpp

CMakeFiles/bubble-sort.dir/bubble-sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bubble-sort.dir/bubble-sort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/bubble-sort.cpp > CMakeFiles/bubble-sort.dir/bubble-sort.cpp.i

CMakeFiles/bubble-sort.dir/bubble-sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bubble-sort.dir/bubble-sort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/bubble-sort.cpp -o CMakeFiles/bubble-sort.dir/bubble-sort.cpp.s

# Object files for target bubble-sort
bubble__sort_OBJECTS = \
"CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o"

# External object files for target bubble-sort
bubble__sort_EXTERNAL_OBJECTS =

bubble-sort: CMakeFiles/bubble-sort.dir/bubble-sort.cpp.o
bubble-sort: CMakeFiles/bubble-sort.dir/build.make
bubble-sort: CMakeFiles/bubble-sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bubble-sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bubble-sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bubble-sort.dir/build: bubble-sort
.PHONY : CMakeFiles/bubble-sort.dir/build

CMakeFiles/bubble-sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bubble-sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bubble-sort.dir/clean

CMakeFiles/bubble-sort.dir/depend:
	cd /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build /workspaces/SYDE223/DSA/9_SortingAlgos/BubbleSort/build/CMakeFiles/bubble-sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bubble-sort.dir/depend
