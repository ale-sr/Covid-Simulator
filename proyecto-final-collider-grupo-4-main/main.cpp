#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Menu.h"
#include "CollisionSystem.h"
#include <stdio.h>
#include <string>
#include <ctime>
using namespace sf;
using namespace std;
std::vector<particle*> particles;
int cant_enfermos;


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

void case1(){
    double radio_general = 0.01/3 ;
    double moving_particles_mass = 0.0025;

    int cant_particulas;
    cout<<"Ingrese la cantidad total que desea: ";
    cin>>cant_particulas;


    cout<<"Ingrese la cantidad de infectados inicialmente: ";
    cin>>cant_enfermos;



    for(int i = 0 ; i < cant_enfermos; i++){

        auto a = new particle(random<double>(0.1, 1),
                              random<double>(0, 1) ,random<double>(-0.056, 0.056)/20,
                              random<double>(0.001, 0.0056)/20, radio_general, moving_particles_mass ,
                              250 ,0 ,0 ) ;

        a->set_infected(true );

        particles.push_back(a);

    }



    for(int i = 0 ; i < cant_particulas-1; i++){
        auto mortality_risk_ =  random<double>(0.0, 100.0);
        //cout<<"mortality_risk_: "<<mortality_risk_<<endl;
        particles.push_back(new particle(random<double>(0.1, 1),
                                         random<double>(0, 1) ,random<double>(-0.056, 0.056)/20,
                                         random<double>(0.001, 0.0056)/20,radio_general, moving_particles_mass ,0 ,
                                         0 ,250));
    }

}
void case2(){

    double radio_general = 0.01/3;
    double masa_de_estaticos = 30;
    double moving_particles_mass = 0.0025;

    int cant_particulas;
    cout<<"Ingrese la cantidad total que desea: ";
    cin>>cant_particulas;

    int particulas_libres = cant_particulas/4;

    auto mortality_risk = random<double>(0.0 , 100.0);

    cout<<"Ingrese la cantidad de infectados inicialmente: ";
    cin>>cant_enfermos;

    for(int i = 0 ; i < cant_enfermos; i++){

        auto mortality_risk_ = random <double> (0.0, 100.0);

        auto a = new particle(random<double>(0.1, 1),
                              random<double>(0, 1) ,random<double>(-0.056, 0.056)/20,
                              random<double>(0.001, 0.0056)/20, radio_general, moving_particles_mass
                              ,250 ,0 ,0 ) ;

        a->set_infected(true );

        particles.push_back(a);

    }


    for(int i = 0 ; i < particulas_libres-1; i++){
        auto mortality_risk_ =  random<double>(0.0, 100.0);

        particles.push_back(new particle(random<double>(0.1, 1),
                                         random<double>(0, 1) ,random<double>(0.001, 0.056)/30,
                                         random<double>(0.001, 0.0056)/30,radio_general, moving_particles_mass ,0 ,
                                         0 ,250
                                         ));
    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        double mortality_risk_ =  random<double>(0.0 , 100.0);

        particles.push_back(new particle(random<double>(0, 0.3),
                                         random<double>(0, 1) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));
    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        auto mortality_risk_ =  random<double>(0.0, 100.0);
        particles.push_back(new particle(random<double>(0.3, 0.7),
                                         random<double>(0, 1) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));
    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        auto mortality_risk_ =  random<double>(0.0, 100.0);

        particles.push_back(new particle(random<double>(0.7, 1),
                                         random<double>(0, 1) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));

    }


}


void case3(){
    double radio_general = 0.01/3 ;
    double masa_de_estaticos = 30;
    double moving_particles_mass = 0.0025;
    auto mortality_risk = random<double>(0.0 , 100.0);



    int cant_particulas;
    cout<<"Ingrese la cantidad total que desea: ";
    cin>>cant_particulas;

    int particulas_libres = cant_particulas/4;

    cout<<"Ingrese la cantidad de infectados inicialmente: ";
    cin>>cant_enfermos;

    for(int i = 0 ; i < cant_enfermos; i++){

        auto mortality_risk_ = random <double> (0.0, 100.0);

        auto a = new particle(random<double>(0.1, 0.99),
                              random<double>(0, 0.99) ,random<double>(-0.056, 0.056)/20,
                              random<double>(0.001, 0.0056)/20, radio_general, moving_particles_mass
                              ,250 ,0 ,0 ) ;

        a->set_infected(true );

        particles.push_back(a);

    }

    for(int i = 0 ; i < particulas_libres-1; i++){
        particles.push_back(new particle(random<double>(0.1, 1),
                                         random<double>(0, 1) ,random<double>(0.001, 0.056)/30,
                                         random<double>(0.001, 0.0056)/30,radio_general, moving_particles_mass ,0 ,
                                         0 ,250));
    }



    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        particles.push_back(new particle(random<double>(0.099, 0.3),
                                         random<double>(0, 0.99) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));
    }

    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        particles.push_back(new particle(random<double>(0.3, 0.7),
                                         random<double>(0, 0.99) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));
    }

    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/8 ); i++){

        particles.push_back(new particle(random<double>(0, 0.3),
                                         random<double>(0, 0.99) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));

    }
    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/8 ); i++){
        particles.push_back(new particle(random<double>(0, 0.3),
                                         random<double>(0, 0.99) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));

    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){

        particles.push_back(new particle(random<double>(0.7, 0.999),
                                         random<double>(0, 0.99) ,0 ,
                                         0, radio_general, masa_de_estaticos ,0 ,
                                         0 ,250));

    }


}


int main() {

    Menu menu;
    menu.correr_menu();

    if(menu.input_Case == 1){
        cout<<"case1();"<<endl;
        thread t(case1);
        t.join();
    }else if(menu.input_Case == 2 ){
        cout<<"case2();"<<endl;
        thread t(case2);
        t.join();
    }else if (menu.input_Case == 3){
        cout<<"case3();"<<endl;
        thread t(case3);
        t.join();
    }else{
        return 0;
    }


    RenderWindow* window = new RenderWindow (VideoMode(1000,1000), "POO2");
    window->setFramerateLimit(60);

    CollisionSystem test(10000, particles, cant_enfermos );


    while (window->isOpen()){
        test.simulate(10000, window);

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
        }

    }
    cout<< "Etapa de vida de los infectados: "<<endl;
    cout<< "    + Infante (entre 0 y 11 de edad) : " <<int(test.count_infected* 4 / 100)<<endl;
    cout<< "    + Adolescente (entre 12 y 17 de edad) : " <<int(test.count_infected* 3 / 100)<<endl;
    cout<< "    + Joven (entre 18 y 29 de edad) : " <<int(test.count_infected* 19 / 100)<<endl;
    cout<< "    + Adulto (entre 30 y 59 de edad) : " <<int(test.count_infected* 56 / 100)<<endl;
    cout<< "    + Adulto mayor ( entre 60 a mas de edad) : " <<int(test.count_infected* 18 / 100)<<endl;
    cout<< "Sexo de los infectados: "<<endl;
    cout<< "    + Sexo masculino : " <<int(test.count_infected* 51.7 / 100.0)<<endl;
    cout<< "    + Sexo femenino : " <<int(test.count_infected*  48.3 / 100.0)<<endl;
    return 0;
}
