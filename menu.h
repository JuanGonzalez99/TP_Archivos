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
    pedirEnter("\n\nPresione enter ");
}

void salida()
{
    sys::cls();
    cout<<"Chau"<<endl;
    pedirEnter("\n\nPresione enter ");
}

int validarOpcion(int _max)
{
    char op[2];
    sys::getline(op, 2);

    while( strlen(op) != 1 || op[0] < '1' || op[0] > char(_max+48) )
    {
        if( strlen(op) != 1 )
            cout << "Ingrese un caracter: ";
        else
            cout << "Ingrese una opcion del menu: ";

        sys::getline(op, 2);
    }

    return int(op[0]-48);
}

void menu()
{

    bool salir = false;
    while(!salir)
    {
        sys::cls();
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

        int op = validarOpcion(5);

        sys::cls();
        switch(op)
        {
            case 1:
            {
                cout << "uno";
            }break;
            case 2:
            {
                cout << "dos";
            }break;
            case 3:
            {
                cout << "tres";
            }break;
            case 4:
            {
                cout << "cuatro";
            }break;
            case 5:
            {
                salir = true;
            }break;
        }//Fin switch

        pedirEnter("\n\nPresione enter para continuar ");

    }//Fin while
}//Fin menu()


#endif // MENU_H_INCLUDED
