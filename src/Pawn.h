#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Pawn : public Piece
{
private:

public: 
    
    void calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) override;
    Pawn(float boardSize, bool color, sf::RectangleShape initalSquare);
    unsigned long long attackingSquares;
};