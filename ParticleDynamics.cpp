#include "ParticleDynamics.h"
#include <iostream>

 void ParticleDynamics::checkBoxCollision(std::shared_ptr<Box> box)
{
    float threshold = 0.95;
    for(auto &p : box->particles_)
    {
        if (p->rightEnd() >= box->rightEnd * threshold|| p->leftEnd() <= box->leftEnd * threshold)
            p->Velocity({p->Velocity()[0] * -1, p->Velocity()[1]});

        else if (p->topEnd() >= box->topEnd *threshold|| p->bottomEnd() <= box->bottomEnd * threshold)
            p->Velocity({p->Velocity()[0], p->Velocity()[1] * -1});
    }
}

bool isNotResolved(std::vector<std::pair<int,int>> &pairs, std::pair<int,int> &key)
{
   bool resolved = true;
    if (pairs.empty()){return true;}
    for (auto &p : pairs)
    {
        if(p.first == key.first && p.second == key.second)
            resolved = false;
        if (p.first == key.second && p.second == key.first)
            resolved = false;
    }
    return resolved;
}

void ParticleDynamics::checkParticleCollision(std::shared_ptr<Box> box)
{
    double center_dist=0;
    double c1, c2;
    std::vector<std::pair<int,int>> resolved_pairs;
    for( auto &p : box->particles_)
    {
        c1 = p->Center()[0];
        c2 = p->Center()[1];

        for(auto &q : box->particles_)
        {
            if(p->ID() != q->ID())
            {

                auto xd = pow((c1 - q->Center()[0]),2);
                auto yd = pow((c2 - q->Center()[1]),2);
                center_dist =  sqrt(xd + yd);
                if (center_dist <= (p->Radius() + q->Radius()) *0.9)
                {
                    //collision

                    auto key = std::make_pair(p->ID(),q->ID());

                    if (isNotResolved(resolved_pairs,key ))
                    {
                        std::cout << "COLLISION ! " << p->ID() << " --> " << q->ID() << std::endl;
                        vec2d v1 = p->Velocity();
                        vec2d v2 = q->Velocity();
                        vec2d normal = {c1 - q->Center()[0], c2 - q->Center()[1]};
                        vec2d unit_normal = normal / center_dist;
                        vec2d unit_tangent = {-unit_normal[1], unit_normal[0]};
                        // tangential velocities remain same after collision
                        auto v1_t = unit_tangent.dot(v1);
                        auto v2_t = unit_tangent.dot(v2);

                        // Normal components change

                        auto v1_n = unit_normal.dot(v1);
                        auto v2_n = unit_normal.dot(v2);

                        auto m1 = p->Mass();
                        auto m2 = q->Mass();

                        auto v1_n_temp = (v1_n * (m1 - m2) + (2 * m2 * v2_n)) / (m1 + m2);
                        auto v2_n_temp = (v2_n * (m2 - m1) + (2 * m1 * v1_n)) / (m1 + m2);

                        auto v1_n_new = v1_n_temp * unit_normal;
                        auto v2_n_new = v2_n_temp * unit_normal;
                        auto v1_t_new = v1_t * unit_tangent;
                        auto v2_t_new = v2_t * unit_tangent;

                        p->Velocity(v1_n_new + v1_t_new);
                        q->Velocity(v2_n_new + v2_t_new);
                        resolved_pairs.emplace_back(std::make_pair(p->ID(), q->ID()));
                        resolved_pairs.emplace_back(std::make_pair(q->ID(), p->ID()));
                    }
                }
            }
        }
    }
}
