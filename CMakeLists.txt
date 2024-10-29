cmake_minimum_required(VERSION 3.28)

project(
    Chess
    VERSION 1.1
    DESCRIPTION "Chess progam with SFML"
    LANGUAGES CXX)

add_compile_options(-std=c++23 -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror)

add_executable(chess src/main.cpp src/Game.cpp src/Game.h src/Board.cpp 
               src/Board.h src/Renderer.cpp src/Renderer.h src/Piece.cpp 
               src/Piece.h src/Rook.cpp src/Rook.h src/SearchAlgos.cpp src/SearchAlgos.h 
               src/MyMaths.cpp src/MyMaths.h src/Bishop.cpp src/Bishop.h src/Queen.cpp src/Queen.h 
               src/Knight.cpp src/Knight.h src/King.cpp src/King.h)

target_link_libraries(chess PUBLIC sfml-graphics sfml-window sfml-system)
target_compile_features(chess PUBLIC cxx_std_17)