#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"


class ChessWindow
{
private:
	std::string mWindowName;
	sf::Vector2u mWindowSize;
	sf::RenderWindow mWindow;
	Board board;

public:
	ChessWindow(unsigned int width, unsigned int height, std::string windowName);
	
	void run();
private:
	
	void updateView();
};

