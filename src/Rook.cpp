#include "Rook.h"
#include "SearchAlgos.h"
#include <array>

Rook::Rook(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 4 * 334, !color * 344, 5, color, initalSquare)
{
}

unsigned long long Rook::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	return SearchAlgo::getHorizontalMovesBitmap(pieces, boardRectangles, mCurrentSquare);
}

