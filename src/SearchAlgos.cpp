#include "SearchAlgos.h"
#include "MyMaths.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstdint>

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

    std::pair<unsigned long long, unsigned long long> getDiagonalMovesBitmap(const unsigned long long friendlyPieces, const unsigned long long enemyPieces,
                                                                             const sf::RectangleShape &currentSquare)
    {

        unsigned int row {static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y))};
        unsigned int col {static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x))};
        uint8_t currentBitSquare = {static_cast<uint8_t>(getSquareBitmap(currentSquare) >> ((7 - row) * 8))};

        uint64_t validSquaresBit = {};

        bool stopRightSearch {};
        bool stopLeftSearch {};

        for (size_t i = row; i > 0; i--)
        {

            if (i - 1 < col && !stopLeftSearch)
            {
                //std::bitset<64> occupied {enemyPieces | friendlyPieces};
                //std::bitset<64> current {static_cast<uint64_t>(currentBitSquare)<< i << i*8};
                //std::cout << occupied << std::endl;
                //std::cout << current << '\n' <<  std::endl;
                if (((enemyPieces | friendlyPieces) & static_cast<uint64_t>(currentBitSquare) << i << i*8 << (7 - row)*8) != 0)
                {
                    for (size_t j = row-i; j > i; j--)
                    {
                        validSquaresBit = validSquaresBit ^ (static_cast<uint64_t>(currentBitSquare) << (i+j) << (j*8));
                    }
                }

                validSquaresBit = validSquaresBit | (currentBitSquare << i);

            }
            if (col + i < 8 && !stopRightSearch)
            {
                std::bitset<64> occupied {enemyPieces | friendlyPieces};
                std::bitset<64> current {static_cast<uint64_t>(currentBitSquare) >> i << i*8};
                std::cout << occupied << std::endl;
                std::cout << current << '\n' << std::endl;
                if (((enemyPieces | friendlyPieces) & static_cast<uint64_t>(currentBitSquare) >> i << i*8 << (7 - row)*8) != 0)
                {
                    stopRightSearch = true;
                }
                
                validSquaresBit = validSquaresBit | (currentBitSquare >> i);
                
            }
            validSquaresBit = validSquaresBit << 8;
        }
        validSquaresBit = validSquaresBit << 8;
        for (size_t i = 1; i < (8 - row); i++)
        {
            if (i - 1 < col)
            {
                validSquaresBit = validSquaresBit | (currentBitSquare << i);
            }
            if (i + col < 8)
            {
                validSquaresBit = validSquaresBit | (currentBitSquare >> i);
            }
            if (i == 7 - row)
            {
                break;
            }
            
            validSquaresBit = validSquaresBit << 8;
        }
        /*
        std::bitset<64> valid {validSquaresBit};
        std::bitset<64> current {currentBitSquare};
        std::bitset<64> enemy {enemyPieces};
        std::bitset<64> friendly {friendlyPieces};
        std::cout << current << std::endl;
        std::cout << enemy << std::endl;
        std::cout << friendly << std::endl;
        std::cout << valid << std::endl;
        */

        return std::make_pair((validSquaresBit ^ friendlyPieces) & validSquaresBit, validSquaresBit & friendlyPieces);
    }

    std::pair<unsigned long long, unsigned long long> getKnightMovesBitmap(const unsigned long long friendlyPieces, const unsigned long long enemyPieces,
                                                                           const sf::RectangleShape &currentSquare)
    {

        uint8_t knightMovesTop    {0b01010000};
        uint8_t knightMovesMidTop {0b10001000};
        uint8_t knightMovesMidBot {0b10001000};
        uint8_t knightMovesBot    {0b01010000};

        unsigned int row {static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y))};
        unsigned int col {static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x))};

        uint64_t validSquaresBit = {};

        if (col < 2)
        {
            knightMovesTop    = knightMovesTop    << (2 - col);
            knightMovesMidTop = knightMovesMidTop << (2 - col);
            knightMovesMidBot = knightMovesMidBot << (2 - col);
            knightMovesBot    = knightMovesBot    << (2 - col);
        }
        else
        {
            knightMovesTop    = knightMovesTop    >> (col - 2);
            knightMovesMidTop = knightMovesMidTop >> (col - 2);
            knightMovesMidBot = knightMovesMidBot >> (col - 2);
            knightMovesBot    = knightMovesBot    >> (col - 2);
        }

        validSquaresBit = (validSquaresBit | knightMovesTop)    << 8;
        validSquaresBit = (validSquaresBit | knightMovesMidTop) << 8;
        validSquaresBit = validSquaresBit;

        if (row < 6)
        {
            validSquaresBit = ((validSquaresBit << 8) | knightMovesMidBot) << 8;
            validSquaresBit = (validSquaresBit | knightMovesBot);
            validSquaresBit = validSquaresBit << ((5 - row) * 8);
        }
        else if (row < 7)
        {
            validSquaresBit = ((validSquaresBit << 8) | knightMovesMidBot);
        }

        //std::bitset<64> friendly {friendlyPieces};
        //std::bitset<64> valid {validSquaresBit};
        //std::bitset<64> result {(validSquaresBit ^ friendlyPieces) & validSquaresBit};
        //std::cout << friendly << std::endl;
        //std::cout << valid << std::endl;
        
        //std::cout << result << std::endl;

        std::cout << enemyPieces << std::endl;


        return std::make_pair((validSquaresBit ^ friendlyPieces) & validSquaresBit, validSquaresBit & friendlyPieces);
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
                                          const sf::RectangleShape &currentSquare, const bool &color, const bool &hasNotMoved) 
    {
        std::array<std::array<bool, 8>, 8> validSquares = {};

        sf::Vector2u position(static_cast<unsigned int>(std::round(currentSquare.getPosition().x / currentSquare.getSize().x)),
                              static_cast<unsigned int>(std::round(currentSquare.getPosition().y / currentSquare.getSize().y)));

        
        if (hasNotMoved == 1)
        {
            if (color)
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
            else if (!color)
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

        }
        else if (position.y > 0 && position.y < 7)
        {
            
            if (color)
            {
                validSquares[position.y - 1][position.x] = 1;
                for (auto &piece : pieces)
                {
                    if (convertV2fToV2u(boardRectangles[position.y - 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                    {
                        std::cout << "match found" << std::endl;
                        validSquares[position.y - 1][position.x ] = 0;
                        break;
                    }
                }
            }
            else if (!color)
            {
                validSquares[position.y + 1][position.x ] = 1;
                for (auto &piece : pieces)
                {
                    if (convertV2fToV2u(boardRectangles[position.y + 1][position.x].getPosition()) == convertV2fToV2u(piece->mCurrentSquare.getPosition()))
                    {
                        std::cout << "match found" << std::endl;
                        validSquares[position.y + 1][position.x ] = 0;
                        break;
                    }
                }
            }
        }      

        displayValidSquares(validSquares);

        std::cout << position.x << "x" << position.y << '\n' << std::endl;

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