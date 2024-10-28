#include "Game.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include <iostream>
#include <iomanip>
#include <bitset>

Game::Game() 
    : board(sf::Vector2u(700, 700)), mPieces{}, activePiece{}, renderer(700, 700, "Chess", board.mBoardRectangles), dragging {false}, 
      bitmapWhitePieces{0b0000000000000000000000000000000000000000000000001111111111111111}, 
      bitmapBlackPieces{0b1111111111111111000000000000000000000000000000000000000000000000} {
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][0]));
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][7]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][2]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][5]));
    mPieces.emplace_back(std::make_shared<Queen> (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][3]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][6]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][1]));
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][0]));
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][7]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][2]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][5]));
    mPieces.emplace_back(std::make_shared<Queen> (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][4]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][6]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][1]));
    
    //load menu()
    for (auto &piece : mPieces)
    {
        piece->calcBitmap(mPieces, board.mBoardRectangles);
    }
    
    run();
}

//load menu()
//  init game()

void Game::run() {
    while (renderer.mWindow.isOpen())
    {
        sf::Event event;
        while (renderer.mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderer.mWindow.close();
            if (event.type == sf::Event::Resized) {
                renderer.updateView();
                board.updateBoard(renderer.mWindowSize);
                renderer.updatePieceSprites(board.mBoardSize, mPieces);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "clicked" << std::endl;

                if (activePiece == nullptr)
                {
                    activePiece = getPieceOnPosition(getMousePosition());
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {

                if (activePiece != nullptr)
                {
                    
                    if (activePiece == getPieceOnPosition(getMousePosition()))
                    {
                        //activePiece->mSprite.setPosition(activePiece->currentSquare.getPosition());
                        std::cout << "piece selected" << std::endl;
                        
                        if (activePiece != nullptr)
                        {
                            renderer.highlightValidSquares(activePiece);
                        }
                        
                    } else
                    {              
                        std::pair<bool, std::shared_ptr<Piece>> moveReturn {activePiece->move(mPieces, board.mBoardRectangles, 
                                                              getSquareOnPosition(getMousePosition()))};
                        
                        renderer.deHighlightValidSquares(activePiece);

                        if (moveReturn.first != 1 && moveReturn.second != nullptr)
                        {
                            for (auto it = mPieces.begin(); it != mPieces.end(); it++)
                            {
                                if (it->get() == moveReturn.second.get())
                                {
                                    it = mPieces.erase(it);
                                    activePiece = nullptr;
                                    break;
                                }
                                
                            }
                            updateAllPiecesBitmaps();
                            
                        }
                        else if (!moveReturn.first)
                        {
                            updateAllPiecesBitmaps();
                            activePiece = nullptr;
                        }
                        activePiece = nullptr;
                        
                        renderer.updatePieceSprites(board.mBoardSize, mPieces);
                        
                    }
                
                } else
                {
                    std::cout << "nothing selected" << std::endl;
                } 
            }
        }
        
        renderer.draw();

    }
}

sf::Vector2f Game::getMousePosition(sf::Event &event) {

    return sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
}

sf::Vector2f Game::getMousePosition() {
    if (renderer.mWindowSize.x > renderer.mWindowSize.y) {
        return sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).x) - (static_cast<float>(renderer.mWindowSize.x) - board.mBoardSize) / 2.0f, static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).y));
    } else {
        return sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).x), static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).y) - (static_cast<float>(renderer.mWindowSize.y) - board.mBoardSize) / 2.0f);
    }
    
}

std::shared_ptr<Piece> Game::getPieceOnPosition(sf::Vector2f mousePosition) {
    //float inset {board.mBoardSize / 8.0f - (board.mBoardSize / 20.0f)};
    for (auto &piece : mPieces) {

        if (   (mousePosition.x > piece->mCurrentSquare.getPosition().x) 
            && (mousePosition.y > piece->mCurrentSquare.getPosition().y)
            && (mousePosition.x < (piece->mCurrentSquare.getPosition().x + piece->mCurrentSquare.getSize().x)) 
            && (mousePosition.y < (piece->mCurrentSquare.getPosition().y + piece->mCurrentSquare.getSize().y))) {

                std::cout << "clicked on piece" << std::endl;
                return piece;

            }

    }

    return nullptr;
    
}

sf::RectangleShape &Game::getSquareOnPosition(sf::Vector2f mousePosition) {

    for (auto &i : board.mBoardRectangles) {
        
        for (auto &rect : i) {
            if (   (mousePosition.x > rect.getPosition().x) 
            && (mousePosition.y > rect.getPosition().y)
            && (mousePosition.x < (rect.getPosition().x + rect.getSize().x)) 
            && (mousePosition.y < (rect.getPosition().y + rect.getSize().y))) {

                std::cout << "clicked on square " << rect.getPosition().x << "x * " << rect.getPosition().y  << "y" << std::endl;
                return rect;

            }
        }
        

    }

    return board.mBoardRectangles[3][3];
}

void Game::dragPiece() {
    std::cout << "dragging" << std::endl;
    activePiece->mSprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(renderer.mWindow)));
}

void Game::updateAllPiecesBitmaps() {
    for (auto &piece : mPieces)
    {
        piece->calcBitmap(mPieces, board.mBoardRectangles);
    }
}

void Game::getPositionCords() {
    for (auto &piece : mPieces)
    {
        std::cout << piece->mCurrentSquare.getPosition().x << "x x " << piece->mCurrentSquare.getPosition().y << "y : " 
                  << piece->mSprite.getPosition().x << "x x " << piece->mSprite.getPosition().y << "y" << std::endl;
    }

    for (auto &piece : mPieces)
    {
        std::cout << std::setw(8);
        std::cout << std::bitset<64>(piece->bitmapValidSquares) << "\n\n" << std::endl;
    }

}