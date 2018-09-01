#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "archivos.h"

using namespace std;


void intro()
{
    cout<<"Hola"<<endl;
}

void salida()
{
    cout<<"Chau"<<endl;
}

void menu()
{

    bool salir = false;
    while(!salir)
    {

        char op[2];
        cout << "#=====================#" << endl;
        cout << "|                     |" << endl;
        cout << "|      1.             |" << endl;
        cout << "|      2.             |" << endl;
        cout << "|      3.             |" << endl;
        cout << "|      4.             |" << endl;
        cout << "|      5. Salir       |" << endl;
        cout << "|                     |" << endl;
        cout << "+---------------------+" << endl;

        sys::getline(op,2);
        switch(op[0])
        {



        }//Fin switch
    }//Fin while
}//Fin menu()


#endif // MENU_H_INCLUDED
