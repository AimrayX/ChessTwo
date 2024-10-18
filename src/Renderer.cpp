#include "Renderer.h"
#include <iostream>

Renderer::Renderer(unsigned int w, unsigned int h, std::string windowName)
    : mWindowName {windowName}, mWindowSize(w, h), mPiecesSprites{},  mWindow(sf::VideoMode(w, h), windowName), board(mWindowSize) {
    run();
}

void Renderer::run() {
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
            //std::cout << "Position of rectangle printed: " << rect.getPosition().x << " size: " << rect.getSize().x << std::endl;
        }

        for (size_t i = 0; i < mPiecesSprites.size(); i++)
        {
            mWindow.draw(mPiecesSprites[i]);
        }

        mWindow.display();
    }
}

void Renderer::updateView() {
    sf::Vector2u windowSize = mWindow.getSize();
    unsigned int minDimension = std::min(windowSize.x, windowSize.y);
    sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);
    std::cout << "called" << std::endl;

    if (windowSize.x > windowSize.y) {
        viewport.width = static_cast<float>(windowSize.y) / static_cast<float>(windowSize.x);
        viewport.left = (1.f - viewport.width) / 2.f;
    }
    else {
        viewport.height = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
        viewport.top = (1.f - viewport.height) / 2.f;
    }

    sf::View view(sf::FloatRect(0.f, 0.f, static_cast<float>(minDimension), static_cast<float>(minDimension)));
    view.setViewport(viewport);
    mWindow.setView(view);
    std::cout << "view set to" << viewport.width << " x " << viewport.height << std::endl;
}