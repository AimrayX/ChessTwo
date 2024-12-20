#include "Game.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
#include <iomanip>
#include <bitset>

Game::Game()
    : board(sf::Vector2u(700, 700)), mPieces{}, activePiece{}, renderer(700, 700, "Chess", board.mBoardRectangles), dragging{false},
      mBitmapWhitePieces{0b0000000000000000000000000000000000000000000000001111111111111111},
      mBitmapBlackPieces{0b1111111111111111000000000000000000000000000000000000000000000000},
      player1(1), player2(0), playerTurn{1}, player1won{}, player2won{}
{
    
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][0]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][1]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][2]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][3]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][4]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][5]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][6]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[1][7]));

    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][0]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][1]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][2]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][3]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][4]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][5]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][6]));
    mPieces.emplace_back(std::make_shared<Pawn>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[6][7]));
    
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][0]));
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][7]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][2]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][5]));
    mPieces.emplace_back(std::make_shared<Queen> (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][3]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][6]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][1]));

    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][0]));
    mPieces.emplace_back(std::make_shared<Rook>  (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][7]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][2]));
    mPieces.emplace_back(std::make_shared<Bishop>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][5]));
    mPieces.emplace_back(std::make_shared<Queen> (static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][3]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][6]));
    mPieces.emplace_back(std::make_shared<Knight>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][1]));

    mPieces.emplace_back(std::make_shared<King>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 0, board.mBoardRectangles[0][4]));
    mPieces.emplace_back(std::make_shared<King>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), 1, board.mBoardRectangles[7][4]));

    for (auto &piece : mPieces)
    {
        piece->calcMovesBitmap(mPieces, board.mBoardRectangles);
    }

    run();
}

void Game::run()
{
    while (renderer.mWindow.isOpen() && !player1won && !player2won)
    {
        sf::Event event;
        while (renderer.mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderer.mWindow.close();
            if (event.type == sf::Event::Resized)
            {
                renderer.updateView();
                board.updateBoard(renderer.mWindowSize);
                renderer.updatePieceSprites(board.mBoardSize, mPieces);
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //std::cout << "clicked" << std::endl;

                if (activePiece == nullptr)
                {
                    activePiece = getPieceOnPosition(getMousePosition());
                    if (activePiece != nullptr && activePiece->mColor != playerTurn)
                    {
                        activePiece = nullptr;
                        std::cout << "thats your opponents piece, idiot" << std::endl;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {

                if (activePiece != nullptr)
                {

                    if (activePiece == getPieceOnPosition(getMousePosition()))
                    {
                        //std::cout << "piece selected" << std::endl;

                        if (activePiece != nullptr)
                        {
                            renderer.highlightValidSquares(activePiece);
                        }
                    }
                    else
                    {
                        std::pair<bool, std::shared_ptr<Piece>> moveReturn{activePiece->move(mPieces, getSquareOnPosition(getMousePosition()))};
                        std::shared_ptr<Piece> tempPiece = nullptr;
                        renderer.deHighlightValidSquares(activePiece);

                        if (!moveReturn.first && moveReturn.second != nullptr)
                        {

                            for (auto it = mPieces.begin(); it != mPieces.end(); it++)
                            {
                                if (it->get() == moveReturn.second.get())
                                {
                                    //std::cout << " taken pieces isProtected: " << it->get()->isProtected;
                                    std::shared_ptr<Piece> tempPiece = *it;
                                    it = mPieces.erase(it);
                                    break;
                                }
                            }
                            updateAllPiecesBitmaps();
                            
                            
                        }
                        else if (!moveReturn.first)
                        {
                            updateAllPiecesBitmaps();
                        }

                        if (!moveReturn.first && checkCheck() && ((playerTurn == player1.mColor && player1.isInCheck) || (playerTurn == player2.mColor && player2.isInCheck)))
                        {
                            activePiece->mCurrentSquare = activePiece->mPreviousSquare;
                            if (activePiece->mHasPrevMoved == false)
                            {
                                activePiece->mHasMoved = false;
                            }
                            if (tempPiece != nullptr)
                            {
                                mPieces.insert(mPieces.begin(), tempPiece);
                            }
                            updateAllPiecesBitmaps();
                        }
                        else if(!moveReturn.first)
                        {
                            updateAllPiecesBitmaps();
                            if (checkIfPawnPromotion())
                            {
                                promote();
                            }
                            switchPlayerTurn();    
                            checkCheck();
                        }
                        activePiece = nullptr;
                        tempPiece = nullptr;
                        renderer.updatePieceSprites(board.mBoardSize, mPieces);                   
                    }
                }
                else
                {
                    std::cout << "nothing selected" << std::endl;
                }
            }
        }

        renderer.draw();
    }
}

sf::Vector2f Game::getMousePosition(sf::Event &event)
{

    return sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
}

sf::Vector2f Game::getMousePosition()
{
    if (renderer.mWindowSize.x > renderer.mWindowSize.y)
    {
        return sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).x) - (static_cast<float>(renderer.mWindowSize.x) - board.mBoardSize) / 2.0f, static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).y));
    }
    else
    {
        return sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).x), static_cast<float>(sf::Mouse::getPosition(renderer.mWindow).y) - (static_cast<float>(renderer.mWindowSize.y) - board.mBoardSize) / 2.0f);
    }
}

