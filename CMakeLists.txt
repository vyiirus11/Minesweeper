cmake_minimum_required(VERSION 3.25)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(Minesweeper main.cpp Tile.cpp Tile.h Board.cpp Board.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Minesweeper sfml-system sfml-window sfml-graphics sfml-audio)
