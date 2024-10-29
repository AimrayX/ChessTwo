#include "Piece.h"
#include "SearchAlgos.h"
#include <iostream>

Piece::Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare)
	: mTextureFile{"../assets/pieces.png"}, mTextureWidth{334}, mTextureHeight{334},
	  mTexturePositionX{texturePositionX}, mTexturePositionY{texturePositionY}, mTexture{},
	  mSprite{}, mValue{value}, mColor{color}, mCurrentSquare{initialSquare}, bitmapValidSquares{}, bitmapCurrentSquare{}
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

}

Piece::~Piece(){

}

void Piece::calcBitmap(std::vector<std::shared_ptr<Piece>> &mPieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) {
	bitmapValidSquares = calcMovesBitmap(mPieces, boardRectangles, mColor);
	bitmapCurrentSquare = SearchAlgos::getSquareBitmap(mCurrentSquare);
}

std::pair<bool, std::shared_ptr<Piece>> Piece::move(std::vector<std::shared_ptr<Piece>> &mPieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles, sf::RectangleShape &targetSquare)
{

	if ((calcMovesBitmap(mPieces, boardRectangles, mColor) & SearchAlgos::getSquareBitmap(targetSquare)) != 0)
	{
		std::cout << "moved Piece\n";
		
		for (auto &piece : mPieces)
		{
			if ((piece->bitmapCurrentSquare & SearchAlgos::getSquareBitmap(targetSquare)) != 0)
			{
				std::cout << "captured piece\n";
				mCurrentSquare = targetSquare;
				return std::make_pair(0, piece);
			}
			
		}
		std::cout << "nothing captured\n";
		mCurrentSquare = targetSquare;
		return std::make_pair(0, nullptr);
	}

	std::cout << "not a valid move\n";
	return std::make_pair(1, nullptr);
}
