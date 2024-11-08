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

protected:
    bool mHasMoved;

public:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mValue;
	bool mColor;
	sf::RectangleShape mCurrentSquare;
	unsigned long long bitmapValidSquares;
	unsigned long long bitmapCurrentSquare;
	bool isProtected;

	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare);

	virtual ~Piece();

	std::pair<bool, std::shared_ptr<Piece>> move(std::vector<std::shared_ptr<Piece>> &mPieces, std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles, sf::RectangleShape &targetSquare);

	void calcBitmap(std::vector<std::shared_ptr<Piece>> &mPieces, 
					std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles);

	virtual unsigned long long calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
											   std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) = 0;
};
