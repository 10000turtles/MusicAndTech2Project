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
include CMakeFiles/retick.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/retick.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/retick.dir/flags.make

CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o: CMakeFiles/retick.dir/flags.make
CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o: /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o -c /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp

CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp > CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.i

CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp -o CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.s

# Object files for target retick
retick_OBJECTS = \
"CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o"

# External object files for target retick
retick_EXTERNAL_OBJECTS =

retick: CMakeFiles/retick.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/retick.cpp.o
retick: CMakeFiles/retick.dir/build.make
retick: libmidifile.a
retick: CMakeFiles/retick.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable retick"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/retick.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/retick.dir/build: retick

.PHONY : CMakeFiles/retick.dir/build

CMakeFiles/retick.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/retick.dir/cmake_clean.cmake
.PHONY : CMakeFiles/retick.dir/clean

CMakeFiles/retick.dir/depend:
	cd /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles/retick.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/retick.dir/depend

