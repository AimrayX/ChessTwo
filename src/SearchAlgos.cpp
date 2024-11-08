#include "SearchAlgos.h"
#include "MyMaths.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>

namespace SearchAlgos
{
    unsigned long long getHorizontalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                                const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                                const sf::RectangleShape &currentSquare, const bool &color)
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        for (size_t i = position.x; i < 7; i++)
        {
            validSquares[position.y][i + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][i + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[position.y][i + 1] = 0;
                        piece->isProtected = 1;
                    }
                    else
                    {
                        validSquares[position.y][i + 1] = 1;
                    }

                    i = 7;
                    break;
                }
            }
        }

        for (size_t i = position.x; i > 0; i--)
        {
            validSquares[position.y][i - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][i - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[position.y][i - 1] = 0;
                        piece->isProtected = 1;
                    }
                    else
                    {
                        validSquares[position.y][i - 1] = 1;
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
                validSquares[i + 1][position.x] = 1;
                if (convertV2fToV2u(boardRectangles[i + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[i + 1][position.x] = 0;
                        piece->isProtected = 1;
                    }
                    else
                    {
                        validSquares[i + 1][position.x] = 1;
                    }

                    i = 7;
                    break;
                }
            }
        }

        for (size_t i = position.y; i > 0; i--)
        {
            validSquares[i - 1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[i - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[i - 1][position.x] = 0;
                        piece->isProtected = 1;
                    }
                    else
                    {
                        validSquares[i - 1][position.x] = 1;
                    }

                    i = 1;
                    break;
                }
            }
        }

        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << std::endl;

        return convert2DArrayToBitmap(validSquares);
    }

    unsigned long long getDiagonalMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                              const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                              const sf::RectangleShape &currentSquare, const bool &color)
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        for (size_t x = position.x, y = position.y; x < 7 && y < 7; x++, y++)
        {
            validSquares[y + 1][x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[y + 1][x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[y + 1][x + 1] = 0;
                        piece->isProtected = 1;
                        std::cout << "Piece is protected" << std::endl;
                    }
                    else
                    {
                        validSquares[y + 1][x + 1] = 1;
                    }

                    x = 7;
                    break;
                }
            }
        }

        for (size_t x = position.x, y = position.y; x < 7 && y > 0; x++, y--)
        {
            validSquares[y - 1][x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[y - 1][x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[y - 1][x + 1] = 0;
                        piece->isProtected = 1;
                        std::cout << "Piece is protected" << std::endl;
                    }
                    else
                    {
                        validSquares[y - 1][x + 1] = 1;
                    }

                    x = 7;
                    break;
                }
            }
        }

        for (size_t y = position.y, x = position.x; x > 0 && y > 0; x--, y--)
        {
            for (auto &piece : pieces)
            {
                validSquares[y - 1][x - 1] = 1;
                if (convertV2fToV2u(boardRectangles[y - 1][x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[y - 1][x - 1] = 0;
                        piece->isProtected = 1;
                        std::cout << "Piece is protected" << std::endl;
                    }
                    else
                    {
                        validSquares[y - 1][x - 1] = 1;
                    }

                    x = 1;
                    break;
                }
            }
        }

        for (size_t y = position.y, x = position.x; x > 0 && y < 7; x--, y++)
        {
            validSquares[y + 1][x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[y + 1][x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    if (piece->mColor == color)
                    {
                        validSquares[y + 1][x - 1] = 0;
                        piece->isProtected = 1;
                        std::cout << "Piece is protected" << std::endl;
                    }
                    else
                    {
                        validSquares[y + 1][x - 1] = 1;
                    }

                    x = 1;
                    break;
                }
            }
        }

        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << '\n' << std::endl;

        return convert2DArrayToBitmap(validSquares);
    }

    unsigned long long getKnightMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                            const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                            const sf::RectangleShape &currentSquare, const bool &color)
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        if (position.y + 2 < 8 && position.x + 1 < 8)
        {
            validSquares[position.y + 2][position.x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 2][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y + 2][position.x + 1] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y + 1 < 8 && position.x + 2 < 8)
        {
            validSquares[position.y + 1][position.x + 2] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x + 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y + 1][position.x + 2] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y > 0 && position.x + 2 < 8)
        {
            validSquares[position.y - 1][position.x + 2] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x + 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y - 1][position.x + 2] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y > 1 && position.x + 1 < 8)
        {
            validSquares[position.y - 2][position.x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 2][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y - 2][position.x + 1] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y > 1 && position.x > 0)
        {
            validSquares[position.y - 2][position.x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 2][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y - 2][position.x - 1] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y > 0 && position.x > 1)
        {
            validSquares[position.y - 1][position.x - 2] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x - 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y - 1][position.x - 2] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y + 1 < 8 && position.x > 1)
        {
            validSquares[position.y + 1][position.x - 2] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x - 2].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y + 1][position.x - 2] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                }
            }
        }

        if (position.y + 2 < 8 && position.x > 0)
        {
            validSquares[position.y + 2][position.x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 2][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
                    {
                        validSquares[position.y + 2][position.x - 1] = 0;
                        piece->isProtected = 1;
                        break;
                    }
                    
                }
            }
        }

        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << '\n' << std::endl;

        return convert2DArrayToBitmap(validSquares);
    }

    unsigned long long getKingMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                          const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                          const sf::RectangleShape &currentSquare, const bool &color) 
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        if (position.y + 1 < 8 && position.x + 1 < 8)
        {
            validSquares[position.y + 1][position.x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y + 1][position.x + 1], pieces))
                {
                    validSquares[position.y + 1][position.x + 1] = 0;
                }
            }
        }

        if (position.x + 1 < 8)
        {
            validSquares[position.y][position.x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y][position.x + 1], pieces))
                {
                    validSquares[position.y][position.x + 1] = 0;
                }
            }
        }

        if (position.y > 0 && position.x + 1 < 8)
        {
            validSquares[position.y - 1][position.x + 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y - 1][position.x + 1], pieces))
                {
                    validSquares[position.y - 1][position.x + 1] = 0;
                }
            }
        }

        if (position.y > 0)
        {
            validSquares[position.y - 1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y - 1][position.x], pieces))
                {
                    validSquares[position.y - 1][position.x] = 0;
                }
            }
        }

        if (position.y > 0 && position.x > 0)
        {
            validSquares[position.y - 1][position.x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y - 1][position.x - 1], pieces))
                {
                    validSquares[position.y - 1][position.x - 1] = 0;
                }
            }
        }

        if (position.x > 0)
        {
            validSquares[position.y][position.x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y][position.x - 1], pieces))
                {
                    validSquares[position.y][position.x - 1] = 0;
                }
            }
        }

        if (position.y + 1 < 8 && position.x > 0)
        {
            validSquares[position.y + 1][position.x - 1] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y + 1][position.x - 1], pieces))
                {
                    validSquares[position.y + 1][position.x - 1] = 0;
                }
            }
        }

        if (position.y + 1 < 8)
        {
            validSquares[position.y + 1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;

                    if (piece->mColor == color)
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
                if (checkIfSquareIsAttacked(color, boardRectangles[position.y + 1][position.x], pieces))
                {
                    validSquares[position.y + 1][position.x] = 0;
                }
            }
            
        }

        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << '\n' << std::endl;

        return convert2DArrayToBitmap(validSquares);
    
    }

    unsigned long long getPawnMovesBitmap(const std::vector<std::shared_ptr<Piece>> &pieces,
                                          const std::array<std::array<sf::RectangleShape, 8>, 8> &boardRectangles,
                                          const sf::RectangleShape &currentSquare, const bool &color, const bool &hasMoved) 
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        if (hasMoved == 0 && color == 0)
        {
            validSquares[position.y + 1][position.x] = 1;
            validSquares[position.y + 2][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y + 1][position.x] = 0;
                    validSquares[position.y + 2][position.x] = 0;
                    break;
                }
                if (convertV2fToV2u(boardRectangles[position.y + 2][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y + 2][position.x] = 0;
                    break;
                }
            }
        }
        else if (hasMoved == 0 && color == 1)
        {
            validSquares[position.y - 1][position.x] = 1;
            validSquares[position.y - 2][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y - 1][position.x] = 0;
                    validSquares[position.y - 2][position.x] = 0;
                    break;
                }
                if (convertV2fToV2u(boardRectangles[position.y - 2][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y - 2][position.x] = 0;
                    break;
                }
            }
        }
        else if (position.y + 1 < 8 && color == 0)
        {
            validSquares[position.y + 1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y + 1][position.x] = 0;
                    break;
                }
            }
        }
        else if (position.y > 0 && color == 1)
        {
            validSquares[position.y - 1][position.x] = 1;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y - 1][position.x] = 0;
                    break;
                }
            }
        }
        if (color == 0 && position.x < 7 && position.x > 0)
        {
            validSquares[position.y + 1][position.x + 1] = 0;
            validSquares[position.y + 1][position.x - 1] = 0;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != color)
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y + 1][position.x + 1] = 1;
                }
                if (convertV2fToV2u(boardRectangles[position.y + 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != color)
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y + 1][position.x - 1] = 1;
                }

            }
        }
        else if (color == 1 && position.x < 7 && position.x > 0)
        {
            validSquares[position.y - 1][position.x + 1] = 0;
            validSquares[position.y - 1][position.x - 1] = 0;
            for (auto &piece : pieces)
            {
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x + 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != color)
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y - 1][position.x + 1] = 1;
                }
                if (convertV2fToV2u(boardRectangles[position.y - 1][position.x - 1].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()) && piece->mColor != color)
                {
                    std::cout << "match found" << std::endl;
                    validSquares[position.y - 1][position.x - 1] = 1;
                }
            }
        }


        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << "  " << color << '\n' << std::endl;

        return convert2DArrayToBitmap(validSquares);                          
    }

    unsigned long long getSquareBitmap(const sf::RectangleShape &square)
    {
        sf::Vector2u position(static_cast<unsigned int>(std::round(square.getPosition().x / square.getSize().x)),
                              static_cast<unsigned int>(std::round(square.getPosition().y / square.getSize().y)));

        return 0b1000000000000000000000000000000000000000000000000000000000000000ULL >> (position.y * 8 + position.x);
    }

    void displayValidSquares(std::array<std::array<bool, 8>, 8> &validSquares)
    {
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++)
            {
                std::cout << validSquares[i][j];
            }
            std::cout << '\n';
        }
    }

    unsigned long long convert2DArrayToBitmap(std::array<std::array<bool, 8>, 8> &validSquares)
    {

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
        return bitmap;
    }

    bool checkIfSquareIsAttacked(const bool &color ,const sf::RectangleShape &boardRectangle, 
                                 const std::vector<std::shared_ptr<Piece>> &pieces) 
    {
        for (auto &piece : pieces)
        {
            if (piece->mColor != color && (getSquareBitmap(boardRectangle) & piece->bitmapValidSquares) != 0)
                {
                    
                    std::cout << "King can't move there. Square under attack!" << std::endl;
                    return 1;
                }
        }
        return 0;
    }

}