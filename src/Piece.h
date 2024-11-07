#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class Piece
{

private:
	std::string mTextureFile;
	int mTextureWidth;
	int mTextureHeight;
	int mTexturePositionX;
	int mTexturePositionY;

public:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mValue;
	bool mColor;
	sf::RectangleShape mCurrentSquare;
	unsigned long long bitmapValidSquares;
	unsigned long long bitmapCurrentSquare;
	unsigned long long protectedPiecesSquares;
	bool isProtected;

	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare);

	virtual ~Piece();

	std::pair<bool, unsigned long long> move(const unsigned long long &blackPieces, const unsigned long long &whitePieces, const sf::RectangleShape &targetSquare);

	void calcBitmap(const unsigned long long &blackPieces, const unsigned long long &whitePieces);

	virtual std::pair<unsigned long long, unsigned long long> calcMovesBitmap(unsigned long long blackPieces, unsigned long long whitePieces) = 0;
};
