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
	//Rook rook1;
	std::vector<sf::RectangleShape> mBoardTexture;
	Board(sf::Vector2u windowSize);
	
	
	std::vector<Piece *> mPieces;
	void updateBoardTexture(sf::Vector2u size);
	void initalizeStartingPosition();
	
};

