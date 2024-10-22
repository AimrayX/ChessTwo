#include "Piece.h"
#include <iostream>

Piece::Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape &initialSquare)
	: mTextureFile {"../assets/pieces.png"}, mTextureWidth {334}, mTextureHeight {334}, 
	  mTexturePositionX {texturePositionX}, mTexturePositionY {texturePositionY}, mTexture {}, 
	  mSprite {}, mValue {value}, mColor {color}, currentSquare {initialSquare} {

	//std::cout << "loaded with exit code: " << mTexture.loadFromFile(mTextureFile) << std::endl;
	
	if (!mTexture.loadFromFile(mTextureFile))
	{
		mTexture.loadFromFile("assets/pieces.png");
	}
	

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(mTexturePositionX, mTexturePositionY, mTextureWidth, mTextureHeight));
	mSprite.setScale((boardSize / 8.0f) / 334.0f , (boardSize / 8.0f) / 334.0f);
	mSprite.setPosition(currentSquare.getPosition());

}