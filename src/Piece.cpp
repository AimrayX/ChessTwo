#include "Piece.h"
#include <iostream>

Piece::Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, 
			 bool movesDiagonaly, bool movesHorizonatly, bool movesVertically, int range)

	: mTextureFile {"../assets/pieces.png"}, 
	mTextureWidth {334}, mTextureHeight {334}, mTexturePositionX {texturePositionX}, 
	mTexturePositionY {texturePositionY}, mValue {value}, mColor {color}, movesDiagonaly {movesDiagonaly},
	movesHorizontaly {movesHorizonatly}, movesVertically {movesVertically}, mRange {range} {

	std::cout << "loaded with exit code: " << mTexture.loadFromFile(mTextureFile) << std::endl;
	
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(mTexturePositionX, mTexturePositionY, 334, 334));
	mSprite.setScale((boardSize / 8.0f) / 334.0f , (boardSize / 8.0f) / 334.0f);
	mSprite.setPosition(0, 0);

}