#include "Player.h"

Player::Player(bool color) 
    : mColor{color}, isToMove{}, isInCheck{}, isCheckMate{}
{
    if (color)
    {
        isToMove = true;
    }
    else
    {
        isToMove = false;
    }
    
}