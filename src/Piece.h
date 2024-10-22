#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Piece
{
public:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;
	int mTexturePositionX;
	int mTexturePositionY;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	//sf::CircleShape mSprite;
	int mValue;
	bool mColor;
	sf::RectangleShape &currentSquare;
	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape &initialSquare);

};

