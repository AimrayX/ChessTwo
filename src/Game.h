#pragma once
#include "Renderer.h"
#include "Piece.h"
#include "Rook.h"
#include "RookMoveBehaviour.h"
#include "Context.h"

class Game {
    private:
        Renderer renderer;
        Context context(std::unique_ptr<RookMoveBehaviour>());
        void passSprites();

    public:
        Game();
        std::vector<std::unique_ptr<Piece>> mPieces;
        
	    
};

