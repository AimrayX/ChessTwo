#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <memory>


class Board {

private:
	

public:

	float mWidth;
	float mHeight;
	float mBoardSize;
	std::array<std::array<sf::RectangleShape, 8>, 8> mBoardRectangles;
	void updateBoard(sf::Vector2u size);
	Board(sf::Vector2u windowSize);
	

};	

