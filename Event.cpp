#include "Event.h"

event::event(double event_time, particle* a, particle* b){
    this->event_time = event_time;
    this->a =a;
    this->b =b;
    if(a != nullptr)
    {
        countA = a->count();
    }
    else countA = -1;

    if(b != nullptr)
    {
        countB = b->count();
    }
    else countB = -1;
}


bool event::isValid()
{
    if (a!= nullptr && a->count()!= countA)
        return  0;
    if (b!= nullptr && b->count()!= countB)
        return  0;
    return  1;

}



