cmake_minimum_required(VERSION 3.18)
project(test VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h" "test/*.cpp" "test/*.h")

add_subdirectory(test)
add_subdirectory(src)