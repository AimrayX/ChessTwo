#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>


class Rook : public Piece
{
private:
    sf::Texture mTexture;

public: 
    sf::Sprite mSprite;
    Rook(float boardSize);
};

