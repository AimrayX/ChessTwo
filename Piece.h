#include <string>
#include <SFML/Graphics.hpp>
#pragma once
class Piece
{
protected:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;
	int mTexturePositionX;
	int mTexturePositionY;
public:
	int mValue;
	bool mColor;
	bool movesDiagonaly;
	bool movesHorizontaly;
	bool movesVertically;
	int mRange;
	Piece(int texturePositionX, int texturePositionY, int value, bool color, bool movesDiagonaly, bool movesHorizonatly, bool movesVertically, int range);

};

