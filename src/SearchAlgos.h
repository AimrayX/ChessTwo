#pragma once
#include "Piece.h"
#include "SFML/Graphics.hpp"
#include <array>

namespace SearchAlgos
{
    unsigned long long getHorizontalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, const bool &color);

    std::pair<unsigned long long, unsigned long long> getDiagonalMovesBitmap(const unsigned long long friendlyPieces, const unsigned long long enemyPieces,
                                                                             const sf::RectangleShape &currentSquare);
                                                
    std::pair<unsigned long long, unsigned long long> getKnightMovesBitmap(const unsigned long long friendlyPieces, const unsigned long long enemyPieces,
                                                                           const sf::RectangleShape &currentSquare);

    unsigned long long getKingMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, const bool &color);

    unsigned long long getPawnMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, const bool &color, const bool &hasNotMoved);

    bool checkIfSquareIsAttacked(const bool &color, const sf::RectangleShape &boardRectangles, 
                                 const std::vector<std::shared_ptr<Piece>> &pieces);

    unsigned long long getSquareBitmap(const sf::RectangleShape &square);

    unsigned long long convert2DArrayToBitmap(std::array<std::array<bool, 8>, 8> &validSquares);

    void displayValidSquares(std::array<std::array<bool, 8>, 8> &validSquares);
}
