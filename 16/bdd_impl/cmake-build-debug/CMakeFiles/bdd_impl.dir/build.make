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
CMAKE_SOURCE_DIR = "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bdd_impl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bdd_impl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bdd_impl.dir/flags.make

CMakeFiles/bdd_impl.dir/main.cpp.o: CMakeFiles/bdd_impl.dir/flags.make
CMakeFiles/bdd_impl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bdd_impl.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bdd_impl.dir/main.cpp.o -c "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/main.cpp"

CMakeFiles/bdd_impl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bdd_impl.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/main.cpp" > CMakeFiles/bdd_impl.dir/main.cpp.i

CMakeFiles/bdd_impl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bdd_impl.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/main.cpp" -o CMakeFiles/bdd_impl.dir/main.cpp.s

CMakeFiles/bdd_impl.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/bdd_impl.dir/main.cpp.o.requires

CMakeFiles/bdd_impl.dir/main.cpp.o.provides: CMakeFiles/bdd_impl.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/bdd_impl.dir/build.make CMakeFiles/bdd_impl.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/bdd_impl.dir/main.cpp.o.provides

CMakeFiles/bdd_impl.dir/main.cpp.o.provides.build: CMakeFiles/bdd_impl.dir/main.cpp.o


CMakeFiles/bdd_impl.dir/toyBDD.cpp.o: CMakeFiles/bdd_impl.dir/flags.make
CMakeFiles/bdd_impl.dir/toyBDD.cpp.o: ../toyBDD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bdd_impl.dir/toyBDD.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bdd_impl.dir/toyBDD.cpp.o -c "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/toyBDD.cpp"

CMakeFiles/bdd_impl.dir/toyBDD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bdd_impl.dir/toyBDD.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/toyBDD.cpp" > CMakeFiles/bdd_impl.dir/toyBDD.cpp.i

CMakeFiles/bdd_impl.dir/toyBDD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bdd_impl.dir/toyBDD.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/toyBDD.cpp" -o CMakeFiles/bdd_impl.dir/toyBDD.cpp.s

CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.requires:

.PHONY : CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.requires

CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.provides: CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.requires
	$(MAKE) -f CMakeFiles/bdd_impl.dir/build.make CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.provides.build
.PHONY : CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.provides

CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.provides.build: CMakeFiles/bdd_impl.dir/toyBDD.cpp.o


# Object files for target bdd_impl
bdd_impl_OBJECTS = \
"CMakeFiles/bdd_impl.dir/main.cpp.o" \
"CMakeFiles/bdd_impl.dir/toyBDD.cpp.o"

# External object files for target bdd_impl
bdd_impl_EXTERNAL_OBJECTS =

bdd_impl: CMakeFiles/bdd_impl.dir/main.cpp.o
bdd_impl: CMakeFiles/bdd_impl.dir/toyBDD.cpp.o
bdd_impl: CMakeFiles/bdd_impl.dir/build.make
bdd_impl: CMakeFiles/bdd_impl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bdd_impl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bdd_impl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bdd_impl.dir/build: bdd_impl

.PHONY : CMakeFiles/bdd_impl.dir/build

CMakeFiles/bdd_impl.dir/requires: CMakeFiles/bdd_impl.dir/main.cpp.o.requires
CMakeFiles/bdd_impl.dir/requires: CMakeFiles/bdd_impl.dir/toyBDD.cpp.o.requires

.PHONY : CMakeFiles/bdd_impl.dir/requires

CMakeFiles/bdd_impl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bdd_impl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bdd_impl.dir/clean

CMakeFiles/bdd_impl.dir/depend:
	cd "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug" "/home/kirill/University/HSE/Algo/2 semestr/Homeworks/16/bdd_impl/cmake-build-debug/CMakeFiles/bdd_impl.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bdd_impl.dir/depend

