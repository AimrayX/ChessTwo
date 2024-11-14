#include "Piece.h"
#include "SearchAlgos.h"
#include <iostream>

Piece::Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare)
	: mTextureFile{"../assets/pieces.png"}, mTextureWidth{334}, mTextureHeight{334},
	  mTexturePositionX{texturePositionX}, mTexturePositionY{texturePositionY}, mHasMoved{}, mHasPrevMoved{}, mTexture{},
	  mSprite{}, mValue{value}, mColor{color}, mCurrentSquare{initialSquare}, mPreviousSquare{initialSquare}, mBitmapValidSquares{}, mBitmapAttackingSquares{}, 
	  mBitmapCurrentSquare{}, isProtected{}
{

	if (!mTexture.loadFromFile(mTextureFile))
	{
		mTexture.loadFromFile("assets/pieces.png");
	}

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(mTexturePositionX, mTexturePositionY, mTextureWidth, mTextureHeight));
	mSprite.setScale((boardSize / 8.0f) / 334.0f, (boardSize / 8.0f) / 334.0f);
	mSprite.setPosition(mCurrentSquare.getPosition());

}

Piece::~Piece()
{
}

std::pair<bool, std::shared_ptr<Piece>> Piece::move(std::vector<std::shared_ptr<Piece>> &mPieces, sf::RectangleShape &targetSquare)
{

	if ((mBitmapValidSquares & SearchAlgos::getSquareBitmap(targetSquare)) != 0)
	{
		std::cout << "moved Piece\n";
		mHasPrevMoved = mHasMoved;
		mHasMoved = 1;
		for (auto &piece : mPieces)
		{
			if ((piece->mBitmapCurrentSquare & SearchAlgos::getSquareBitmap(targetSquare)) != 0)
			{
				std::cout << "captured piece\n";
				mPreviousSquare = mCurrentSquare;
				mCurrentSquare = targetSquare;
				return std::make_pair(0, piece);
			}
			
		}
		std::cout << "nothing captured\n";
		mPreviousSquare = mCurrentSquare;
		mCurrentSquare = targetSquare;
		return std::make_pair(0, nullptr);
	}

	std::cout << "not a valid move\n";
	return std::make_pair(1, nullptr);
}
