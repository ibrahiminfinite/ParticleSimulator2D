#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator() {

    center_distribution =  std::uniform_int_distribution<>(50,350);
    velocity_distribution = std::uniform_int_distribution<>(10, 200);
    radius_distribution = std::uniform_int_distribution<>(10,25);
    mass_distribution = std::uniform_int_distribution<>(1,15);
    color_distribution = std::uniform_int_distribution<>(50,255);

}

std::vector<int> ParticleGenerator::Generate()
{
    int center_x, center_y, radius, velocity_x, velocity_y, mass;
    int color_r, color_g, color_b;
    std::mt19937 engine(device());
    mass = mass_distribution(engine);
    center_x = center_distribution(engine);
    center_y = center_distribution(engine);
    radius = radius_distribution(engine);
    velocity_x = velocity_distribution(engine);
    velocity_y = velocity_distribution(engine);
    color_r = color_distribution(engine);
    color_g = color_distribution(engine);
    color_b = color_distribution(engine);

    return {center_x, center_y, radius, velocity_x, velocity_y, mass, color_r, color_g, color_b};
}
