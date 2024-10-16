#pragma once

#include "Piece.h"
#include "Rook.h"
#include "RookMoveBehaviour.h"
#include "Context.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


class Board {

private:
	

public:


	float mWidth;
	float mHeight;
	std::vector<sf::RectangleShape> mBoardTexture;
	void updateBoardTexture(sf::Vector2u size);
	Board(sf::Vector2u windowSize);
	std::vector<std::unique_ptr<Piece>> mPieces;
	Context context(std::unique_ptr<RookMoveBehaviour>());

};	

