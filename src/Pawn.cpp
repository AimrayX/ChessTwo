#include "Pawn.h"
#include "SearchAlgos.h"
#include "MyMaths.h"
#include <iostream>
#include <array>
#include <cmath>

Pawn::Pawn(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 5 * 334, !color * 344, 6, 1, color, initalSquare), attackingSquares{}
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

	//check valid squares while on starting square
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

	//check valid squares after the pawn has moved for the first time
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

	//check attacking squares
	if (position.y < 8 && mColor == 0)
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
			if (rightSearch && convertV2fToV2u(boardRectangles[position.y + 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) 
				&& piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x + 1] = 1;
			}
			if (leftSearch && convertV2fToV2u(boardRectangles[position.y + 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) 
				&& piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y + 1][position.x - 1] = 1;
			}

		}
	}
	else if (position.y > 0 && mColor == 1)
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
			if (rightSearch && convertV2fToV2u(boardRectangles[position.y - 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) 
				&& piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x + 1] = 1;
			}
			if (leftSearch && convertV2fToV2u(boardRectangles[position.y - 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) 
				&& piece->mColor != mColor)
			{
				//std::cout << "match found" << std::endl;
				validSquares[position.y - 1][position.x - 1] = 1;
			}

		}
		
	}
	
	//check en passent
	//TODO make the attacking squares take the pawn
	//update the previous move so they can not always be moved or make a variable just moved that resets after every turn
	if (mColor == 0 && (0b0000000000000000000000000000000011111111000000000000000000000000 & mBitmapCurrentSquare) != 0)
	{
		for (auto &piece : pieces)
		{
			if (piece->mColor != mColor && piece->mPieceID == 6 && (0b0000000000000000000000000000000011111111000000000000000000000000 & piece->mBitmapCurrentSquare) != 0
				&& (SearchAlgos::getSquareBitmap(piece->mPreviousSquare) & 0b0000000000000000000000000000000000000000000000001111111100000000) != 0)
			{
				unsigned int x = static_cast<unsigned int>(std::round(piece->mCurrentSquare.getPosition().x / piece->mCurrentSquare.getSize().x));
				unsigned int y = static_cast<unsigned int>(std::round(piece->mCurrentSquare.getPosition().y / piece->mCurrentSquare.getSize().y));
				validSquares[y + 1][x] = 1;
			}
			
		}
	}
	else if (mColor == 1 && (0b0000000000000000000000001111111100000000000000000000000000000000 & mBitmapCurrentSquare) != 0)
	{
		for (auto &piece : pieces)
		{
			if (piece->mColor != mColor && piece->mPieceID == 6 && (0b0000000000000000000000001111111100000000000000000000000000000000 & piece->mBitmapCurrentSquare) != 0
				&& (SearchAlgos::getSquareBitmap(piece->mPreviousSquare) & 0b0000000011111111000000000000000000000000000000000000000000000000) != 0)
			{
				unsigned int x = static_cast<unsigned int>(std::round(piece->mCurrentSquare.getPosition().x / piece->mCurrentSquare.getSize().x));
				unsigned int y = static_cast<unsigned int>(std::round(piece->mCurrentSquare.getPosition().y / piece->mCurrentSquare.getSize().y));
				validSquares[y - 1][x] = 1;
			}
			
		}
	}


	//SearchAlgos::displayValidSquares(validSquares);

	//std::cout << position.x << "x" << position.y << "  " << mColor << '\n' << std::endl;

	mBitmapValidSquares = SearchAlgos::convert2DArrayToBitmap(validSquares);
	mBitmapAttackingSquares = SearchAlgos::convert2DArrayToBitmap(attackingSquares);
}