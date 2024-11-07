#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Bishop : public Piece
{
private:

public: 
    std::pair<unsigned long long, unsigned long long> calcMovesBitmap(unsigned long long blackPieces, unsigned long long whitePieces) override;
    
    Bishop(float boardSize, bool color, sf::RectangleShape initalSquare);
};
