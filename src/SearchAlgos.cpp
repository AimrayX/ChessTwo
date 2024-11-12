#include "SearchAlgos.h"
#include "MyMaths.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>

namespace SearchAlgos
{
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
            if (piece->mColor != color && (getSquareBitmap(boardRectangle) & piece->mBitmapValidSquares) != 0)
                {
                    
                    std::cout << "King can't move there. Square under attack!" << std::endl;
                    return 1;
                }
        }
        return 0;
    }

}