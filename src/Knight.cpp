#include "Knight.h"
#include "SearchAlgos.h"
#include <array>

Knight::Knight(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 3 * 334, !color * 344, 3, color, initalSquare)
{
}

std::pair<unsigned long long, unsigned long long> Knight::calcMovesBitmap(unsigned long long blackPieces, unsigned long long whitePieces)
{
	if (mColor)
	{
		return SearchAlgos::getKnightMovesBitmap(blackPieces, whitePieces, mCurrentSquare);
	}
	else
	{
		return SearchAlgos::getKnightMovesBitmap(whitePieces, blackPieces, mCurrentSquare);
	}
	
	
}