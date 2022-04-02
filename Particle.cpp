#include "Particle.h"

void particle::move(double dt) {
    rx_ += vx_ * dt;
    ry_ += vy_ * dt;
}

void particle::draw(sf::RenderWindow *window){
    //prueba tamaño radio
    int factor= 1000;
    sf::CircleShape circle(r_*1000);
    circle.setFillColor(sf::Color(this->red, this->gr, this->blu,255));
    circle.setPosition(factor*rx_+00, factor*ry_+00);
    window->draw(circle);
}

//Colisión entre dos particulas
/*En esta función se determinará si estas dos particulas
chocaran y cuando lo harán*/
/*retorna infinito si las particulas no colisionaran*/
double particle::timeHitOther(particle *other) {
    if (this == other)
        return INFINITY;
/*obtenemos los valores de las varibles usadas en
la ecuación*/
// dx_= distancia entre las dos particulas en el eje x
    double dx_  = other->rx_ - this->rx_;
// dx_= distancia entre las dos particulas en el eje y
    double dy_  = other->ry_ - this->ry_;
    double dvx_ = other->vx_ - this->vx_;
    double dvy_ = other->vy_ - this->vy_;
    double dvdr_ = dx_*dvx_ + dy_*dvy_;

    //evaluamos los valores para obtener el tipo
    if (dvdr_ > 0)
        return INFINITY;

    double dvdv_ = dvx_*dvx_ + dvy_*dvy_;
    if (dvdv_ == 0)
        return INFINITY;

    double drdr_ = dx_*dx_ + dy_*dy_;
    double sig = this->r_ + other->r_;
    double d = (dvdr_*dvdr_) - dvdv_ * (drdr_ - sig*sig);
    if (d < 0)
        return INFINITY;
    else
    return - (dvdr_ + sqrt(d)) / dvdv_;
}

/*Esta función nos permite determinar cuando una particula
entrará en contacto con una pared vertical */
//como las coordenadas están entre 0 y 1

double particle::timeHitVWall(){
    if (vx_ > 0)
        return (1.0 - rx_ - r_) / vx_;

    else if (vx_ < 0)
        return (r_ - rx_) / vx_;

    else
        return INFINITY;
}

/*Esta función nos permite determinar cuando una particula
entrará en contacto con una pared horizontal */
double particle::timeHitHWall() {
    if (vy_ > 0)
        return (1.0 - r_ - ry_) / vy_;

    else if (vy_ < 0)
        return (r_ - ry_) / vy_;

    else
        return INFINITY;
}


void particle::bounceOther(particle* other){
    double dx_  = other->rx_ - this->rx_;
    double dy_  = other->ry_ - this->ry_;
    double dvx_ = other->vx_ - this->vx_;
    double dvy_= other->vy_ - this->vy_;
    double dvdr_ = dx_*dvx_ + dy_*dvy_;
    double distance_ = this->r_ + other->r_;

    double magni = 2* this->mass_ * other->mass_ * dvdr_ / ((this->mass_ + other->mass_) * distance_);

    double fx_ = magni * dx_ / distance_;
    double fy_ = magni * dy_ / distance_;

    // update velocities according to normal force
    this->vx_ += fx_ / this->mass_;
    this->vy_ += fy_ / this->mass_;
    other->vx_ -= fx_ / other->mass_;
    other->vy_ -= fy_ / other->mass_;

    // update collision counts
    this->count_++;
    other->count_++;

};

void particle::bounceVWall()
{
    vx_ = -vx_;
    count_++;
};

void particle::bounceHWall()
{
    vy_ = -vy_;
    count_++;

};


