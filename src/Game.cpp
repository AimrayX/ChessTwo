#include "Game.h"
#include "iostream"

Game::Game() 
    : board(sf::Vector2u(800, 800)), mPieces{}, activePiece{}, renderer(800, 800, "Chess", board.mBoardRectangles), dragging {false} {
    mPieces.emplace_back(std::make_shared<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[0][0]));
    mPieces.push_back(std::make_shared<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][0]));
    mPieces.push_back(std::make_shared<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][7]));
    mPieces.push_back(std::make_shared<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[7][7]));
    //load menu()
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
                
                
                if (activePiece != nullptr) {
                    dragging = true;
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                activePiece = getPieceOnPosition(getMousePosition(event));
                dragging = false;
                

                if (activePiece != nullptr)
                {
                    activePiece->mSprite.setPosition(activePiece->currentSquare.getPosition());
                    if (activePiece == getPieceOnPosition(getMousePosition(event)))
                    {
                        std::cout << "piece selected" << std::endl;
                    } else
                    {
                        //check for valid square and if not then set back to original position otherwise
                        std::cout << "piece dragged" << std::endl;

                    }
                
                } else
                {
                    std::cout << "nothing selected" << std::endl;
                } 
            }
            if (dragging) {
                dragPiece();
            }
        }
        
        renderer.draw();

    }
}

sf::Vector2f Game::getMousePosition(sf::Event &event) {

    return sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
}

std::shared_ptr<Piece> Game::getPieceOnPosition(sf::Vector2f mousePosition) {
    //float inset {board.mBoardSize / 8.0f - (board.mBoardSize / 20.0f)};
    for (auto &i : mPieces) {

        if (   (mousePosition.x > i->currentSquare.getPosition().x) 
            && (mousePosition.y > i->currentSquare.getPosition().y)
            && (mousePosition.x < (i->currentSquare.getPosition().x + i->currentSquare.getSize().x)) 
            && (mousePosition.y < (i->currentSquare.getPosition().y + i->currentSquare.getSize().y))) {

                std::cout << "clicked on piece" << std::endl;
                return i;

            }

    }

    return nullptr;
    
}

void Game::dragPiece() {
    std::cout << "dragging" << std::endl;
    activePiece->mSprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(renderer.mWindow)));
}
