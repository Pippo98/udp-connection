# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/filippo/github/udp-connection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filippo/github/udp-connection/build

# Include any dependencies generated for this target.
include CMakeFiles/udp_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/udp_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_shared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_shared.dir/flags.make

CMakeFiles/udp_shared.dir/udp.c.o: CMakeFiles/udp_shared.dir/flags.make
CMakeFiles/udp_shared.dir/udp.c.o: ../udp.c
CMakeFiles/udp_shared.dir/udp.c.o: CMakeFiles/udp_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filippo/github/udp-connection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/udp_shared.dir/udp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/udp_shared.dir/udp.c.o -MF CMakeFiles/udp_shared.dir/udp.c.o.d -o CMakeFiles/udp_shared.dir/udp.c.o -c /home/filippo/github/udp-connection/udp.c

CMakeFiles/udp_shared.dir/udp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_shared.dir/udp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/filippo/github/udp-connection/udp.c > CMakeFiles/udp_shared.dir/udp.c.i

CMakeFiles/udp_shared.dir/udp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_shared.dir/udp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/filippo/github/udp-connection/udp.c -o CMakeFiles/udp_shared.dir/udp.c.s

# Object files for target udp_shared
udp_shared_OBJECTS = \
"CMakeFiles/udp_shared.dir/udp.c.o"

# External object files for target udp_shared
udp_shared_EXTERNAL_OBJECTS =

libudp_shared.so: CMakeFiles/udp_shared.dir/udp.c.o
libudp_shared.so: CMakeFiles/udp_shared.dir/build.make
libudp_shared.so: CMakeFiles/udp_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filippo/github/udp-connection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libudp_shared.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_shared.dir/build: libudp_shared.so
.PHONY : CMakeFiles/udp_shared.dir/build

CMakeFiles/udp_shared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_shared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_shared.dir/clean

CMakeFiles/udp_shared.dir/depend:
	cd /home/filippo/github/udp-connection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filippo/github/udp-connection /home/filippo/github/udp-connection /home/filippo/github/udp-connection/build /home/filippo/github/udp-connection/build /home/filippo/github/udp-connection/build/CMakeFiles/udp_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_shared.dir/depend

