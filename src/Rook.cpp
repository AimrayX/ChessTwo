#include "Rook.h"

Rook::Rook(float boardSize, bool color, sf::RectangleShape &initalSquare)
	:Piece(boardSize, 4 * 334, !color * 344, 5, color, initalSquare) {
	
}