cmake_minimum_required(VERSION 3.20)
project(8_old)

set(CMAKE_CXX_STANDARD 14)

add_executable(8_old main.cpp cube.h turns.h automat.h UserDialogue.h cube.cpp turns.cpp automat.cpp UserDialogue.cpp)
