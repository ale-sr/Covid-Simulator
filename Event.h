#ifndef CLIONPROYECT_EVENT_H
#define CLIONPROYECT_EVENT_H
#include "Particle.h"

class event {

private:

    particle* a;
    particle* b;
    double event_time;
    int countA;
    int countB;

public:

    friend class CollisionSystem;
    friend class comparetime;

    event(double event_time, particle* a, particle* b);

    bool isValid();

};

struct comparetime {
    bool operator()(event* const& e1, event* const& e2){
        return  e1->event_time > e2->event_time;
    }

};
#endif //CLIONPROYECT_EVENT_H
