#pragma once
#include "Renderer.h"
#include "Piece.h"
#include "Rook.h"
#include "RookMoveBehaviour.h"
#include "Context.h"
#include "Board.h"

#include <SFML/Window/Mouse.hpp>

class Game {
    private:
        Board board;
        std::vector<std::shared_ptr<Piece>> mPieces;
        std::shared_ptr<Piece> activePiece;
        Renderer renderer;
        bool dragging;
        Context context(std::unique_ptr<RookMoveBehaviour>());
        sf::Vector2f getMousePosition(sf::Event&);
        std::shared_ptr<Piece> getPieceOnPosition(sf::Vector2f);
        void run();
        void dragPiece();
        

    public:
        Game();
        
        
	    
};

