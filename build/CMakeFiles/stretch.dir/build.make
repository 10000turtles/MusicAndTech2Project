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
include CMakeFiles/stretch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stretch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stretch.dir/flags.make

CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o: CMakeFiles/stretch.dir/flags.make
CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o: /home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o -c /home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp

CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp > CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.i

CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp -o CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.s

# Object files for target stretch
stretch_OBJECTS = \
"CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o"

# External object files for target stretch
stretch_EXTERNAL_OBJECTS =

stretch: CMakeFiles/stretch.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/stretch.cpp.o
stretch: CMakeFiles/stretch.dir/build.make
stretch: libmidifile.a
stretch: CMakeFiles/stretch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stretch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stretch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stretch.dir/build: stretch

.PHONY : CMakeFiles/stretch.dir/build

CMakeFiles/stretch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stretch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stretch.dir/clean

CMakeFiles/stretch.dir/depend:
	cd /home/oem/Documents/Code/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles/stretch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stretch.dir/depend

