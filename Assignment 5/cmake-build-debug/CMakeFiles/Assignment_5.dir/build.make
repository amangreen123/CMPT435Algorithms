# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_5.dir/flags.make

CMakeFiles/Assignment_5.dir/main.cpp.obj: CMakeFiles/Assignment_5.dir/flags.make
CMakeFiles/Assignment_5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_5.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_5.dir\main.cpp.obj -c "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\main.cpp"

CMakeFiles/Assignment_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_5.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\main.cpp" > CMakeFiles\Assignment_5.dir\main.cpp.i

CMakeFiles/Assignment_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_5.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\main.cpp" -o CMakeFiles\Assignment_5.dir\main.cpp.s

CMakeFiles/Assignment_5.dir/KnapSack.cpp.obj: CMakeFiles/Assignment_5.dir/flags.make
CMakeFiles/Assignment_5.dir/KnapSack.cpp.obj: ../KnapSack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment_5.dir/KnapSack.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_5.dir\KnapSack.cpp.obj -c "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\KnapSack.cpp"

CMakeFiles/Assignment_5.dir/KnapSack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_5.dir/KnapSack.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\KnapSack.cpp" > CMakeFiles\Assignment_5.dir\KnapSack.cpp.i

CMakeFiles/Assignment_5.dir/KnapSack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_5.dir/KnapSack.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\KnapSack.cpp" -o CMakeFiles\Assignment_5.dir\KnapSack.cpp.s

# Object files for target Assignment_5
Assignment_5_OBJECTS = \
"CMakeFiles/Assignment_5.dir/main.cpp.obj" \
"CMakeFiles/Assignment_5.dir/KnapSack.cpp.obj"

# External object files for target Assignment_5
Assignment_5_EXTERNAL_OBJECTS =

Assignment_5.exe: CMakeFiles/Assignment_5.dir/main.cpp.obj
Assignment_5.exe: CMakeFiles/Assignment_5.dir/KnapSack.cpp.obj
Assignment_5.exe: CMakeFiles/Assignment_5.dir/build.make
Assignment_5.exe: CMakeFiles/Assignment_5.dir/linklibs.rsp
Assignment_5.exe: CMakeFiles/Assignment_5.dir/objects1.rsp
Assignment_5.exe: CMakeFiles/Assignment_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_5.dir/build: Assignment_5.exe

.PHONY : CMakeFiles/Assignment_5.dir/build

CMakeFiles/Assignment_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_5.dir/clean

CMakeFiles/Assignment_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5" "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5" "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug" "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug" "C:\Users\aaron\Documents\GitHub\CMPT435Algorithms\Assignment 5\cmake-build-debug\CMakeFiles\Assignment_5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_5.dir/depend

