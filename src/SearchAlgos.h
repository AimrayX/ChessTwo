#pragma once
#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <array>

namespace SearchAlgo
{
    unsigned long long getHorizontalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, bool &color);

    unsigned long long getSquareBitmap(const sf::RectangleShape &square);
}
