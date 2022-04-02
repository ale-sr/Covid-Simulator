#include <ctime>
#include <cstdlib>
#include <thread>
#include <random>
#include <mutex>
#include "pthread.h"
#include "CollisionSystem.h"
using namespace  std;
template<typename Numeric, typename Generator = std::mt19937>
Numeric random(Numeric from, Numeric to)
{
    thread_local static Generator gen(std::random_device{}());

    using dist_type = typename std::conditional
            <
                    std::is_integral<Numeric>::value
                    , std::uniform_int_distribution<Numeric>
                    , std::uniform_real_distribution<Numeric>
            >::type;

    thread_local static dist_type dist;

    return dist(gen, typename dist_type::param_type{from, to});
}


CollisionSystem::CollisionSystem(int limit, std::vector<particle *> particles, int cant_enfermos){
    count_infected = cant_enfermos;
    this->particles = particles;
    pq = new std::priority_queue <event*, std::vector<event*>, comparetime>;
    for (int i = 0; i < particles.size(); i++)
    {
        predict(particles[i], limit);
    }
    pq->push(new event(0, nullptr, nullptr));
};


void CollisionSystem::predict (particle *a, double limit){
    if (a == nullptr)
        return;

    for (int w = 0; w < particles.size(); w++){
        double dt = a->timeHitOther(particles[w]);
        if (time +dt <= limit){
            pq->push(new event (time + dt, a, particles[w]));
        }
    }

    double dtX = a->timeHitVWall();
    double dtY = a->timeHitHWall();
    if (time + dtX <= limit) pq->push(new event(time + dtX, a, nullptr));
    if (time + dtY <= limit) pq->push(new event(time + dtY, nullptr, a));

};

void CollisionSystem::drawall(double limit, RenderWindow* window) {
    window->clear(sf::Color(250,250, 250, 255));
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->draw(window);
    }
    window->display();

    sf::sleep(sf::Time(sf::milliseconds(100)));
    if (time < limit) {
        pq->push(new event(time + 1.0 / HZ, nullptr, nullptr));
    }
}

void CollisionSystem::draw(RenderWindow* window){
    window->clear(sf::Color(0,0, 0, 255));
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->draw(window);
    }
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(100)));

};



void cambiar_color(particle *b){

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        b->set_blue(0);
        b->set_red(0);
        b->set_green(250);


}
void CollisionSystem::infeccion (particle *b){
    count_infected++;
    b->set_blue(0);
    b->set_red(250);
    b->set_green(0);

    b->set_infected(true);

    pthread_t thread_aux;
    pthread_create(&thread_aux, nullptr, reinterpret_cast<void *(*)(void *)>(&cambiar_color), b);

}
std::mutex mtx;
void CollisionSystem::simulate (double limit, RenderWindow* window)
{
    if(!pq->empty()){
        //draw(window);
        event* e = pq->top();
        pq->pop();
        if (!e->isValid()) return;
        particle* a = e->a;
        particle* b = e->b;

        for (int x= 0; x < particles.size(); ++x)
            particles[x]->move(e->event_time -time);
        time =e->event_time;


        if (a != nullptr && b != nullptr){
            a->bounceOther(b);

            if ((contador_aux <= count_infected && b->get_red() == 250)){
                mtx.lock();
                contador_aux++;
                mtx.unlock();
                a->set_red(250);
                a->set_green(0);
                a->set_blue(0);
                pthread_t thread_aux;
                pthread_create(&thread_aux, nullptr, reinterpret_cast<void *(*)(void *)>(&cambiar_color), b);
            }
            else if ((contador_aux <=count_infected && a->get_red()== 250) ){
                mtx.lock();
                contador_aux++;
                mtx.unlock();
                b->set_red(250);
                b->set_green(0);
                b->set_blue(0);
                pthread_t thread_aux;
                pthread_create(&thread_aux, nullptr, reinterpret_cast<void *(*)(void *)>(&cambiar_color), a);            }

            if ( a -> get_red() == 250 && a -> get_blue() == 0 && a -> get_green() == 0
                 && b->get_infected() == false ){
                    infeccion(b);
                   // cout<<"Entra al IF"<<endl;
            }else if ( b -> get_red() == 250 && b -> get_blue() == 0 && b-> get_green() == 0
                       && a->get_infected() == false ){

                infeccion(a);

            }
        }
        else if (a != nullptr && b == nullptr )
            a->bounceVWall();
        else if (a == nullptr && b != nullptr)
            b->bounceHWall();
        else if (a == nullptr && b == nullptr)
            drawall(limit,window);

        predict(a, limit);
        predict(b, limit);
    }
    else
    {
        for (int i = 0; i < particles.size(); i++)
        {
            predict(particles[i], limit);
        }
    }
}
