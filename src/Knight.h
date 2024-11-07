#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Knight : public Piece
{
private:

public: 
    std::pair<unsigned long long, unsigned long long> calcMovesBitmap(unsigned long long blackPieces, unsigned long long whitePieces) override;
    Knight(float boardSize, bool color, sf::RectangleShape initalSquare);
};