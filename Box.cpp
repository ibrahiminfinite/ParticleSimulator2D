#include "Box.h"

void Box::addParticle(vec2d center, int radius, vec2d velocity, int mass, std::vector<int> color)
{
    particles_.emplace_back(std::make_unique<CircleParticle>(center, radius, velocity, mass, color));
}

Box::Box(vec2d p)
{
    leftEnd = 0;
    rightEnd = p[0];
    topEnd = p[1];
    bottomEnd = 0;
}

