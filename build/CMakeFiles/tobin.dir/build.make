# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/793/bin/cmake

# The command to remove a file.
RM = /snap/cmake/793/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build

# Include any dependencies generated for this target.
include CMakeFiles/tobin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tobin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tobin.dir/flags.make

CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o: CMakeFiles/tobin.dir/flags.make
CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o: /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o -c /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp

CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp > CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.i

CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp -o CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.s

# Object files for target tobin
tobin_OBJECTS = \
"CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o"

# External object files for target tobin
tobin_EXTERNAL_OBJECTS =

tobin: CMakeFiles/tobin.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/tobin.cpp.o
tobin: CMakeFiles/tobin.dir/build.make
tobin: libmidifile.a
tobin: CMakeFiles/tobin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tobin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tobin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tobin.dir/build: tobin

.PHONY : CMakeFiles/tobin.dir/build

CMakeFiles/tobin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tobin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tobin.dir/clean

CMakeFiles/tobin.dir/depend:
	cd /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles/tobin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tobin.dir/depend

