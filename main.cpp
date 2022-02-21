
#include "Simulator.h"
#include <iostream>

// Entry point
int main()
{

    // Define box size
    vec2d box_size{500,500};

    int numParticles = 0;

    // Get number of particles input from user
    while (true){
        std::cout<<"Enter the number of particles (min : 1, max 20)  : ";
        std::cin >> numParticles;
        if(numParticles > 0 && numParticles <= 20) break;
    }

    // Create the simulator instance
    // stepsize 16 ~ 60 FPS or 60 Hz
    Simulator s(16, box_size , numParticles);

    // Run the simulation
    s.run();
}