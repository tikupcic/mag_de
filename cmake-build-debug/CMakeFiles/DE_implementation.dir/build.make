# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Git/mag_de

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Git/mag_de/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DE_implementation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DE_implementation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DE_implementation.dir/flags.make

CMakeFiles/DE_implementation.dir/sources/main.cpp.o: CMakeFiles/DE_implementation.dir/flags.make
CMakeFiles/DE_implementation.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DE_implementation.dir/sources/main.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DE_implementation.dir/sources/main.cpp.o -c /cygdrive/d/Git/mag_de/sources/main.cpp

CMakeFiles/DE_implementation.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DE_implementation.dir/sources/main.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Git/mag_de/sources/main.cpp > CMakeFiles/DE_implementation.dir/sources/main.cpp.i

CMakeFiles/DE_implementation.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DE_implementation.dir/sources/main.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Git/mag_de/sources/main.cpp -o CMakeFiles/DE_implementation.dir/sources/main.cpp.s

CMakeFiles/DE_implementation.dir/sources/main.cpp.o.requires:

.PHONY : CMakeFiles/DE_implementation.dir/sources/main.cpp.o.requires

CMakeFiles/DE_implementation.dir/sources/main.cpp.o.provides: CMakeFiles/DE_implementation.dir/sources/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DE_implementation.dir/build.make CMakeFiles/DE_implementation.dir/sources/main.cpp.o.provides.build
.PHONY : CMakeFiles/DE_implementation.dir/sources/main.cpp.o.provides

CMakeFiles/DE_implementation.dir/sources/main.cpp.o.provides.build: CMakeFiles/DE_implementation.dir/sources/main.cpp.o


CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o: CMakeFiles/DE_implementation.dir/flags.make
CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o: ../sources/DifferentialEvolution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o -c /cygdrive/d/Git/mag_de/sources/DifferentialEvolution.cpp

CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Git/mag_de/sources/DifferentialEvolution.cpp > CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.i

CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Git/mag_de/sources/DifferentialEvolution.cpp -o CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.s

CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.requires:

.PHONY : CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.requires

CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.provides: CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.requires
	$(MAKE) -f CMakeFiles/DE_implementation.dir/build.make CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.provides.build
.PHONY : CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.provides

CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.provides.build: CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o


CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o: CMakeFiles/DE_implementation.dir/flags.make
CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o: ../sources/VectorOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o -c /cygdrive/d/Git/mag_de/sources/VectorOperations.cpp

CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Git/mag_de/sources/VectorOperations.cpp > CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.i

CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Git/mag_de/sources/VectorOperations.cpp -o CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.s

CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.requires:

.PHONY : CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.requires

CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.provides: CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.requires
	$(MAKE) -f CMakeFiles/DE_implementation.dir/build.make CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.provides.build
.PHONY : CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.provides

CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.provides.build: CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o


CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o: CMakeFiles/DE_implementation.dir/flags.make
CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o: ../sources/TrigonometryOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o -c /cygdrive/d/Git/mag_de/sources/TrigonometryOperations.cpp

CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Git/mag_de/sources/TrigonometryOperations.cpp > CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.i

CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Git/mag_de/sources/TrigonometryOperations.cpp -o CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.s

CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.requires:

.PHONY : CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.requires

CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.provides: CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.requires
	$(MAKE) -f CMakeFiles/DE_implementation.dir/build.make CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.provides.build
.PHONY : CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.provides

CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.provides.build: CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o


# Object files for target DE_implementation
DE_implementation_OBJECTS = \
"CMakeFiles/DE_implementation.dir/sources/main.cpp.o" \
"CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o" \
"CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o" \
"CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o"

# External object files for target DE_implementation
DE_implementation_EXTERNAL_OBJECTS =

DE_implementation.exe: CMakeFiles/DE_implementation.dir/sources/main.cpp.o
DE_implementation.exe: CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o
DE_implementation.exe: CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o
DE_implementation.exe: CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o
DE_implementation.exe: CMakeFiles/DE_implementation.dir/build.make
DE_implementation.exe: CMakeFiles/DE_implementation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DE_implementation.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DE_implementation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DE_implementation.dir/build: DE_implementation.exe

.PHONY : CMakeFiles/DE_implementation.dir/build

CMakeFiles/DE_implementation.dir/requires: CMakeFiles/DE_implementation.dir/sources/main.cpp.o.requires
CMakeFiles/DE_implementation.dir/requires: CMakeFiles/DE_implementation.dir/sources/DifferentialEvolution.cpp.o.requires
CMakeFiles/DE_implementation.dir/requires: CMakeFiles/DE_implementation.dir/sources/VectorOperations.cpp.o.requires
CMakeFiles/DE_implementation.dir/requires: CMakeFiles/DE_implementation.dir/sources/TrigonometryOperations.cpp.o.requires

.PHONY : CMakeFiles/DE_implementation.dir/requires

CMakeFiles/DE_implementation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DE_implementation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DE_implementation.dir/clean

CMakeFiles/DE_implementation.dir/depend:
	cd /cygdrive/d/Git/mag_de/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Git/mag_de /cygdrive/d/Git/mag_de /cygdrive/d/Git/mag_de/cmake-build-debug /cygdrive/d/Git/mag_de/cmake-build-debug /cygdrive/d/Git/mag_de/cmake-build-debug/CMakeFiles/DE_implementation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DE_implementation.dir/depend

