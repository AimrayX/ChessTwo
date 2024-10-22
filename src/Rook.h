#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Rook : public Piece
{
private:

public: 

    Rook(float boardSize, bool color, sf::RectangleShape &initalSquare);
};

