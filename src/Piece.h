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
	bool mHasMoved;
	bool mHasPrevMoved;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mValue;
	bool mColor;
	sf::RectangleShape mCurrentSquare;
	sf::RectangleShape mPreviousSquare;
	unsigned long long mBitmapValidSquares;
	unsigned long long mBitmapAttackingSquares;
	unsigned long long mBitmapCurrentSquare;
	bool isProtected;

	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare);

	virtual ~Piece();

	std::pair<bool, std::shared_ptr<Piece>> move(std::vector<std::shared_ptr<Piece>> &mPieces, sf::RectangleShape &targetSquare);

	virtual void calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
								 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles) = 0;
};
