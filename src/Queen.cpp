#include "Queen.h"
#include "SearchAlgos.h"
#include <array>

Queen::Queen(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 1 * 334, !color * 344, 3, color, initalSquare)
{
}

unsigned long long Queen::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles, bool &color)
{
	return SearchAlgo::getDiagonalMovesBitmap(pieces, boardRectangles, mCurrentSquare, color) | SearchAlgo::getHorizontalMovesBitmap(pieces, boardRectangles, mCurrentSquare, color);
}