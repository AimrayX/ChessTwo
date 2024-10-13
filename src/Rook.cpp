#include "Rook.h"
#include <iostream>

Rook::Rook(float boardSize)
	:Piece(4 * 334, 0, 5, 1, false, true, true, 8), mTexture {}, mSprite {} {
	std::cout << "loaded with exit code: " << mTexture.loadFromFile("../assets/pieces.png") << std::endl;
	
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(mTexturePositionX, mTexturePositionY, 334, 334));
	mSprite.setScale((boardSize / 8.0f) / 334.0f , (boardSize / 8.0f) / 334.0f);
	mSprite.setPosition(0, 0);
}