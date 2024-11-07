#include "MyMaths.h"
#include <cmath>

sf::Vector2u convertV2fToV2u(const sf::Vector2f &vectorF) {
    if (vectorF.x >= 0 && vectorF.y > 0)
    {
        return sf::Vector2u(static_cast<unsigned int>(std::round(vectorF.x)), static_cast<unsigned int>(std::round(vectorF.y)));
    }
    else
    {
        std::printf("out of scope");
    }
    return sf::Vector2u();
    
}