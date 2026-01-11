cmake_minimum_required(VERSION 3.10)
project(Main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main Main.cpp)
find_package(Threads REQUIRED)
target_include_directories(Main PUBLIC Common)
target_link_libraries(Main PRIVATE Threads::Threads)
