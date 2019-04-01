cmake_minimum_required(VERSION 3.13)
project(Scrabble)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(Client main.cpp)

add_library(my_library pantallajuego.cpp)



find_package(PkgConfig REQUIRED)
pkg_check_modules(JSON-C json-c)
link_libraries(${JSON-C_LIBRARIES})
target_link_libraries(Client ${JSON-C_LIBRARIES})