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
	long long bitMapValidSquares;

	Piece(float boardSize, int texturePositionX, int texturePositionY, int value, bool color, sf::RectangleShape initialSquare);

	void move(sf::RectangleShape &square, long long enemyPieces, long long friendlyPieces);

	void setCurrentSquare(sf::RectangleShape &square);

	virtual long long getMovesBitmap(const long long &enemyPieces, const long long &friendlyPieces);
};

