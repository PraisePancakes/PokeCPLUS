# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\aryas\Downloads\cmake-3.28.0-rc5-windows-x86_64\cmake-3.28.0-rc5-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\aryas\Downloads\cmake-3.28.0-rc5-windows-x86_64\cmake-3.28.0-rc5-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\aryas\OneDrive\Desktop\PokeCPLUS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build

# Include any dependencies generated for this target.
include CMakeFiles/poke.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/poke.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/poke.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poke.dir/flags.make

CMakeFiles/poke.dir/src/main.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/main.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/main.cpp
CMakeFiles/poke.dir/src/main.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/poke.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/main.cpp.obj -MF CMakeFiles\poke.dir\src\main.cpp.obj.d -o CMakeFiles\poke.dir\src\main.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\main.cpp

CMakeFiles/poke.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\main.cpp > CMakeFiles\poke.dir\src\main.cpp.i

CMakeFiles/poke.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\main.cpp -o CMakeFiles\poke.dir\src\main.cpp.s

CMakeFiles/poke.dir/src/User.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/User.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/User.cpp
CMakeFiles/poke.dir/src/User.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/poke.dir/src/User.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/User.cpp.obj -MF CMakeFiles\poke.dir\src\User.cpp.obj.d -o CMakeFiles\poke.dir\src\User.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\User.cpp

CMakeFiles/poke.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/User.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\User.cpp > CMakeFiles\poke.dir\src\User.cpp.i

CMakeFiles/poke.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/User.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\User.cpp -o CMakeFiles\poke.dir\src\User.cpp.s

CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/console_gui/Gui.cpp
CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj -MF CMakeFiles\poke.dir\src\console_gui\Gui.cpp.obj.d -o CMakeFiles\poke.dir\src\console_gui\Gui.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\console_gui\Gui.cpp

CMakeFiles/poke.dir/src/console_gui/Gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/console_gui/Gui.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\console_gui\Gui.cpp > CMakeFiles\poke.dir\src\console_gui\Gui.cpp.i

CMakeFiles/poke.dir/src/console_gui/Gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/console_gui/Gui.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\console_gui\Gui.cpp -o CMakeFiles\poke.dir\src\console_gui\Gui.cpp.s

CMakeFiles/poke.dir/src/Pokemon.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/Pokemon.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/Pokemon.cpp
CMakeFiles/poke.dir/src/Pokemon.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/poke.dir/src/Pokemon.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/Pokemon.cpp.obj -MF CMakeFiles\poke.dir\src\Pokemon.cpp.obj.d -o CMakeFiles\poke.dir\src\Pokemon.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Pokemon.cpp

CMakeFiles/poke.dir/src/Pokemon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/Pokemon.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Pokemon.cpp > CMakeFiles\poke.dir\src\Pokemon.cpp.i

CMakeFiles/poke.dir/src/Pokemon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/Pokemon.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Pokemon.cpp -o CMakeFiles\poke.dir\src\Pokemon.cpp.s

CMakeFiles/poke.dir/src/Ball.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/Ball.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/Ball.cpp
CMakeFiles/poke.dir/src/Ball.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/poke.dir/src/Ball.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/Ball.cpp.obj -MF CMakeFiles\poke.dir\src\Ball.cpp.obj.d -o CMakeFiles\poke.dir\src\Ball.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Ball.cpp

CMakeFiles/poke.dir/src/Ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/Ball.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Ball.cpp > CMakeFiles\poke.dir\src\Ball.cpp.i

CMakeFiles/poke.dir/src/Ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/Ball.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Ball.cpp -o CMakeFiles\poke.dir\src\Ball.cpp.s

CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/pokeData/Data.cpp
CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj -MF CMakeFiles\poke.dir\src\pokeData\Data.cpp.obj.d -o CMakeFiles\poke.dir\src\pokeData\Data.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\pokeData\Data.cpp

CMakeFiles/poke.dir/src/pokeData/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/pokeData/Data.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\pokeData\Data.cpp > CMakeFiles\poke.dir\src\pokeData\Data.cpp.i

CMakeFiles/poke.dir/src/pokeData/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/pokeData/Data.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\pokeData\Data.cpp -o CMakeFiles\poke.dir\src\pokeData\Data.cpp.s

CMakeFiles/poke.dir/src/Environment.cpp.obj: CMakeFiles/poke.dir/flags.make
CMakeFiles/poke.dir/src/Environment.cpp.obj: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/src/Environment.cpp
CMakeFiles/poke.dir/src/Environment.cpp.obj: CMakeFiles/poke.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/poke.dir/src/Environment.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poke.dir/src/Environment.cpp.obj -MF CMakeFiles\poke.dir\src\Environment.cpp.obj.d -o CMakeFiles\poke.dir\src\Environment.cpp.obj -c C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Environment.cpp

CMakeFiles/poke.dir/src/Environment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poke.dir/src/Environment.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Environment.cpp > CMakeFiles\poke.dir\src\Environment.cpp.i

CMakeFiles/poke.dir/src/Environment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poke.dir/src/Environment.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\src\Environment.cpp -o CMakeFiles\poke.dir\src\Environment.cpp.s

# Object files for target poke
poke_OBJECTS = \
"CMakeFiles/poke.dir/src/main.cpp.obj" \
"CMakeFiles/poke.dir/src/User.cpp.obj" \
"CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj" \
"CMakeFiles/poke.dir/src/Pokemon.cpp.obj" \
"CMakeFiles/poke.dir/src/Ball.cpp.obj" \
"CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj" \
"CMakeFiles/poke.dir/src/Environment.cpp.obj"

# External object files for target poke
poke_EXTERNAL_OBJECTS =

C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/main.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/User.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/console_gui/Gui.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/Pokemon.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/Ball.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/pokeData/Data.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/src/Environment.cpp.obj
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/build.make
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/linkLibs.rsp
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/objects1.rsp
C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe: CMakeFiles/poke.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\exe\poke.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\poke.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poke.dir/build: C:/Users/aryas/OneDrive/Desktop/PokeCPLUS/exe/poke.exe
.PHONY : CMakeFiles/poke.dir/build

CMakeFiles/poke.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\poke.dir\cmake_clean.cmake
.PHONY : CMakeFiles/poke.dir/clean

CMakeFiles/poke.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aryas\OneDrive\Desktop\PokeCPLUS C:\Users\aryas\OneDrive\Desktop\PokeCPLUS C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build C:\Users\aryas\OneDrive\Desktop\PokeCPLUS\build\CMakeFiles\poke.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/poke.dir/depend

