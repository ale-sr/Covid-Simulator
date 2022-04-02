#ifndef CLIONPROYECT_PARTICLE_H
#define CLIONPROYECT_PARTICLE_H
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class particle {

private:

// posición de la particula en X y en Y
    double rx_, ry_;
// velocidad de la particula en X y en Y
    double vx_, vy_;
// número de colisiones de la particula
    int count_;
//radio de la particula
    double r_;
//masa de la particula
    double mass_;
//color de la particula r,g,b
    int red, gr, blu;
// infectado? -> Hacer un metodo que tome el tiempo que empezo a ser infectado
// 5 segundos despues de ser infectado, cambie a otro color
    bool infected;


public:


//constructor
    particle(double rx, double ry, double vx, double vy,
    double r, double mass, int red, int gr, int blu):
    rx_(rx), ry_(ry), vx_(vx), vy_(vy),r_(r),
    mass_(mass), red(red), gr(gr),blu(blu) {};

//getter
// get count
    inline int count() { return count_;}

    inline int get_red (){ return red;};

    inline int get_blue (){ return blu;};

    inline int get_green (){ return gr;};

    inline bool get_infected (){ return infected;};


    //setter

    inline void set_red (int red_){ red = red_;};

    inline void set_blue (int blu_){ blu = blu_;};

    inline void set_green (int gr_){  gr = gr_;};

    inline void set_infected (bool infected_){  infected =  infected_;};



    //mueve a la particula con movimiento rectilineo
    void move(double dt);

//dibuja la particula en la ventana
    void draw(sf::RenderWindow* window);

/*nos da el tiempo en el que la particula colisionará con la
particula que se pasa como parametro */
    double timeHitOther(particle* other);

/*nos da el tiempo en que la particula colisionara con el
 limite vertial (en este caso la ventana ) */
    double timeHitVWall();

/*nos da el tiempo en que la particula colisionará con el
  limite horizantal(en este caso la ventana )*/
    double timeHitHWall();

/*aquí se realiza el redireccionamiento de la particula
 cuando se realiza un colisión entre dos particulas
 modifica las velocidades*/
    void bounceOther(particle* other);

/*redireccionar solo a la particula no estática*/


/* aquí se modifica la veolocidad de la particula cuando
 colisiona con una pared vertical, se invierten la trayectoria
 es decir la dirección que tomará la particula
 */
    void bounceVWall();

 /* aquí pasa algo muy similar  bounce V Wall
  se modifica la veolocidad de la particula para que tome
  una dirección contraria pero cuando colisione con una
  pared horizonal
 */
    void bounceHWall();

};

#endif //CLIONPROYECT_PARTICLE_H
