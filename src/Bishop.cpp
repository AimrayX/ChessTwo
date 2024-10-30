#include "Bishop.h"
#include "SearchAlgos.h"
#include <array>

Bishop::Bishop(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 2 * 334, !color * 344, 3, color, initalSquare)
{
}

unsigned long long Bishop::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	return SearchAlgos::getDiagonalMovesBitmap(pieces, boardRectangles, mCurrentSquare, mColor);
}

