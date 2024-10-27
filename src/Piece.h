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

	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare);

	virtual ~Piece();

	void move(std::vector<std::shared_ptr<Piece>> &mPieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles, sf::RectangleShape &targetSquare);

	virtual unsigned long long calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) = 0;
};
