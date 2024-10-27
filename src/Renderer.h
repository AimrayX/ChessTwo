#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "Board.h"
#include "Piece.h"


class Renderer
{
private:
	std::string mWindowName;
	
public:
	sf::Vector2u mWindowSize;
private:
	std::array<std::array<sf::RectangleShape, 8>, 8> &mBoardRectangles;
	std::vector<sf::Sprite> mPieceSprites;
	void scalePieces(float boardSize);
public:	
	sf::RenderWindow mWindow;
	void updatePieceSprites(float boardSize, std::vector<std::shared_ptr<Piece>> &pieces);
	void highlightValidSquares(const std::shared_ptr<Piece> &piece);
	void draw();

public:
	Renderer(unsigned int width, unsigned int height, std::string windowName, std::array<std::array<sf::RectangleShape, 8>, 8> &BoardRectangles);
	
	void updateView();
};

