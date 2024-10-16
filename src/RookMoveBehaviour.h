#pragma once
#include "IMoveBehaviour.h"

class RookMoveBehaviour : public IMoveBehaviour {
    
private:

    long long getValidMovesBitmap() const override;

public:
    
};

