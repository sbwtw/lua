cmake_minimum_required(VERSION 3.17)
project(LuaWindows C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lua)

add_executable(main main.cpp)
target_link_libraries(main Lua)