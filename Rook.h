#pragma once
#include "Piece.h"
#include "Board.h"
#include <SFML/Graphics.hpp>


class Rook : public Piece
{
private:
    sf::Texture texture;

public: 
    sf::Sprite sprite;
    Rook(int boardSize);
};

