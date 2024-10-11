cmake_minimum_required(VERSION 3.28)

project(
    Chess
    VERSION 1.0
    DESCRIPTION "Chess progam with SFML"
    LANGUAGES CXX)

add_executable(chess main.cpp Game.cpp Game.h Board.cpp Board.h ChessWindow.cpp ChessWindow.h Piece.cpp Piece.h Rook.cpp Rook.h)

target_link_libraries(chess PUBLIC sfml-graphics sfml-window sfml-system)
target_compile_features(chess PUBLIC cxx_std_17)