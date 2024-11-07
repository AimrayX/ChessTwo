#include "Pawn.h"
#include "MyMaths.h"
#include "SearchAlgos.h"
#include <array>

#include <iostream>

Pawn::Pawn(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 5 * 334, !color * 344, 1, color, initalSquare), mHasNotMoved{1}
{
}

unsigned long long Pawn::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{
	if (mHasNotMoved == 1)
	{
		mHasNotMoved = 0;
		if (mColor)
		{
			for (size_t i = 0; i < 8; i++)
		{
			std::cout << convertV2fToV2u(boardRectangles[6][i].getPosition()).x << "x ^ " << convertV2fToV2u(boardRectangles[6][i].getPosition()).y 
			<< "x : " << convertV2fToV2u(mCurrentSquare.getPosition()).x << "x ^ " << convertV2fToV2u(mCurrentSquare.getPosition()).y << "y" << std::endl;
			
			if (convertV2fToV2u(boardRectangles[6][i].getPosition()) == convertV2fToV2u(mCurrentSquare.getPosition()))
			{
				mHasNotMoved = 1;
				break;
			} 
		
		}
		}
		else
		{
			for (size_t i = 0; i < 8; i++)
		{
			std::cout << convertV2fToV2u(boardRectangles[1][i].getPosition()).x << "x ^ " << convertV2fToV2u(boardRectangles[1][i].getPosition()).y 
			<< "x : " << convertV2fToV2u(mCurrentSquare.getPosition()).x << "x ^ " << convertV2fToV2u(mCurrentSquare.getPosition()).y << "y" << std::endl;
			
			if (convertV2fToV2u(boardRectangles[1][i].getPosition()) == convertV2fToV2u(mCurrentSquare.getPosition()))
			{
				mHasNotMoved = 1;
				break;
			} 
		
		}
		}
		
		
	}
	
	
	
	
	
	
	return SearchAlgos::getPawnMovesBitmap(pieces, boardRectangles, mCurrentSquare, mColor, mHasNotMoved);
}