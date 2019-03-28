cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Scrabble
        README.md Ficha.cpp Ficha.h FichaCreator.cpp FichaCreator.h Juego.cpp Juego.h Jugador.cpp Jugador.h List.cpp List.h main.cpp Node.cpp Node.h)
