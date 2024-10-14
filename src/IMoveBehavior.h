#pragma once
#include <vector>

class IMoveBehavior {

public:

    virtual ~IMoveBehavior() = default;
    virtual long long getValidMovesBitmap() = 0;

};
