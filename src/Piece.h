#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Piece
{
protected:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;
	int mTexturePositionX;
	int mTexturePositionY;
 	sf::Vector2f mPosition;
	sf::Texture mTexture;
	
public:
	sf::Sprite mSprite;
	int mValue;
	bool mColor;
	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color);

};

