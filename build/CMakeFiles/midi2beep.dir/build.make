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
CMAKE_COMMAND = /snap/cmake/805/bin/cmake

# The command to remove a file.
RM = /snap/cmake/805/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build

# Include any dependencies generated for this target.
include CMakeFiles/midi2beep.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/midi2beep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/midi2beep.dir/flags.make

CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o: CMakeFiles/midi2beep.dir/flags.make
CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o: /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o -c /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp

CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp > CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.i

CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp -o CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.s

# Object files for target midi2beep
midi2beep_OBJECTS = \
"CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o"

# External object files for target midi2beep
midi2beep_EXTERNAL_OBJECTS =

midi2beep: CMakeFiles/midi2beep.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/midi2beep.cpp.o
midi2beep: CMakeFiles/midi2beep.dir/build.make
midi2beep: libmidifile.a
midi2beep: CMakeFiles/midi2beep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable midi2beep"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/midi2beep.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/midi2beep.dir/build: midi2beep

.PHONY : CMakeFiles/midi2beep.dir/build

CMakeFiles/midi2beep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/midi2beep.dir/cmake_clean.cmake
.PHONY : CMakeFiles/midi2beep.dir/clean

CMakeFiles/midi2beep.dir/depend:
	cd /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles/midi2beep.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/midi2beep.dir/depend

