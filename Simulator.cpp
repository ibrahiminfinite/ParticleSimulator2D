#include "Simulator.h"

Simulator::Simulator(float stepsize, vec2d boxCoords, int numParticles):timeSteps_(0), stepSize_(stepsize)
{

    dynamics_ = ParticleDynamics();
    renderer_ = Renderer();
    box_ = std::make_shared<Box>(boxCoords);
    timeSteps_ = 0;

// Test particles
//    box_->addParticle({50,140}, 5, {100, 0},1);
//    box_->addParticle({200,140}, 10, {-100, 0},1);

    // Add numParticle particles
    ParticleGenerator p;
    for(int i=0; i < numParticles; i++)
    {
        auto data = generator_.Generate();
        auto color = {data[6], data[7],data[8]};
        box_->addParticle({data[0], data[1]}, data[2],{data[3], data[4]}, data[5], color);
    }
}


void Simulator::run()
{

    while(true) {
        // 40 ms delay is given by cv::Waitkey()

        dynamics_.checkBoxCollision(box_);
        dynamics_.checkParticleCollision(box_);
        for(auto &p : box_->particles_)
        {
            p->simulate(stepSize_);

        }
        this->render(this->box_);
        timeSteps_ ++;
    }

}

void Simulator::render(std::shared_ptr<Box> box)
{
    this->renderer_.render(box, this->stepSize_);
}


