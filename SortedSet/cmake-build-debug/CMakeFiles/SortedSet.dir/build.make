# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andrei\Desktop\UBB\SortedSet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\SortedSet.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\SortedSet.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\SortedSet.dir\flags.make

CMakeFiles\SortedSet.dir\App.cpp.obj: CMakeFiles\SortedSet.dir\flags.make
CMakeFiles\SortedSet.dir\App.cpp.obj: ..\App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SortedSet.dir/App.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SortedSet.dir\App.cpp.obj /FdCMakeFiles\SortedSet.dir\ /FS -c C:\Users\Andrei\Desktop\UBB\SortedSet\App.cpp
<<

CMakeFiles\SortedSet.dir\App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortedSet.dir/App.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\SortedSet.dir\App.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrei\Desktop\UBB\SortedSet\App.cpp
<<

CMakeFiles\SortedSet.dir\App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortedSet.dir/App.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SortedSet.dir\App.cpp.s /c C:\Users\Andrei\Desktop\UBB\SortedSet\App.cpp
<<

CMakeFiles\SortedSet.dir\ExtendedTest.cpp.obj: CMakeFiles\SortedSet.dir\flags.make
CMakeFiles\SortedSet.dir\ExtendedTest.cpp.obj: ..\ExtendedTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SortedSet.dir/ExtendedTest.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SortedSet.dir\ExtendedTest.cpp.obj /FdCMakeFiles\SortedSet.dir\ /FS -c C:\Users\Andrei\Desktop\UBB\SortedSet\ExtendedTest.cpp
<<

CMakeFiles\SortedSet.dir\ExtendedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortedSet.dir/ExtendedTest.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\SortedSet.dir\ExtendedTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrei\Desktop\UBB\SortedSet\ExtendedTest.cpp
<<

CMakeFiles\SortedSet.dir\ExtendedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortedSet.dir/ExtendedTest.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SortedSet.dir\ExtendedTest.cpp.s /c C:\Users\Andrei\Desktop\UBB\SortedSet\ExtendedTest.cpp
<<

CMakeFiles\SortedSet.dir\ShortTest.cpp.obj: CMakeFiles\SortedSet.dir\flags.make
CMakeFiles\SortedSet.dir\ShortTest.cpp.obj: ..\ShortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SortedSet.dir/ShortTest.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SortedSet.dir\ShortTest.cpp.obj /FdCMakeFiles\SortedSet.dir\ /FS -c C:\Users\Andrei\Desktop\UBB\SortedSet\ShortTest.cpp
<<

CMakeFiles\SortedSet.dir\ShortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortedSet.dir/ShortTest.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\SortedSet.dir\ShortTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrei\Desktop\UBB\SortedSet\ShortTest.cpp
<<

CMakeFiles\SortedSet.dir\ShortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortedSet.dir/ShortTest.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SortedSet.dir\ShortTest.cpp.s /c C:\Users\Andrei\Desktop\UBB\SortedSet\ShortTest.cpp
<<

CMakeFiles\SortedSet.dir\SortedSet.cpp.obj: CMakeFiles\SortedSet.dir\flags.make
CMakeFiles\SortedSet.dir\SortedSet.cpp.obj: ..\SortedSet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SortedSet.dir/SortedSet.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SortedSet.dir\SortedSet.cpp.obj /FdCMakeFiles\SortedSet.dir\ /FS -c C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSet.cpp
<<

CMakeFiles\SortedSet.dir\SortedSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortedSet.dir/SortedSet.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\SortedSet.dir\SortedSet.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSet.cpp
<<

CMakeFiles\SortedSet.dir\SortedSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortedSet.dir/SortedSet.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SortedSet.dir\SortedSet.cpp.s /c C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSet.cpp
<<

CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.obj: CMakeFiles\SortedSet.dir\flags.make
CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.obj: ..\SortedSetIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SortedSet.dir/SortedSetIterator.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SortedSet.dir\SortedSetIterator.cpp.obj /FdCMakeFiles\SortedSet.dir\ /FS -c C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSetIterator.cpp
<<

CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortedSet.dir/SortedSetIterator.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSetIterator.cpp
<<

CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortedSet.dir/SortedSetIterator.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SortedSet.dir\SortedSetIterator.cpp.s /c C:\Users\Andrei\Desktop\UBB\SortedSet\SortedSetIterator.cpp
<<

# Object files for target SortedSet
SortedSet_OBJECTS = \
"CMakeFiles\SortedSet.dir\App.cpp.obj" \
"CMakeFiles\SortedSet.dir\ExtendedTest.cpp.obj" \
"CMakeFiles\SortedSet.dir\ShortTest.cpp.obj" \
"CMakeFiles\SortedSet.dir\SortedSet.cpp.obj" \
"CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.obj"

# External object files for target SortedSet
SortedSet_EXTERNAL_OBJECTS =

SortedSet.exe: CMakeFiles\SortedSet.dir\App.cpp.obj
SortedSet.exe: CMakeFiles\SortedSet.dir\ExtendedTest.cpp.obj
SortedSet.exe: CMakeFiles\SortedSet.dir\ShortTest.cpp.obj
SortedSet.exe: CMakeFiles\SortedSet.dir\SortedSet.cpp.obj
SortedSet.exe: CMakeFiles\SortedSet.dir\SortedSetIterator.cpp.obj
SortedSet.exe: CMakeFiles\SortedSet.dir\build.make
SortedSet.exe: CMakeFiles\SortedSet.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SortedSet.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\SortedSet.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\SortedSet.dir\objects1.rsp @<<
 /out:SortedSet.exe /implib:SortedSet.lib /pdb:C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\SortedSet.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\SortedSet.dir\build: SortedSet.exe

.PHONY : CMakeFiles\SortedSet.dir\build

CMakeFiles\SortedSet.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SortedSet.dir\cmake_clean.cmake
.PHONY : CMakeFiles\SortedSet.dir\clean

CMakeFiles\SortedSet.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Andrei\Desktop\UBB\SortedSet C:\Users\Andrei\Desktop\UBB\SortedSet C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug C:\Users\Andrei\Desktop\UBB\SortedSet\cmake-build-debug\CMakeFiles\SortedSet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\SortedSet.dir\depend

