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
CMAKE_SOURCE_DIR = /home/oem/Documents/Code/MusicAndTech2Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oem/Documents/Code/MusicAndTech2Project/build

# Include any dependencies generated for this target.
include CMakeFiles/midi2skini.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/midi2skini.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/midi2skini.dir/flags.make

CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o: CMakeFiles/midi2skini.dir/flags.make
CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o: /home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o -c /home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp

CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp > CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.i

CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp -o CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.s

# Object files for target midi2skini
midi2skini_OBJECTS = \
"CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o"

# External object files for target midi2skini
midi2skini_EXTERNAL_OBJECTS =

midi2skini: CMakeFiles/midi2skini.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midi2skini.cpp.o
midi2skini: CMakeFiles/midi2skini.dir/build.make
midi2skini: libmidifile.a
midi2skini: CMakeFiles/midi2skini.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable midi2skini"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/midi2skini.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/midi2skini.dir/build: midi2skini

.PHONY : CMakeFiles/midi2skini.dir/build

CMakeFiles/midi2skini.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/midi2skini.dir/cmake_clean.cmake
.PHONY : CMakeFiles/midi2skini.dir/clean

CMakeFiles/midi2skini.dir/depend:
	cd /home/oem/Documents/Code/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles/midi2skini.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/midi2skini.dir/depend

