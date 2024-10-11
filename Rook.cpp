#include "Rook.h"
#include <iostream>

Rook::Rook(int boardSize)
	:Piece(100, 100, 5) {
	texture.loadFromFile("C:/Users/Timmy/source/repos/ChessTwo/assets/pieces.png");
	std::cout << "loaded with exit code: " << texture.loadFromFile("pieces.png") << std::endl;
	
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 334, 334));
	sprite.setScale(boardSize / 334, boardSize / 334);
	sprite.setPosition(0, 0);
}