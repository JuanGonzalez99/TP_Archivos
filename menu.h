#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream> // Libreria para la entrada y salida por consola
#include <string.h> // Libreria para el manejo de cadenas
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "archivos.h" // Libreria para las funciones de archivos

using namespace std;

void pedirEnter(const char* txt = "")
{
    char enter[2];
    cout << txt;
    sys::getline(enter, 2);
}

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
        sys::cls();
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
        cout << endl;
        cout << "Ingrese una opcion: ";
        sys::getline(op,2);



        switch(op[0])
        {



        }//Fin switch
    }//Fin while
}//Fin menu()


#endif // MENU_H_INCLUDED
