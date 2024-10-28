#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Queen : public Piece
{
private:

public: 
    unsigned long long calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles, bool &color) override;
    Queen(float boardSize, bool color, sf::RectangleShape initalSquare);
};