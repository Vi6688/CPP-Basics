cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(Basics/Common)
include_directories(Basics/Railway)
add_subdirectory(Basics)
add_executable(Main Main.cpp)