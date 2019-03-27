cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Scrabble
        README.md Cuadricula.cpp Cuadricula.h Node.cpp Node.h)
