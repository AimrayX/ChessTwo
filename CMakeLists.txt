cmake_minimum_required(VERSION 3.28)

project(
    Chess
    VERSION 1.0
    DESCRIPTION "Chess progam with SFML"
    LANGUAGES CXX)

add_compile_options(-std=c++23 -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror)

add_executable(chess src/main.cpp src/Game.cpp src/Game.h src/Board.cpp 
               src/Board.h src/Renderer.cpp src/Renderer.h src/Piece.cpp 
               src/Piece.h src/Rook.cpp src/Rook.h src/IMoveBehaviour.h src/RookMoveBehaviour.cpp 
               src/RookMoveBehaviour.h src/Context.cpp src/Context.h)

target_link_libraries(chess PUBLIC sfml-graphics sfml-window sfml-system)
target_compile_features(chess PUBLIC cxx_std_17)