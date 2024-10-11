#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"
#include "Rook.h"

class Board
{
private:
	

public:
	int mWidth;
	int mHeight;
	Board(sf::Vector2u windowSize);
	std::vector<sf::RectangleShape> mBoardTexture;
	
	std::vector<Piece *> mPieces;
	void updateBoardTexture(sf::Vector2u size);
	void initalizeStartingPosition();
	Rook rook1;
};

