cmake_minimum_required(VERSION 3.17)
project(LuaWindows C)

set(SOURCES lapi.c lauxlib.c lbaselib.c lcode.c lcorolib.c lctype.c ldblib.c ldebug.c ldo.c ldump.c lfunc.c lgc.c
        linit.c liolib.c llex.c lmem.c loadlib.c lobject.c lopcodes.c lparser.c loslib.c lstate.c lstring.c lstrlib.c
        ltable.c ltablib.c ltm.c lundump.c lutf8lib.c lvm.c lzio.c lmathlib.c)

if (WIN32)
    set(BUILD_SHARED_LIBS true)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()

if (MSVC AND NOT (CMAKE_BUILD_TYPE MATCHES DEBUG))
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:libcmt /LTCG")
endif()

add_library(Lua STATIC ${SOURCES})

add_executable(LuaI lua.c)
target_link_libraries(LuaI Lua)

add_executable(LuaC luac.c)
target_link_libraries(LuaC Lua)

add_subdirectory("testes/libs" "testes")