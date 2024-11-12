#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class King : public Piece
{
private:

public: 
    void calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) override;
    King(float boardSize, bool color, sf::RectangleShape initalSquare);
    bool checkIfSquareIsAttacked(const bool &color ,const sf::RectangleShape &boardRectangle, const std::vector<std::shared_ptr<Piece>> &pieces);
};