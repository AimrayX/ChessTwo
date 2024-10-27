#include "SearchAlgos.h"
#include "MyMaths.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>

namespace SearchAlgo
{
    unsigned long long getHorizontalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, bool &color)
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)), 
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        for (size_t i = position.x; i < 7; i++)
        {
            validSquares[position.y][i+1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][i+1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[position.y][i+1] = 0;
                    }
                    else 
                    {
                        validSquares[position.y][i+1] = 1;
                    }
                    
                    
                    i = 7;
                    break;
                }
                //std::cout << convertV2fToV2u(boardRectangles[position.y][i+1].getPosition()).x << "x x " << convertV2fToV2u(boardRectangles[position.y][i+1].getPosition()).y
                //              << "y : " <<convertV2fToV2u(piece->mCurrentSquare.getPosition()).x << "x x " << convertV2fToV2u(piece->mCurrentSquare.getPosition()).y << "y" << std::endl;
            }
        }

        for (size_t i = position.x; i > 0; i--)
        {
            validSquares[position.y][i-1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][i-1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[position.y][i-1] = 0;
                    }
                    else
                    {
                        validSquares[position.y][i-1] = 1;
                    }
                    
                    
                    i = 1;
                    break;
                }
            }
        }

        for (size_t i = position.y; i < 7; i++)
        {
            for (auto &piece : pieces)
            {
                validSquares[i+1][position.x] = 1;
                if (convertV2fToV2u(boardRectangles[i+1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[i+1][position.x] = 0;
                    }
                    else
                    {
                        validSquares[i+1][position.x] = 1;
                    }
                    
                    i = 7;
                    break;
                }
            }
        }

        for (size_t i = position.y; i > 0; i--)
        {
            validSquares[i-1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[i-1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[i-1][position.x] = 0;
                    }
                    else
                    {
                        validSquares[i-1][position.x] = 1;
                    }
                    
                    i = 1;
                    break;
                }
            }
        }

        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++)
            {
                std::cout << validSquares[i][j];
            }
            std::cout << '\n';
        }

        unsigned long long bitmap{};

        for (auto &row : validSquares)
        {
            for (auto &col : row)
            {
                bitmap = bitmap << 1;
                if (col)
                {
                    bitmap += 1;
                }
            }
        }

        std::cout << position.x << "x" << position.y << std::endl;

        return bitmap;
    }


    unsigned long long getSquareBitmap(const sf::RectangleShape &square) 
    {
        sf::Vector2u position(static_cast<unsigned int>(std::round(square.getPosition().x / square.getSize().x)), 
                              static_cast<unsigned int>(std::round(square.getPosition().y / square.getSize().y)));

        return 0b1000000000000000000000000000000000000000000000000000000000000000ULL >> (position.y * 8 + position.x);
    }
}