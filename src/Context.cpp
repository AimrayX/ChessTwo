#include "Context.h"

#include <iostream>



Context::Context(std::unique_ptr<IMoveBehaviour> &&behaviour) 
    : mBehaviour(std::move(behaviour)) {

    }   
 
void Context::setBehaviour(std::unique_ptr<IMoveBehaviour> &&behaviour) {

    mBehaviour = std::move(behaviour);
}

int Context::movePiece() {
    if (mBehaviour) {

        long long validMoves {mBehaviour->getValidMovesBitmap()};
        std::cout << validMoves;
        //check if valid and something was captured
            //call destructor of the other piece
        return 0;
    } else {

        std::cout << "strategy not set";
        return 1;
    }
    return 1;
}