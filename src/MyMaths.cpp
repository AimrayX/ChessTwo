#include "MyMaths.h"
#include <cmath>

sf::Vector2u convertV2fToV2u(const sf::Vector2f &vectorF) {
    return sf::Vector2u(static_cast<unsigned int>(std::round(vectorF.x)), static_cast<unsigned int>(std::round(vectorF.y)));
}