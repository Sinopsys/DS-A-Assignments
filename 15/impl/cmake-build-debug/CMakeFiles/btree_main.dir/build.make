# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/kirill/Soft/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kirill/Soft/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/btree_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/btree_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btree_main.dir/flags.make

CMakeFiles/btree_main.dir/main.cpp.o: CMakeFiles/btree_main.dir/flags.make
CMakeFiles/btree_main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/btree_main.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/btree_main.dir/main.cpp.o -c "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/main.cpp"

CMakeFiles/btree_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree_main.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/main.cpp" > CMakeFiles/btree_main.dir/main.cpp.i

CMakeFiles/btree_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree_main.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/main.cpp" -o CMakeFiles/btree_main.dir/main.cpp.s

CMakeFiles/btree_main.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/btree_main.dir/main.cpp.o.requires

CMakeFiles/btree_main.dir/main.cpp.o.provides: CMakeFiles/btree_main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/btree_main.dir/build.make CMakeFiles/btree_main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/btree_main.dir/main.cpp.o.provides

CMakeFiles/btree_main.dir/main.cpp.o.provides.build: CMakeFiles/btree_main.dir/main.cpp.o


CMakeFiles/btree_main.dir/btree.cpp.o: CMakeFiles/btree_main.dir/flags.make
CMakeFiles/btree_main.dir/btree.cpp.o: ../btree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/btree_main.dir/btree.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/btree_main.dir/btree.cpp.o -c "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/btree.cpp"

CMakeFiles/btree_main.dir/btree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree_main.dir/btree.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/btree.cpp" > CMakeFiles/btree_main.dir/btree.cpp.i

CMakeFiles/btree_main.dir/btree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree_main.dir/btree.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/btree.cpp" -o CMakeFiles/btree_main.dir/btree.cpp.s

CMakeFiles/btree_main.dir/btree.cpp.o.requires:

.PHONY : CMakeFiles/btree_main.dir/btree.cpp.o.requires

CMakeFiles/btree_main.dir/btree.cpp.o.provides: CMakeFiles/btree_main.dir/btree.cpp.o.requires
	$(MAKE) -f CMakeFiles/btree_main.dir/build.make CMakeFiles/btree_main.dir/btree.cpp.o.provides.build
.PHONY : CMakeFiles/btree_main.dir/btree.cpp.o.provides

CMakeFiles/btree_main.dir/btree.cpp.o.provides.build: CMakeFiles/btree_main.dir/btree.cpp.o


# Object files for target btree_main
btree_main_OBJECTS = \
"CMakeFiles/btree_main.dir/main.cpp.o" \
"CMakeFiles/btree_main.dir/btree.cpp.o"

# External object files for target btree_main
btree_main_EXTERNAL_OBJECTS =

btree_main: CMakeFiles/btree_main.dir/main.cpp.o
btree_main: CMakeFiles/btree_main.dir/btree.cpp.o
btree_main: CMakeFiles/btree_main.dir/build.make
btree_main: CMakeFiles/btree_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable btree_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/btree_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btree_main.dir/build: btree_main

.PHONY : CMakeFiles/btree_main.dir/build

CMakeFiles/btree_main.dir/requires: CMakeFiles/btree_main.dir/main.cpp.o.requires
CMakeFiles/btree_main.dir/requires: CMakeFiles/btree_main.dir/btree.cpp.o.requires

.PHONY : CMakeFiles/btree_main.dir/requires

CMakeFiles/btree_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/btree_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/btree_main.dir/clean

CMakeFiles/btree_main.dir/depend:
	cd "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/15/impl/cmake-build-debug/CMakeFiles/btree_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/btree_main.dir/depend

