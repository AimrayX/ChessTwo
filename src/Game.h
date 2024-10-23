#pragma once
#include "Renderer.h"
#include "Piece.h"
#include "Rook.h"
#include "Board.h"
#include <SFML/Window/Mouse.hpp>

class Game {
    private:
        Board board;
        std::vector<std::shared_ptr<Piece>> mPieces;
        std::shared_ptr<Piece> activePiece;
        Renderer renderer;
        bool dragging;
        sf::Vector2f getMousePosition();
        sf::Vector2f getMousePosition(sf::Event&);
        std::shared_ptr<Piece> getPieceOnPosition(sf::Vector2f);
        sf::RectangleShape &getSquareOnPosition(sf::Vector2f);
        void run();
        void dragPiece();
        

    public:
        Game();
        
        
	    
};

