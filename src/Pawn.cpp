#include "Pawn.h"
#include "SearchAlgos.h"
#include "MyMaths.h"
#include <iostream>
#include <array>
#include <cmath>

Pawn::Pawn(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 5 * 334, !color * 344, 1, color, initalSquare), attackingSquares{}
{
}

void Pawn::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
						   std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	mBitmapCurrentSquare = SearchAlgos::getSquareBitmap(mCurrentSquare);

	std::array<std::array<bool, 8>, 8> validSquares = {};
	std::array<std::array<bool, 8>, 8> attackingSquares = {};

	sf::Vector2u position(static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().x / mCurrentSquare.getSize().x)),
							static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().y / mCurrentSquare.getSize().y)));

	if (mHasMoved == 0 && mColor == 0)
	{
		validSquares[position.y + 1][position.x] = 1;
		validSquares[position.y + 2][position.x] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x] = 0;
				validSquares[position.y + 2][position.x] = 0;
				break;
			}
			if (convertV2fToV2u(boardRectangles[position.y + 2][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 2][position.x] = 0;
				break;
			}
		}
	}
	else if (mHasMoved == 0 && mColor == 1)
	{
		validSquares[position.y - 1][position.x] = 1;
		validSquares[position.y - 2][position.x] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x] = 0;
				validSquares[position.y - 2][position.x] = 0;
				break;
			}
			if (convertV2fToV2u(boardRectangles[position.y - 2][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 2][position.x] = 0;
				break;
			}
		}
	}
	else if (position.y + 1 < 8 && mColor == 0)
	{
		validSquares[position.y + 1][position.x] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x] = 0;
				break;
			}
		}
	}
	else if (position.y > 0 && mColor == 1)
	{
		validSquares[position.y - 1][position.x] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x] = 0;
				break;
			}
		}
	}
	if (mColor == 0)
	{
		bool leftSearch{}, rightSearch{};

		if (position.x < 7)
		{
			validSquares[position.y + 1][position.x + 1] = 0;
			attackingSquares[position.y + 1][position.x + 1] = 1;
			rightSearch = true;
		}
		if (position.x > 0)
		{
			validSquares[position.y + 1][position.x - 1] = 0;
			attackingSquares[position.y + 1][position.x - 1] = 1;
			leftSearch = true;
		}
		
		
		
		for (auto &piece : pieces)
		{
			if (rightSearch && convertV2fToV2u(boardRectangles[position.y + 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x + 1] = 1;
			}
			if (leftSearch && convertV2fToV2u(boardRectangles[position.y + 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x - 1] = 1;
			}

		}
	}
	else if (mColor == 1)
	{
		bool leftSearch{}, rightSearch{};

		if (position.x < 7)
		{
			validSquares[position.y - 1][position.x + 1] = 0;
			attackingSquares[position.y - 1][position.x + 1] = 1;
			rightSearch = true;
		}
		if (position.x > 0)
		{
			validSquares[position.y - 1][position.x - 1] = 0;
			attackingSquares[position.y - 1][position.x - 1] = 1;
			leftSearch = true;
		}
		
		
		
		for (auto &piece : pieces)
		{
			if (rightSearch && convertV2fToV2u(boardRectangles[position.y - 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x + 1] = 1;
			}
			if (leftSearch && convertV2fToV2u(boardRectangles[position.y - 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x - 1] = 1;
			}

		}
	}
	


	//SearchAlgos::displayValidSquares(validSquares);

	std::cout << position.x << "x" << position.y << "  " << mColor << '\n' << std::endl;

	mBitmapValidSquares = SearchAlgos::convert2DArrayToBitmap(validSquares);
	mBitmapAttackingSquares = SearchAlgos::convert2DArrayToBitmap(attackingSquares);
}