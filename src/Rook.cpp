#include "Rook.h"
#include <cmath>

Rook::Rook(float boardSize, bool color, sf::RectangleShape initalSquare)
	:Piece(boardSize, 4 * 334, !color * 344, 5, color, initalSquare), rookBitmap{} {
	
}

long long Rook::getMovesBitmap(const long long &enemyPieces, const long long &friendlyPieces) {
	
}

long long Rook::getRookBitmap() {
	
	float position {mCurrentSquare.getPosition().x / mCurrentSquare.getSize().x * mCurrentSquare.getPosition().y / mCurrentSquare.getSize().y};

	
}

static bool approximatelyEqualRel(const double &a, const double &b, const double &relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

