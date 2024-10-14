#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Piece
{
private:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;
	int mTexturePositionX;
	int mTexturePositionY;
	sf::Sprite mSprite;
	sf::Texture mTexture;

protected:
	
public:
	int mValue;
	bool mColor;
	bool movesDiagonaly;
	bool movesHorizontaly;
	bool movesVertically;
	int mRange;
	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, bool movesDiagonaly, bool movesHorizonatly, bool movesVertically, int range);

};

