//
// Created by mobile on 13/01/22.
//

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <memory>
#include <chrono>
#include "Box.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include "ParticleDynamics.h"
#include "Renderer.h"


class Simulator {

private:
    int timeSteps_;
    float stepSize_; // (milliseconds) fraction of time covered in a single step
    ParticleDynamics dynamics_;
    Renderer renderer_;
    ParticleGenerator generator_;

public:

    std::shared_ptr<Box> box_;

    Simulator(float stepsize, vec2d boxCoords, int numParticles);

    // Computes a single step of the simulation
    void run();

    // Renders the particles on to the GUI
    void render(std::shared_ptr<Box> box);
};


#endif //SIMULATOR_H
