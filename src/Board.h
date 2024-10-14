#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"
#include "Rook.h"

class Board
{
private:
	

public:
	float mWidth;
	float mHeight;
	

	std::vector<sf::RectangleShape> mBoardTexture;
	Rook rook1b;
	Rook rook2b;
	Rook rook1w;
	Rook rook2w;
	void updateBoardTexture(sf::Vector2u size);
	void initalizeStartingPosition();
	Board(sf::Vector2u windowSize);
	
	
	std::vector<Piece *> mPieces;
	
	
};

