#include "Rook.h"
#include <iostream>

Rook::Rook(int boardSize)
	:Piece(0, 0, 5, 1, false, true, true, 8), mTexture {}, mSprite {} {
	mTexture.loadFromFile("C:/Users/Timmy/source/repos/ChessTwo/assets/pieces.png");
	std::cout << "loaded with exit code: " << mTexture.loadFromFile("pieces.png") << std::endl;
	
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(0, 0, 334, 334));
	mSprite.setScale(static_cast<float>(boardSize / 334), static_cast<float>(boardSize / 334));
	mSprite.setPosition(0, 0);
}