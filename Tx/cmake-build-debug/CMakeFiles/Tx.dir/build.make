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
CMAKE_COMMAND = /home/aerez/clion-2019.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/aerez/clion-2019.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aerez/CLionProjects/CustomFrame/Tx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tx.dir/flags.make

CMakeFiles/Tx.dir/main.cpp.o: CMakeFiles/Tx.dir/flags.make
CMakeFiles/Tx.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tx.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tx.dir/main.cpp.o -c /home/aerez/CLionProjects/CustomFrame/Tx/main.cpp

CMakeFiles/Tx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tx.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrame/Tx/main.cpp > CMakeFiles/Tx.dir/main.cpp.i

CMakeFiles/Tx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tx.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrame/Tx/main.cpp -o CMakeFiles/Tx.dir/main.cpp.s

CMakeFiles/Tx.dir/CustomFrame.cpp.o: CMakeFiles/Tx.dir/flags.make
CMakeFiles/Tx.dir/CustomFrame.cpp.o: ../CustomFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tx.dir/CustomFrame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tx.dir/CustomFrame.cpp.o -c /home/aerez/CLionProjects/CustomFrame/Tx/CustomFrame.cpp

CMakeFiles/Tx.dir/CustomFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tx.dir/CustomFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrame/Tx/CustomFrame.cpp > CMakeFiles/Tx.dir/CustomFrame.cpp.i

CMakeFiles/Tx.dir/CustomFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tx.dir/CustomFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrame/Tx/CustomFrame.cpp -o CMakeFiles/Tx.dir/CustomFrame.cpp.s

CMakeFiles/Tx.dir/FileSender.cpp.o: CMakeFiles/Tx.dir/flags.make
CMakeFiles/Tx.dir/FileSender.cpp.o: ../FileSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tx.dir/FileSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tx.dir/FileSender.cpp.o -c /home/aerez/CLionProjects/CustomFrame/Tx/FileSender.cpp

CMakeFiles/Tx.dir/FileSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tx.dir/FileSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrame/Tx/FileSender.cpp > CMakeFiles/Tx.dir/FileSender.cpp.i

CMakeFiles/Tx.dir/FileSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tx.dir/FileSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrame/Tx/FileSender.cpp -o CMakeFiles/Tx.dir/FileSender.cpp.s

# Object files for target Tx
Tx_OBJECTS = \
"CMakeFiles/Tx.dir/main.cpp.o" \
"CMakeFiles/Tx.dir/CustomFrame.cpp.o" \
"CMakeFiles/Tx.dir/FileSender.cpp.o"

# External object files for target Tx
Tx_EXTERNAL_OBJECTS =

Tx: CMakeFiles/Tx.dir/main.cpp.o
Tx: CMakeFiles/Tx.dir/CustomFrame.cpp.o
Tx: CMakeFiles/Tx.dir/FileSender.cpp.o
Tx: CMakeFiles/Tx.dir/build.make
Tx: CMakeFiles/Tx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Tx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tx.dir/build: Tx

.PHONY : CMakeFiles/Tx.dir/build

CMakeFiles/Tx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tx.dir/clean

CMakeFiles/Tx.dir/depend:
	cd /home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aerez/CLionProjects/CustomFrame/Tx /home/aerez/CLionProjects/CustomFrame/Tx /home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug /home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug /home/aerez/CLionProjects/CustomFrame/Tx/cmake-build-debug/CMakeFiles/Tx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tx.dir/depend

