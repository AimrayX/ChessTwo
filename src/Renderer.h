#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"


class Renderer
{
private:
	std::string mWindowName;
public:
	sf::Vector2u mWindowSize;
	std::vector<sf::Sprite> mPiecesSprites;
private:
	sf::RenderWindow mWindow;
	Board board;
	

public:
	Renderer(unsigned int width, unsigned int height, std::string windowName);
	void run();
private:
	
	void updateView();
};

