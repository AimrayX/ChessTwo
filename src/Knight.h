#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Knight : public Piece
{
private:

public: 
    void calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) override;
    Knight(float boardSize, bool color, sf::RectangleShape initalSquare);
};