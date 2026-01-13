cmake_minimum_required(VERSION 3.10)
project(Main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Tests)

add_executable(Main Main.cpp)
find_package(Threads REQUIRED)
target_include_directories(Main PUBLIC Common)
target_link_libraries(Main PRIVATE Threads::Threads)
