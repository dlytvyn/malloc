# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lits-user/CLionProjects/malloc-final-printf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/malloc_final-printf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc_final-printf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc_final-printf.dir/flags.make

CMakeFiles/malloc_final-printf.dir/tests/test0.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/tests/test0.c.o: ../tests/test0.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc_final-printf.dir/tests/test0.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/tests/test0.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/tests/test0.c

CMakeFiles/malloc_final-printf.dir/tests/test0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/tests/test0.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/tests/test0.c > CMakeFiles/malloc_final-printf.dir/tests/test0.c.i

CMakeFiles/malloc_final-printf.dir/tests/test0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/tests/test0.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/tests/test0.c -o CMakeFiles/malloc_final-printf.dir/tests/test0.c.s

CMakeFiles/malloc_final-printf.dir/sources/free.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/sources/free.c.o: ../sources/free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloc_final-printf.dir/sources/free.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/sources/free.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/sources/free.c

CMakeFiles/malloc_final-printf.dir/sources/free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/sources/free.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/sources/free.c > CMakeFiles/malloc_final-printf.dir/sources/free.c.i

CMakeFiles/malloc_final-printf.dir/sources/free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/sources/free.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/sources/free.c -o CMakeFiles/malloc_final-printf.dir/sources/free.c.s

CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o: ../sources/malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc.c

CMakeFiles/malloc_final-printf.dir/sources/malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/sources/malloc.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc.c > CMakeFiles/malloc_final-printf.dir/sources/malloc.c.i

CMakeFiles/malloc_final-printf.dir/sources/malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/sources/malloc.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc.c -o CMakeFiles/malloc_final-printf.dir/sources/malloc.c.s

CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o: ../sources/malloc_add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc_add.c

CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc_add.c > CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.i

CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/sources/malloc_add.c -o CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.s

CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o: ../sources/realloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/sources/realloc.c

CMakeFiles/malloc_final-printf.dir/sources/realloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/sources/realloc.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/sources/realloc.c > CMakeFiles/malloc_final-printf.dir/sources/realloc.c.i

CMakeFiles/malloc_final-printf.dir/sources/realloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/sources/realloc.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/sources/realloc.c -o CMakeFiles/malloc_final-printf.dir/sources/realloc.c.s

CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o: CMakeFiles/malloc_final-printf.dir/flags.make
CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o: ../sources/show_alloc_mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o   -c /Users/lits-user/CLionProjects/malloc-final-printf/sources/show_alloc_mem.c

CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lits-user/CLionProjects/malloc-final-printf/sources/show_alloc_mem.c > CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.i

CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lits-user/CLionProjects/malloc-final-printf/sources/show_alloc_mem.c -o CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.s

# Object files for target malloc_final-printf
malloc_final__printf_OBJECTS = \
"CMakeFiles/malloc_final-printf.dir/tests/test0.c.o" \
"CMakeFiles/malloc_final-printf.dir/sources/free.c.o" \
"CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o" \
"CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o" \
"CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o" \
"CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o"

# External object files for target malloc_final-printf
malloc_final__printf_EXTERNAL_OBJECTS =

malloc_final-printf: CMakeFiles/malloc_final-printf.dir/tests/test0.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/sources/free.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/sources/malloc.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/sources/malloc_add.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/sources/realloc.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/sources/show_alloc_mem.c.o
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/build.make
malloc_final-printf: ../ft_printf/libftprintf.a
malloc_final-printf: CMakeFiles/malloc_final-printf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable malloc_final-printf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc_final-printf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc_final-printf.dir/build: malloc_final-printf

.PHONY : CMakeFiles/malloc_final-printf.dir/build

CMakeFiles/malloc_final-printf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc_final-printf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc_final-printf.dir/clean

CMakeFiles/malloc_final-printf.dir/depend:
	cd /Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lits-user/CLionProjects/malloc-final-printf /Users/lits-user/CLionProjects/malloc-final-printf /Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug /Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug /Users/lits-user/CLionProjects/malloc-final-printf/cmake-build-debug/CMakeFiles/malloc_final-printf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc_final-printf.dir/depend

