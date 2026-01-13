
add_executable(VectorTest VectorTest.cpp)
target_include_directories(VectorTest PRIVATE ${CMAKE_SOURCE_DIR}/Common)

add_executable(VectorPerformanceTest VectorPerfTest.cpp)
target_include_directories(VectorPerformanceTest PRIVATE ${CMAKE_SOURCE_DIR}/Common)