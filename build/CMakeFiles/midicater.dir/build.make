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
include CMakeFiles/midicater.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/midicater.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/midicater.dir/flags.make

CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o: CMakeFiles/midicater.dir/flags.make
CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o: /home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o -c /home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp

CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp > CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.i

CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp -o CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.s

# Object files for target midicater
midicater_OBJECTS = \
"CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o"

# External object files for target midicater
midicater_EXTERNAL_OBJECTS =

midicater: CMakeFiles/midicater.dir/home/oem/Documents/Code/MusicAndTech2Project/tools/midicater.cpp.o
midicater: CMakeFiles/midicater.dir/build.make
midicater: libmidifile.a
midicater: CMakeFiles/midicater.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable midicater"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/midicater.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/midicater.dir/build: midicater

.PHONY : CMakeFiles/midicater.dir/build

CMakeFiles/midicater.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/midicater.dir/cmake_clean.cmake
.PHONY : CMakeFiles/midicater.dir/clean

CMakeFiles/midicater.dir/depend:
	cd /home/oem/Documents/Code/MusicAndTech2Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/src /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build /home/oem/Documents/Code/MusicAndTech2Project/build/CMakeFiles/midicater.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/midicater.dir/depend

