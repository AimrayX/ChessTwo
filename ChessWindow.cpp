#include "ChessWindow.h"
#include <iostream>

ChessWindow::ChessWindow(int w, int h)
    : mWindowSize(w, h), mWindow(sf::VideoMode(w, h), "Chess SFML"), board(mWindowSize) {
    run();
}

void ChessWindow::run() {
    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();
            if (event.type == sf::Event::Resized) {
                updateView();
                board.updateBoardTexture(mWindow.getSize());
                std::cout << "updated" << std::endl;
            }
        }

        mWindow.clear();
        for (sf::RectangleShape rect : board.mBoardTexture) {
            mWindow.draw(rect);
        }
        mWindow.draw(board.rook1.sprite);
        mWindow.display();
    }
}

void ChessWindow::updateView() {
    sf::Vector2u windowSize = mWindow.getSize();
    unsigned int minDimension = std::min(windowSize.x, windowSize.y);
    sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);
    std::cout << "called" << std::endl;

    if (windowSize.x > windowSize.y) {
        viewport.width = windowSize.y / static_cast<float>(windowSize.x);
        viewport.left = (1.f - viewport.width) / 2.f;
    }
    else {
        viewport.height = windowSize.x / static_cast<float>(windowSize.y);
        viewport.top = (1.f - viewport.height) / 2.f;
    }

    sf::View view(sf::FloatRect(0.f, 0.f, minDimension, minDimension));
    view.setViewport(viewport);
    mWindow.setView(view);
}