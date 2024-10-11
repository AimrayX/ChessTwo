#include "Board.h"
#include <iostream>

Board::Board(sf::Vector2u windowSize)
    : rook1(std::min(windowSize.x, windowSize.y)) {
    std::cout << "constructor called : " << windowSize.x << std::endl;
    updateBoardTexture(windowSize);
    initalizeStartingPosition();
}

void Board::updateBoardTexture(sf::Vector2u windowSize) {
    mBoardTexture.clear();
    unsigned int minDimension = std::min(windowSize.x, windowSize.y);
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
            rectangle.setPosition(sf::Vector2f(j * (mWidth / 8.0f), i * (mHeight / 8.0f)));
            mBoardTexture.push_back(rectangle);
            std::cout << "added rectangle: " << i+j << " " << rectangle.getSize().x << rectangle.getSize().y <<  std::endl;
        }
    }
}

void Board::initalizeStartingPosition() {
    
}
