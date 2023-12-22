cmake_minimum_required(VERSION 3.10)
project(Bombs)
add_executable(Bombs main.cpp getBombs.cpp getBombs.h maxDetonations.cpp maxDetonations.h bombs.txt)

target_link_libraries(Bombs gtest)