#include "Board.h"

#include <iostream>

Board::Board(sf::Vector2u windowSize)
    : mWidth{}, mHeight{}, mBoardSize{}, mBoardRectangles() {

    

    std::cout << "constructor called : " << windowSize.x << std::endl;
    updateBoard(windowSize);
    
}

void Board::updateBoard(sf::Vector2u windowSize) {
    mBoardSize = static_cast<float>(std::min(windowSize.x, windowSize.y));
    mWidth = mBoardSize;
    mHeight = mBoardSize;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(mWidth / 8.0f, mHeight / 8.0f));
    for (unsigned int i = 0; i < 8; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if ((j + i) % 2 == 0) {
                rectangle.setFillColor(sf::Color(247, 247, 247));

            }
            else {
                rectangle.setFillColor(sf::Color(196, 140, 108));
            }
            rectangle.setPosition(static_cast<float>(j) * (mWidth / 8.0f), static_cast<float>(i) * (mHeight / 8.0f));
            mBoardRectangles[j][i] = rectangle;
            
            //std::cout << "added rectangle: " << i+j << " " << rectangle.getSize().x << " x " 
            //<< rectangle.getSize().y << " vector size: " << mBoardTexture.size() << std::endl;
            
        }
    }
}

