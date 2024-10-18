#include "Game.h"

Game::Game() 
    : renderer(1000, 1000, "Test"), mPieces{} {
    //load menu()
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), true));
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), true));
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), false));
    mPieces.push_back(std::make_unique<Rook>(static_cast<float>(std::min(renderer.mWindowSize.x, renderer.mWindowSize.y)), false));
    passSprites();
}

//load menu()
//  init game()

void Game::passSprites() {
    for (auto &&i : mPieces)
    {
        renderer.mPiecesSprites.push_back(i->mSprite);
    }
}