#include "Knight.h"
#include "SearchAlgos.h"
#include <array>

Knight::Knight(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 3 * 334, !color * 344, 3, color, initalSquare)
{
}

unsigned long long Knight::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	return SearchAlgos::getKnightMovesBitmap(pieces, boardRectangles, mCurrentSquare, mColor);
}