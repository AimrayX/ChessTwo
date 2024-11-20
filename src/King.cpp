#include "King.h"
#include "SearchAlgos.h"
#include "MyMaths.h"
#include <array>
#include <cmath>
#include <iostream>

King::King(float boardSize, bool color, sf::RectangleShape initalSquare)
	: Piece(boardSize, 0 * 334, !color * 344, 1, 0, color, initalSquare)
{
}

void King::calcMovesBitmap(std::vector<std::shared_ptr<Piece>> &pieces, 
										 std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles)
{

    mBitmapCurrentSquare = SearchAlgos::getSquareBitmap(mCurrentSquare);

	std::array<std::array<bool, 8>, 8> validSquares = {};
    std::array<std::array<bool, 8>, 8> attackingSquares = {};

    sf::Vector2u position(static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().x / mCurrentSquare.getSize().x)),
                            static_cast<unsigned int>(std::round(mCurrentSquare.getPosition().y / mCurrentSquare.getSize().y)));

    if (position.y + 1 < 8 && position.x + 1 < 8)
    {
        validSquares[position.y + 1][position.x + 1] = 1;
        attackingSquares[position.y + 1][position.x + 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y + 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y + 1][position.x + 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y + 1][position.x + 1] = 0;
                    break;
                }
                
            }
        }
        if (validSquares[position.y + 1][position.x + 1] != 0)
        {
            if (SearchAlgos::checkIfSquareIsAttacked(mColor, boardRectangles[position.y + 1][position.x + 1], pieces))
            {
                validSquares[position.y + 1][position.x + 1] = 0;
            }
        }
    }

    if (position.x + 1 < 8)
    {
        validSquares[position.y][position.x + 1] = 1;
        attackingSquares[position.y][position.x + 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y][position.x + 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y][position.x + 1] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y][position.x + 1] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y][position.x + 1], pieces))
            {
                validSquares[position.y][position.x + 1] = 0;
            }
        }
    }

    if (position.y > 0 && position.x + 1 < 8)
    {
        validSquares[position.y - 1][position.x + 1] = 1;
        attackingSquares[position.y - 1][position.x + 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y - 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y - 1][position.x + 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y - 1][position.x + 1] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y - 1][position.x + 1] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y - 1][position.x + 1], pieces))
            {
                validSquares[position.y - 1][position.x + 1] = 0;
            }
        }
    }

    if (position.y > 0)
    {
        validSquares[position.y - 1][position.x] = 1;
        attackingSquares[position.y - 1][position.x] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y - 1][position.x] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y - 1][position.x] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y - 1][position.x] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y - 1][position.x], pieces))
            {
                validSquares[position.y - 1][position.x] = 0;
            }
        }
    }

    if (position.y > 0 && position.x > 0)
    {
        validSquares[position.y - 1][position.x - 1] = 1;
        attackingSquares[position.y - 1][position.x - 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y - 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y - 1][position.x - 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y - 1][position.x - 1] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y - 1][position.x - 1] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y - 1][position.x - 1], pieces))
            {
                validSquares[position.y - 1][position.x - 1] = 0;
            }
        }
    }

    if (position.x > 0)
    {
        validSquares[position.y][position.x - 1] = 1;
        attackingSquares[position.y][position.x - 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y][position.x - 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y][position.x - 1] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y][position.x - 1] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y][position.x - 1], pieces))
            {
                validSquares[position.y][position.x - 1] = 0;
            }
        }
    }

    if (position.y + 1 < 8 && position.x > 0)
    {
        validSquares[position.y + 1][position.x - 1] = 1;
        attackingSquares[position.y + 1][position.x - 1] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y + 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y + 1][position.x - 1] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y + 1][position.x - 1] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y + 1][position.x - 1] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y + 1][position.x - 1], pieces))
            {
                validSquares[position.y + 1][position.x - 1] = 0;
            }
        }
    }

    if (position.y + 1 < 8)
    {
        validSquares[position.y + 1][position.x] = 1;
        attackingSquares[position.y + 1][position.x] = 1;
        for (auto &piece : pieces)
        {
            if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
            {
                //std::cout << "match found" << std::endl;

                if (piece->mColor == mColor)
                {
                    validSquares[position.y + 1][position.x] = 0;
                    piece->isProtected = 1;
                    break;
                }
                if (piece->isProtected == 1)
                {
                    validSquares[position.y + 1][position.x] = 0;
                    break;
                }
            }
        }
        if (validSquares[position.y + 1][position.x] != 0)
        {
            if (checkIfSquareIsAttacked(mColor, boardRectangles[position.y + 1][position.x], pieces))
            {
                validSquares[position.y + 1][position.x] = 0;
            }
        }
        
    }

    //std::cout << position.x << "x" << position.y << '\n' << std::endl;

    mBitmapValidSquares = SearchAlgos::convert2DArrayToBitmap(validSquares);
    mBitmapAttackingSquares = SearchAlgos::convert2DArrayToBitmap(attackingSquares);
}

bool King::checkIfSquareIsAttacked(const bool &color ,const sf::RectangleShape &boardRectangle, 
                                 const std::vector<std::shared_ptr<Piece>> &pieces) 
    {
        for (auto &piece : pieces)
        {
            if (piece->mColor != color && (SearchAlgos::getSquareBitmap(boardRectangle) & piece->mBitmapAttackingSquares) != 0)
                {
                    
                    std::cout << "King can't move there. Square under attack!" << std::endl;
                    return 1;
                }
        }
        return 0;
    }