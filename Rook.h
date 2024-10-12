#pragma once
#include "Piece.h"
#include "Board.h"
#include <SFML/Graphics.hpp>


class Rook : public Piece
{
private:
    sf::Texture mTexture;

public: 
    sf::Sprite mSprite;
    Rook(int boardSize);
};

