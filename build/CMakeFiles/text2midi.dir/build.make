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
include CMakeFiles/text2midi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/text2midi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text2midi.dir/flags.make

CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o: CMakeFiles/text2midi.dir/flags.make
CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o: /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o -c /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp

CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp > CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.i

CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp -o CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.s

# Object files for target text2midi
text2midi_OBJECTS = \
"CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o"

# External object files for target text2midi
text2midi_EXTERNAL_OBJECTS =

text2midi: CMakeFiles/text2midi.dir/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/tools/text2midi.cpp.o
text2midi: CMakeFiles/text2midi.dir/build.make
text2midi: libmidifile.a
text2midi: CMakeFiles/text2midi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable text2midi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/text2midi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text2midi.dir/build: text2midi

.PHONY : CMakeFiles/text2midi.dir/build

CMakeFiles/text2midi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/text2midi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/text2midi.dir/clean

CMakeFiles/text2midi.dir/depend:
	cd /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build /home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/build/CMakeFiles/text2midi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/text2midi.dir/depend

