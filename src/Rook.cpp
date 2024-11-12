#include "Rook.h"
#include "SearchAlgos.h"
#include "MyMaths.h"
#include <array>
#include <cmath>
#include <iostream>

Rook::Rook(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 4 * 334, !color * 344, 5, color, initalSquare)
{
}

void Rook::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{

	std::array<std::array<bool, 8>, 8> validSquares = {};

	sf::Vector2u position(static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().x / mCurrentSquare.getSize().x)),
							static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().y / mCurrentSquare.getSize().y)));

	for (size_t i = position.x; i < 7; i++)
	{
		validSquares[position.y][i + 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y][i + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;
				if (piece->mColor == mColor)
				{
					validSquares[position.y][i + 1] = 0;
					piece->isProtected = 1;
				}
				else
				{
					validSquares[position.y][i + 1] = 1;
				}

				i = 7;
				break;
			}
		}
	}

	for (size_t i = position.x; i > 0; i--)
	{
		validSquares[position.y][i - 1] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[position.y][i - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;
				if (piece->mColor == mColor)
				{
					validSquares[position.y][i - 1] = 0;
					piece->isProtected = 1;
				}
				else
				{
					validSquares[position.y][i - 1] = 1;
				}

				i = 1;
				break;
			}
		}
	}

	for (size_t i = position.y; i < 7; i++)
	{
		for (auto &piece : pieces)
		{
			validSquares[i + 1][position.x] = 1;
			if (convertV2fToV2u(boardRectangles[i + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;
				if (piece->mColor == mColor)
				{
					validSquares[i + 1][position.x] = 0;
					piece->isProtected = 1;
				}
				else
				{
					validSquares[i + 1][position.x] = 1;
				}

				i = 7;
				break;
			}
		}
	}

	for (size_t i = position.y; i > 0; i--)
	{
		validSquares[i - 1][position.x] = 1;
		for (auto &piece : pieces)
		{
			if (convertV2fToV2u(boardRectangles[i - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
			{
				std::cout << "match found" << std::endl;
				if (piece->mColor == mColor)
				{
					validSquares[i - 1][position.x] = 0;
					piece->isProtected = 1;
				}
				else
				{
					validSquares[i - 1][position.x] = 1;
				}

				i = 1;
				break;
			}
		}
	}

	SearchAlgos::displayValidSquares(validSquares);

	std::cout << position.x << "x" << position.y << std::endl;

	mBitmapValidSquares = SearchAlgos::convert2DArrayToBitmap(validSquares);

}

