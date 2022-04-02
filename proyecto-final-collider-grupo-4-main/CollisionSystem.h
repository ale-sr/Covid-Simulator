#ifndef CLIONPROYECT_COLLISIONSYSTEM_H
#define CLIONPROYECT_COLLISIONSYSTEM_H
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Event.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace sf;
class CollisionSystem{

private:

    double time =0.0;
    double HZ = 0.5;
    std::vector<particle*> particles;
    std::priority_queue <event*, std::vector<event*>, comparetime > *pq;

public:
    int contador_aux = 1;
    friend class event;
    int count_infected = 0;

    CollisionSystem(int limit, std::vector<particle*> particles, int cant_enfermos);

    void predict (particle *a, double limit);

    void drawall(double limit, RenderWindow* window);

    void draw(RenderWindow* window);

    void simulate (double limit, RenderWindow* window);

    void infeccion (particle *a);
};

#endif //CLIONPROYECT_COLLISIONSYSTEM_H
