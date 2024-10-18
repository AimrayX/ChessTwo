#pragma once

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
	

};	

