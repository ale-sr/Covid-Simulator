//
// Created by rumin on 12/12/2020.
//

#ifndef CLIONPROYECT_MENU_H
#define CLIONPROYECT_MENU_H
#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;


void f2(const string& texto) {
    cout << texto << endl;
}

void hacer_cin(int &input_) {

}
struct Menu {
    int input_Case{};

    void correr_menu()
    {
        system("cls");
        int input =0;

        do {
            system("cls");

            cout << "\n\nMenu de opciones" << endl;
            cout << "1. Personas libres (sin distanciamiento social)" << endl;
            /* Particulas con igual velocidad, todas se mueven.
             * */
            cout << "2. Distanciamiento social promedio" << endl;
            /*
             * 1/4 de Particulas se mueven las otras no se mueven.
             * */
            cout << "3. Distanciamiento social extensivo" << endl;
            /*
             * 12.5% de particulas se mueve. Las demas no se mueven
             * */
            cout << "4. SALIR" << endl<<endl;

            cout << "Ingrese una opcion : ";

            cin >> input_Case;
        }while (input_Case>4 || 1>input_Case);

    }

};


#endif //CLIONPROYECT_MENU_H
