#include "Piece.h"
#include "SearchAlgos.h"
#include <iostream>

#include <bitset>

Piece::Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare)
	: mTextureFile{"../assets/pieces.png"}, mTextureWidth{334}, mTextureHeight{334},
	  mTexturePositionX{texturePositionX}, mTexturePositionY{texturePositionY}, mTexture{},
	  mSprite{}, mValue{value}, mColor{color}, mCurrentSquare{initialSquare}, bitmapValidSquares{}, bitmapCurrentSquare{}, protectedPiecesSquares{},isProtected{}
{

	// std::cout << "loaded with exit code: " << mTexture.loadFromFile(mTextureFile) << std::endl;

	if (!mTexture.loadFromFile(mTextureFile))
	{
		mTexture.loadFromFile("assets/pieces.png");
	}

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(mTexturePositionX, mTexturePositionY, mTextureWidth, mTextureHeight));
	mSprite.setScale((boardSize / 8.0f) / 334.0f, (boardSize / 8.0f) / 334.0f);
	mSprite.setPosition(mCurrentSquare.getPosition());

	bitmapCurrentSquare = SearchAlgos::getSquareBitmap(mCurrentSquare);

}

Piece::~Piece(){

}

void Piece::calcBitmap(const unsigned long long &blackPieces, const unsigned long long &whitePieces) {

	bitmapCurrentSquare = SearchAlgos::getSquareBitmap(mCurrentSquare);
	std::pair<unsigned long long, unsigned long long> temp {calcMovesBitmap(blackPieces, whitePieces)};
	bitmapValidSquares = temp.first;
	protectedPiecesSquares = temp.second;
	
}

std::pair<bool, unsigned long long> Piece::move(const unsigned long long &blackPieces, const unsigned long long &whitePieces, const sf::RectangleShape &targetSquare)
{
	
	std::pair<unsigned long long, unsigned long long> tempValidMoves {calcMovesBitmap(blackPieces, whitePieces)};
	unsigned long long tempTargetSquare {SearchAlgos::getSquareBitmap(targetSquare)};

	//std::bitset<64> valid {tempValidMoves.first};
	//std::cout << "in piece function : " << valid << std::endl;
	

	if ((tempValidMoves.first & tempTargetSquare) != 0)
	{
		
		std::cout << "moved Piece\n";
		if (!mColor)
		{
			if ((whitePieces & tempTargetSquare) != 0)
			{
				std::cout << "captured piece\n";
				mCurrentSquare = targetSquare;
				bitmapCurrentSquare = tempTargetSquare;
				return std::make_pair(0, tempTargetSquare);
			}
			else
			{
				std::cout << "nothing captured\n";
				mCurrentSquare = targetSquare;
				bitmapCurrentSquare = tempTargetSquare;
				return std::make_pair(0, 0);
			}
		}
		if (mColor)
		{
			if ((blackPieces & tempTargetSquare) != 0)
			{
				std::cout << "captured piece\n";
				mCurrentSquare = targetSquare;
				bitmapCurrentSquare = tempTargetSquare;
				return std::make_pair(0, tempTargetSquare);
			}
			else
			{
				std::cout << "nothing captured\n";
				mCurrentSquare = targetSquare;
				bitmapCurrentSquare = tempTargetSquare;
				return std::make_pair(0, 0);
			}
		}
	}
	std::cout << "not a valid move\n";
	return std::make_pair(1, 0);
}
