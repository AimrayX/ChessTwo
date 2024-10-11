#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


class ChessWindow
{
private:
	float height;
	float width;
	std::string windowName;
	sf::RenderWindow window;
	std::vector<sf::RectangleShape> board;

public:
	ChessWindow(float width, float height);
	void run();
};