std::shared_ptr<Piece> Game::getPieceOnPosition(sf::Vector2f mousePosition)
{
    // float inset {board.mBoardSize / 8.0f - (board.mBoardSize / 20.0f)};
    for (auto &piece : mPieces)
    {

        if ((mousePosition.x > piece->mCurrentSquare.getPosition().x) 
             && (mousePosition.y > piece->mCurrentSquare.getPosition().y) 
             && (mousePosition.x < (piece->mCurrentSquare.getPosition().x + piece->mCurrentSquare.getSize().x)) 
             && (mousePosition.y < (piece->mCurrentSquare.getPosition().y + piece->mCurrentSquare.getSize().y)))
        {

            //std::cout << "clicked on piece" << std::endl;
            return piece;
        }
    }

    return nullptr;
}

sf::RectangleShape &Game::getSquareOnPosition(sf::Vector2f mousePosition)
{

    for (auto &i : board.mBoardRectangles)
    {

        for (auto &rect : i)
        {
            if ((mousePosition.x > rect.getPosition().x) 
                 && (mousePosition.y > rect.getPosition().y) 
                 && (mousePosition.x < (rect.getPosition().x + rect.getSize().x)) 
                 && (mousePosition.y < (rect.getPosition().y + rect.getSize().y)))
            {

                //std::cout << "clicked on square " << rect.getPosition().x << "x * " << rect.getPosition().y << "y" << std::endl;
                return rect;
            }
        }
    }

    return board.mBoardRectangles[3][3];
}

void Game::dragPiece()
{
    //std::cout << "dragging" << std::endl;
    activePiece->mSprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(renderer.mWindow)));
}

void Game::updateAllPiecesBitmaps()
{
    for (auto &piece : mPieces)
    {
        piece->isProtected = 0;
    }
    for (auto &piece : mPieces)
    {
        piece->calcMovesBitmap(mPieces, board.mBoardRectangles);
    }
    
}

void Game::getPositionCords()
{
    for (auto &piece : mPieces)
    {
        std::cout << piece->mCurrentSquare.getPosition().x << "x x " << piece->mCurrentSquare.getPosition().y << "y : "
                  << piece->mSprite.getPosition().x << "x x " << piece->mSprite.getPosition().y << "y" << std::endl;
    }

    for (auto &piece : mPieces)
    {
        std::cout << std::setw(8);
        std::cout << std::bitset<64>(piece->mBitmapValidSquares) << "\n\n"
                  << std::endl;
    }
}

//make that only if the side that is playing is in check it returns true, in order to check for a invalid move
bool Game::checkCheck()
{
    unsigned long long kingPos;

    if (playerTurn)
    {
        kingPos = mPieces[mPieces.size()-1].get()->mBitmapCurrentSquare;
    }
    else
    {
        kingPos = mPieces[mPieces.size()-2].get()->mBitmapCurrentSquare; 
    }

    for (auto &piece : mPieces)
    {
        if (piece->mColor != playerTurn && (kingPos & piece->mBitmapAttackingSquares) != 0)
        {
            if (playerTurn == player1.mColor)
            {
                player1.isInCheck = true;
                checkCheckMate();
            }
            else
            {
                player2.isInCheck = true;
                checkCheckMate();
            }
            return true;
        } 
    }
    return false;
}

void Game::switchPlayerTurn()
{
    if (playerTurn == player1.mColor)
    {
        player1.isToMove = false;
    }
    else
    {
        player2.isToMove = false;
    }
    playerTurn = !playerTurn;
}

bool Game::checkCheckMate()
{
    if (!checkIfAbleToEvade() && !checkIfAbleToBlock())
    {
        std::cout << "Player " << !playerTurn << " won the game by checkmate!" << std::endl;
        if (playerTurn)
        {
            player2won = true;
        }
        else
        {
            player1won = true;
        }
        
        
        return true;
    }
    return false;
}

bool Game::checkIfAbleToEvade()
{
    if (playerTurn && mPieces[mPieces.size()-1].get()->mBitmapValidSquares != 0)
    {
        return true;
    }
    else if (!playerTurn && mPieces[mPieces.size()-2].get()->mBitmapValidSquares != 0)
    {
        return true; 
    }
    return false;
}

//TODO
//Class would have to move the piece to each single valid square but would first have to find out what does squares are by bitshifting
//and checking if there was a 1 and keeping track of the shifts and thus which square it corresponds to :(
//Then it need to move it and check if its still check and undo the move
bool Game::checkIfAbleToBlock()
{
    return false;
}

//check if a pawn has its current square in the first eight bits or last eight bits
bool Game::checkIfPawnPromotion()
{
    if (activePiece->mPieceID == 6 && (activePiece->mBitmapCurrentSquare & 0b1111111100000000000000000000000000000000000000000000000011111111) != 0)
    {
        std::cout << "pawn can be promoted" << std::endl;
        return true;
    }

    return false;
}

void Game::promote()
{
    //TODO make promote selection pop up
    for (auto it = mPieces.begin(); it != mPieces.end(); it++)
    {
        if (it->get() == activePiece.get())
        {
            //std::cout << " taken pieces isProtected: " << it->get()->isProtected;

            sf::RectangleShape promotionSquare = activePiece->mCurrentSquare;

            it = mPieces.erase(it);

            mPieces.insert(it, std::make_shared<Queen> (static_cast<float>(
                std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), playerTurn, promotionSquare));

            break;
        }
    }
}