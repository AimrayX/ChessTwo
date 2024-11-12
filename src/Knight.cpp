#include "Knight.h"
#include "SearchAlgos.h"
#include "MyMaths.h"
#include <iostream>
#include <array>
#include <cmath>

Knight::Knight(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 3 * 334, !color * 344, 3, color, initalSquare)
{
}

void Knight::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	std::array<std::array<bool, 8>, 8> validSquares = {};

	sf::Vector2u position(static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().x / mCurrentSquare.getSize().x)),
							static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().y / mCurrentSquare.getSize().y)));

	if (position.y + 2 < 8 && position.x + 1 < 8)
	{
		validSquares[position.y + 2][position.x + 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 2][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y + 2][position.x + 1] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y + 1 < 8 && position.x + 2 < 8)
	{
		validSquares[position.y + 1][position.x + 2] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 1][position.x + 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y + 1][position.x + 2] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y > 0 && position.x + 2 < 8)
	{
		validSquares[position.y - 1][position.x + 2] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 1][position.x + 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y - 1][position.x + 2] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y > 1 && position.x + 1 < 8)
	{
		validSquares[position.y - 2][position.x + 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 2][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y - 2][position.x + 1] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y > 1 && position.x > 0)
	{
		validSquares[position.y - 2][position.x - 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 2][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y - 2][position.x - 1] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y > 0 && position.x > 1)
	{
		validSquares[position.y - 1][position.x - 2] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y - 1][position.x - 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y - 1][position.x - 2] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y + 1 < 8 && position.x > 1)
	{
		validSquares[position.y + 1][position.x - 2] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 1][position.x - 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y + 1][position.x - 2] = 0;
					piece->isProtected = 1;
					break;
				}
			}
		}
	}

	if (position.y + 2 < 8 && position.x > 0)
	{
		validSquares[position.y + 2][position.x - 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y + 2][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;

				if (piece->mColor == mColor)
				{
					validSquares[position.y + 2][position.x - 1] = 0;
					piece->isProtected = 1;
					break;
				}
				
			}
		}
	}

	SearchAlgos::displayValidSquares(validSquares);

	std::cout << position.x << "x" << position.y << '\n' << std::endl;

	mBitmapValidSquares = SearchAlgos::convert2DArrayToBitmap(validSquares);
}