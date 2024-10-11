#include <string>
#include <SFML/Graphics.hpp>
#pragma once
class Piece
{
protected:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;

public:
	int mValue;
	bool mColor;
	bool movesDiagonaly;
	bool movesHorizontaly;
	bool movesVertically;
	int mRange;
	Piece(float textureWidth, float textureHeight, int value);

};

