#ifndef PARTICLEDYNAMICS_H
#define PARTICLEDYNAMICS_H

#include <vector>
#include <thread>
#include <cmath>

#include "Box.h"

class ParticleDynamics {

public:

    ParticleDynamics()=default;

    static void checkBoxCollision(std::shared_ptr<Box> box);

    static void checkParticleCollision(std::shared_ptr<Box> box);

};

#endif //PARTICLEDYNAMICS_H
