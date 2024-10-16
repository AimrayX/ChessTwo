#include "Board.h"

#include <iostream>

Board::Board(sf::Vector2u windowSize)
    : mWidth{}, mHeight{}, mBoardTexture(), mPieces {} {

    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(windowSize.x, windowSize.y)), true)); // color true or false as needed
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(windowSize.x, windowSize.y)), true));
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(windowSize.x, windowSize.y)), false));
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(windowSize.x, windowSize.y)), false));

    std::cout << "constructor called : " << windowSize.x << std::endl;
    updateBoardTexture(windowSize);
    
}

void Board::updateBoardTexture(sf::Vector2u windowSize) {
    mBoardTexture.clear();
    float minDimension = static_cast<float>(std::min(windowSize.x, windowSize.y));
    mWidth = minDimension;
    mHeight = minDimension;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(mWidth / 8.0f, mHeight / 8.0f));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((j + i) % 2 == 0) {
                rectangle.setFillColor(sf::Color(247, 247, 247));

            }
            else {
                rectangle.setFillColor(sf::Color(196, 140, 108));
            }
            rectangle.setPosition(static_cast<float>(j) * (mWidth / 8.0f), static_cast<float>(i) * (mHeight / 8.0f));
            mBoardTexture.push_back(rectangle);
            /*
            std::cout << "added rectangle: " << i+j << " " << rectangle.getSize().x << " x " 
            << rectangle.getSize().y << " vector size: " << mBoardTexture.size() << std::endl;
            */
        }
    }
}

