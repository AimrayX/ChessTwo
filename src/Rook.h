#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Rook : public Piece
{
private:
    long long rookBitmap;
public: 
    long long getMovesBitmap(const long long &enemyPieces, const long long &friendlyPieces) override;
    long long getRookBitmap();
    Rook(float boardSize, bool color, sf::RectangleShape initalSquare);
};

