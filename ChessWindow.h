#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"


class ChessWindow
{
private:
	std::string mWindowName;
	sf::RenderWindow mWindow;
	

public:
	sf::Vector2u mWindowSize;
	ChessWindow(int width, int height);
	void run();
private:
	Board board;
	void updateView();
};

