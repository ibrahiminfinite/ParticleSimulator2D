#ifndef BOX_H
#define BOX_H

#include <vector>
#include <memory>
#include <Eigen/Dense>

#include "Particle.h"

typedef Eigen::Vector2d vec2d;


class Box {


public:
    float leftEnd, rightEnd, topEnd, bottomEnd;
    std::vector<std::unique_ptr<CircleParticle>> particles_;
    Box(vec2d p);

    void addParticle(vec2d Center, int radius, vec2d velocity, int mass, std::vector<int> color);

};


#endif //BOX_H
