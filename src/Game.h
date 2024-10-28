#pragma once
#include "Renderer.h"
#include "Board.h"
#include <utility>
#include <SFML/Window/Mouse.hpp>

class Game {
    private:
        Board board;
        std::vector<std::shared_ptr<Piece>> mPieces;
        std::shared_ptr<Piece> activePiece;
        Renderer renderer;
        bool dragging;
        unsigned long long bitmapWhitePieces;
        unsigned long long bitmapBlackPieces;
        sf::Vector2f getMousePosition();
        sf::Vector2f getMousePosition(sf::Event&);
        std::shared_ptr<Piece> getPieceOnPosition(sf::Vector2f);
        sf::RectangleShape &getSquareOnPosition(sf::Vector2f);
        void run();
        void dragPiece();
        void updateAllPiecesBitmaps();
        void getPositionCords();
        

    public:
        Game();
        
        
	    
};

