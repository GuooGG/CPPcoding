cmake_minimum_required(VERSION 3.14)

project(CPPcoding)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(VarintZigZag Algo/VarintZigzag.cpp)
add_executable(waitpidTemp OS/waitpid.cpp)