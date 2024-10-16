#pragma once
#include <vector>

class IMoveBehaviour {

public:

    virtual ~IMoveBehaviour() = default;
    virtual long long getValidMovesBitmap() const = 0;

};
