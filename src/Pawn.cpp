#include "Pawn.h"
#include "SearchAlgos.h"
#include <array>

Pawn::Pawn(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 5 * 334, !color * 344, 1, color, initalSquare), mHasMoved{}
{
}

unsigned long long Pawn::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	return SearchAlgos::getPawnMovesBitmap(pieces, boardRectangles, mCurrentSquare, mColor, mHasMoved);
}