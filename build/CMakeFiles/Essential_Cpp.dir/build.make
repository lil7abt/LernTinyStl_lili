# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lili/Documents/LernTinyStl_lili/build

# Include any dependencies generated for this target.
include CMakeFiles/Essential_Cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Essential_Cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Essential_Cpp.dir/flags.make

CMakeFiles/Essential_Cpp.dir/hello.cpp.o: CMakeFiles/Essential_Cpp.dir/flags.make
CMakeFiles/Essential_Cpp.dir/hello.cpp.o: /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lili/Documents/LernTinyStl_lili/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Essential_Cpp.dir/hello.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Essential_Cpp.dir/hello.cpp.o -c /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics/hello.cpp

CMakeFiles/Essential_Cpp.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Essential_Cpp.dir/hello.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics/hello.cpp > CMakeFiles/Essential_Cpp.dir/hello.cpp.i

CMakeFiles/Essential_Cpp.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Essential_Cpp.dir/hello.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics/hello.cpp -o CMakeFiles/Essential_Cpp.dir/hello.cpp.s

# Object files for target Essential_Cpp
Essential_Cpp_OBJECTS = \
"CMakeFiles/Essential_Cpp.dir/hello.cpp.o"

# External object files for target Essential_Cpp
Essential_Cpp_EXTERNAL_OBJECTS =

Essential_Cpp: CMakeFiles/Essential_Cpp.dir/hello.cpp.o
Essential_Cpp: CMakeFiles/Essential_Cpp.dir/build.make
Essential_Cpp: CMakeFiles/Essential_Cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lili/Documents/LernTinyStl_lili/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Essential_Cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Essential_Cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Essential_Cpp.dir/build: Essential_Cpp

.PHONY : CMakeFiles/Essential_Cpp.dir/build

CMakeFiles/Essential_Cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Essential_Cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Essential_Cpp.dir/clean

CMakeFiles/Essential_Cpp.dir/depend:
	cd /Users/lili/Documents/LernTinyStl_lili/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics /Users/lili/Documents/LernTinyStl_lili/Essential_Cpp/K1_Basics /Users/lili/Documents/LernTinyStl_lili/build /Users/lili/Documents/LernTinyStl_lili/build /Users/lili/Documents/LernTinyStl_lili/build/CMakeFiles/Essential_Cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Essential_Cpp.dir/depend
