#ifndef PARTICLE_H
#define PARTICLE_H

#include <Eigen/Dense>
#include <vector>

typedef Eigen::Vector2d vec2d;

class BaseParticle {

private:


protected:
    static int idCnt_;

    vec2d velocity_; // [vx, vy]
    vec2d position_; // [x,y]
    int mass_; // keeping as int for simplicity, could very well be float/double
    int id_;

public :

    //Making color public since there is only read access after initialization
    std::vector<int> color_;

    BaseParticle() { idCnt_++; };
    ~BaseParticle()= default;

    vec2d Velocity(){return this->velocity_;}
    vec2d Position(){return this->position_;}

    void Velocity(vec2d v) {velocity_ = v;}
    void Position(vec2d p) {position_ = p;}

    void Mass(int mass){mass_ = mass;}
    int Mass(){return mass_;}

    // Physics
    virtual  void simulate(int timestep) = 0;

};


class CircleParticle : public  BaseParticle
{
private:

    int radius_;


public:
    CircleParticle(vec2d center, float radius, vec2d velocity, int mass, std::vector<int> color);
    ~CircleParticle() = default;

    int ID();

    int Radius() {return radius_;}

    vec2d Center();

    float leftEnd();
    float rightEnd();
    float topEnd();
    float bottomEnd();

    // Simulated movement based on zero acceleration motion model.
    void simulate(int stepsize) override;

};

#endif //PARTICLE_H
