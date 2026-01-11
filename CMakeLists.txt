cmake_minimum_required(VERSION 3.10)

project(CPPBasics)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(Common)
# include_directories(Basics/Railway)
add_executable(Main Main.cpp)