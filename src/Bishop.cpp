#include "Bishop.h"
#include "SearchAlgos.h"
#include <array>

Bishop::Bishop(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 2 * 334, !color * 344, 3, color, initalSquare)
{
}

std::pair<unsigned long long, unsigned long long> Bishop::calcMovesBitmap(unsigned long long blackPieces, unsigned long long whitePieces)
{
	if (!mColor)
	{
		return SearchAlgos::getDiagonalMovesBitmap(blackPieces, whitePieces, mCurrentSquare);
	}
	else
	{
		return SearchAlgos::getDiagonalMovesBitmap(whitePieces, blackPieces, mCurrentSquare);
	}
}

