#include "Renderer.h"
#include <iostream>

Renderer::Renderer(unsigned int w, unsigned int h, std::string windowName, std::array<std::array<sf::RectangleShape, 8>, 8> &BoardRectangles)
    : mWindowName {windowName}, mWindowSize(w, h), mBoardRectangles{BoardRectangles}, mPieceSprites{},  mWindow(sf::VideoMode(w, h), windowName) {

}


void Renderer::updateView() {
    mWindowSize = mWindow.getSize();
    unsigned int minDimension = std::min(mWindowSize.x, mWindowSize.y);
    sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);
    //std::cout << "called" << std::endl;

    if (mWindowSize.x > mWindowSize.y) {
        viewport.width = static_cast<float>(mWindowSize.y) / static_cast<float>(mWindowSize.x);
        viewport.left = (1.f - viewport.width) / 2.f;
    }
    else {
        viewport.height = static_cast<float>(mWindowSize.x) / static_cast<float>(mWindowSize.y);
        viewport.top = (1.f - viewport.height) / 2.f;
    }

    sf::View view(sf::FloatRect(0.f, 0.f, static_cast<float>(minDimension), static_cast<float>(minDimension)));
    view.setViewport(viewport);
    mWindow.setView(view);
    //std::cout << "view set to" << viewport.width << " x " << viewport.height << std::endl;
}

void Renderer::updatePieceSprites(float boardSize, std::vector<std::shared_ptr<Piece>> &pieces) {
    
    for (auto &i : pieces)
    {
        i->mSprite.setPosition(i->currentSquare.getPosition());
    }
    
    mPieceSprites.clear();
    for (auto &i : pieces)
    {
        mPieceSprites.push_back(i->mSprite);
        std::cout << i->currentSquare.getSize().x << " x " <<  i->currentSquare.getSize().y << '\n';
    }

    scalePieces(boardSize);
    
}


void Renderer::scalePieces(float boardSize){
    
    float scale {boardSize / 8.0f / 334.0f};

    for (auto &i : mPieceSprites)
    {
        i.setScale(scale, scale);
    }

}

void Renderer::draw() {

    mWindow.clear();
    
    for (auto &rect : mBoardRectangles) {
        for (auto &i : rect)
        {
            mWindow.draw(i);
        }
        
        //std::cout << "Position of rectangle printed: " << rect.getPosition().x << " size: " << rect.getSize().x << std::endl;
    }
    

    for (auto &i : mPieceSprites)
    {
        mWindow.draw(i);   
    }
    

    mWindow.display();

}