#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Queen : public Piece
{
private:

public: 
    void calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
                                       std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) override;
    Queen(float boardSize, bool color, sf::RectangleShape initalSquare);
    unsigned long long getHorizontalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces, const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles);
    unsigned long long getDiagonalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces, const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles);
};