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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kuraxii/desktop/repo/OnlineConference-server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kuraxii/desktop/repo/OnlineConference-server/build

# Include any dependencies generated for this target.
include src/CMakeFiles/conference.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/conference.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/conference.dir/flags.make

src/CMakeFiles/conference.dir/buffer.cpp.o: src/CMakeFiles/conference.dir/flags.make
src/CMakeFiles/conference.dir/buffer.cpp.o: ../src/buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuraxii/desktop/repo/OnlineConference-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/conference.dir/buffer.cpp.o"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/conference.dir/buffer.cpp.o -c /home/kuraxii/desktop/repo/OnlineConference-server/src/buffer.cpp

src/CMakeFiles/conference.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conference.dir/buffer.cpp.i"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kuraxii/desktop/repo/OnlineConference-server/src/buffer.cpp > CMakeFiles/conference.dir/buffer.cpp.i

src/CMakeFiles/conference.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conference.dir/buffer.cpp.s"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kuraxii/desktop/repo/OnlineConference-server/src/buffer.cpp -o CMakeFiles/conference.dir/buffer.cpp.s

src/CMakeFiles/conference.dir/http.cpp.o: src/CMakeFiles/conference.dir/flags.make
src/CMakeFiles/conference.dir/http.cpp.o: ../src/http.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuraxii/desktop/repo/OnlineConference-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/conference.dir/http.cpp.o"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/conference.dir/http.cpp.o -c /home/kuraxii/desktop/repo/OnlineConference-server/src/http.cpp

src/CMakeFiles/conference.dir/http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conference.dir/http.cpp.i"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kuraxii/desktop/repo/OnlineConference-server/src/http.cpp > CMakeFiles/conference.dir/http.cpp.i

src/CMakeFiles/conference.dir/http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conference.dir/http.cpp.s"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kuraxii/desktop/repo/OnlineConference-server/src/http.cpp -o CMakeFiles/conference.dir/http.cpp.s

src/CMakeFiles/conference.dir/net.cpp.o: src/CMakeFiles/conference.dir/flags.make
src/CMakeFiles/conference.dir/net.cpp.o: ../src/net.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuraxii/desktop/repo/OnlineConference-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/conference.dir/net.cpp.o"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/conference.dir/net.cpp.o -c /home/kuraxii/desktop/repo/OnlineConference-server/src/net.cpp

src/CMakeFiles/conference.dir/net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conference.dir/net.cpp.i"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kuraxii/desktop/repo/OnlineConference-server/src/net.cpp > CMakeFiles/conference.dir/net.cpp.i

src/CMakeFiles/conference.dir/net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conference.dir/net.cpp.s"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kuraxii/desktop/repo/OnlineConference-server/src/net.cpp -o CMakeFiles/conference.dir/net.cpp.s

src/CMakeFiles/conference.dir/rtp.cpp.o: src/CMakeFiles/conference.dir/flags.make
src/CMakeFiles/conference.dir/rtp.cpp.o: ../src/rtp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuraxii/desktop/repo/OnlineConference-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/conference.dir/rtp.cpp.o"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/conference.dir/rtp.cpp.o -c /home/kuraxii/desktop/repo/OnlineConference-server/src/rtp.cpp

src/CMakeFiles/conference.dir/rtp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conference.dir/rtp.cpp.i"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kuraxii/desktop/repo/OnlineConference-server/src/rtp.cpp > CMakeFiles/conference.dir/rtp.cpp.i

src/CMakeFiles/conference.dir/rtp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conference.dir/rtp.cpp.s"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kuraxii/desktop/repo/OnlineConference-server/src/rtp.cpp -o CMakeFiles/conference.dir/rtp.cpp.s

# Object files for target conference
conference_OBJECTS = \
"CMakeFiles/conference.dir/buffer.cpp.o" \
"CMakeFiles/conference.dir/http.cpp.o" \
"CMakeFiles/conference.dir/net.cpp.o" \
"CMakeFiles/conference.dir/rtp.cpp.o"

# External object files for target conference
conference_EXTERNAL_OBJECTS =

src/libconference.a: src/CMakeFiles/conference.dir/buffer.cpp.o
src/libconference.a: src/CMakeFiles/conference.dir/http.cpp.o
src/libconference.a: src/CMakeFiles/conference.dir/net.cpp.o
src/libconference.a: src/CMakeFiles/conference.dir/rtp.cpp.o
src/libconference.a: src/CMakeFiles/conference.dir/build.make
src/libconference.a: src/CMakeFiles/conference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kuraxii/desktop/repo/OnlineConference-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libconference.a"
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/conference.dir/cmake_clean_target.cmake
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/conference.dir/build: src/libconference.a

.PHONY : src/CMakeFiles/conference.dir/build

src/CMakeFiles/conference.dir/clean:
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/conference.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/conference.dir/clean

src/CMakeFiles/conference.dir/depend:
	cd /home/kuraxii/desktop/repo/OnlineConference-server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kuraxii/desktop/repo/OnlineConference-server /home/kuraxii/desktop/repo/OnlineConference-server/src /home/kuraxii/desktop/repo/OnlineConference-server/build /home/kuraxii/desktop/repo/OnlineConference-server/build/src /home/kuraxii/desktop/repo/OnlineConference-server/build/src/CMakeFiles/conference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/conference.dir/depend

