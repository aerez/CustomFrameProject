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
CMAKE_SOURCE_DIR = /home/aerez/CLionProjects/CustomFrameProject/Rx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Rx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rx.dir/flags.make

CMakeFiles/Rx.dir/main.cpp.o: CMakeFiles/Rx.dir/flags.make
CMakeFiles/Rx.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rx.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rx.dir/main.cpp.o -c /home/aerez/CLionProjects/CustomFrameProject/Rx/main.cpp

CMakeFiles/Rx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rx.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrameProject/Rx/main.cpp > CMakeFiles/Rx.dir/main.cpp.i

CMakeFiles/Rx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rx.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrameProject/Rx/main.cpp -o CMakeFiles/Rx.dir/main.cpp.s

CMakeFiles/Rx.dir/FileReceiver.cpp.o: CMakeFiles/Rx.dir/flags.make
CMakeFiles/Rx.dir/FileReceiver.cpp.o: ../FileReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Rx.dir/FileReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rx.dir/FileReceiver.cpp.o -c /home/aerez/CLionProjects/CustomFrameProject/Rx/FileReceiver.cpp

CMakeFiles/Rx.dir/FileReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rx.dir/FileReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrameProject/Rx/FileReceiver.cpp > CMakeFiles/Rx.dir/FileReceiver.cpp.i

CMakeFiles/Rx.dir/FileReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rx.dir/FileReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrameProject/Rx/FileReceiver.cpp -o CMakeFiles/Rx.dir/FileReceiver.cpp.s

CMakeFiles/Rx.dir/CustomFrame.cpp.o: CMakeFiles/Rx.dir/flags.make
CMakeFiles/Rx.dir/CustomFrame.cpp.o: ../CustomFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Rx.dir/CustomFrame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rx.dir/CustomFrame.cpp.o -c /home/aerez/CLionProjects/CustomFrameProject/Rx/CustomFrame.cpp

CMakeFiles/Rx.dir/CustomFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rx.dir/CustomFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/CustomFrameProject/Rx/CustomFrame.cpp > CMakeFiles/Rx.dir/CustomFrame.cpp.i

CMakeFiles/Rx.dir/CustomFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rx.dir/CustomFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/CustomFrameProject/Rx/CustomFrame.cpp -o CMakeFiles/Rx.dir/CustomFrame.cpp.s

# Object files for target Rx
Rx_OBJECTS = \
"CMakeFiles/Rx.dir/main.cpp.o" \
"CMakeFiles/Rx.dir/FileReceiver.cpp.o" \
"CMakeFiles/Rx.dir/CustomFrame.cpp.o"

# External object files for target Rx
Rx_EXTERNAL_OBJECTS =

Rx: CMakeFiles/Rx.dir/main.cpp.o
Rx: CMakeFiles/Rx.dir/FileReceiver.cpp.o
Rx: CMakeFiles/Rx.dir/CustomFrame.cpp.o
Rx: CMakeFiles/Rx.dir/build.make
Rx: CMakeFiles/Rx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Rx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rx.dir/build: Rx

.PHONY : CMakeFiles/Rx.dir/build

CMakeFiles/Rx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rx.dir/clean

CMakeFiles/Rx.dir/depend:
	cd /home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aerez/CLionProjects/CustomFrameProject/Rx /home/aerez/CLionProjects/CustomFrameProject/Rx /home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug /home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug /home/aerez/CLionProjects/CustomFrameProject/Rx/cmake-build-debug/CMakeFiles/Rx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rx.dir/depend

