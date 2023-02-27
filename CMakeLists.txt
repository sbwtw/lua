cmake_minimum_required(VERSION 3.17)
project(LuaWindows C)

if (WIN32)
    set(BUILD_SHARED_LIBS true)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()

if (MSVC AND NOT (CMAKE_BUILD_TYPE MATCHES DEBUG))
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:libcmt /LTCG")
endif()

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")
endif()

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DLUA_USE_JUMPTABLE=0)
endif()

add_definitions(-DLUA_USE_POSIX)

set(SOURCES lapi.c lauxlib.c lbaselib.c lcode.c lcorolib.c lctype.c ldblib.c ldebug.c ldo.c ldump.c lfunc.c lgc.c
        linit.c liolib.c llex.c lmem.c loadlib.c lobject.c lopcodes.c lparser.c loslib.c lstate.c lstring.c lstrlib.c
        ltable.c ltablib.c ltm.c lundump.c lutf8lib.c lvm.c lzio.c lmathlib.c)

add_library(Lua STATIC ${SOURCES})
set_property(TARGET Lua PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(LuaI lua.c)
target_link_libraries(LuaI Lua m)
target_compile_definitions(LuaI PUBLIC LUAI_ASSERT)

add_executable(LuaC luac.c)
target_link_libraries(LuaC Lua m)

add_subdirectory("testes/libs" "testes")