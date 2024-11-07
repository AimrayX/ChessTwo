#include "King.h"
#include "SearchAlgos.h"
#include <array>

King::King(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 0 * 334, !color * 344, 0, color, initalSquare)
{
}

unsigned long long King::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	return SearchAlgos::getKingMovesBitmap(pieces, boardRectangles, mCurrentSquare, mColor);
}