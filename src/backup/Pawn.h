#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Pawn : public Piece
{
private:
    bool mHasNotMoved;

public: 
    unsigned long long calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) override;
    Pawn(float boardSize, bool color, sf::RectangleShape initalSquare);
};