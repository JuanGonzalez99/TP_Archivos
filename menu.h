////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 30/09/2018.
// ULTIMA ACTUALIZACION : 01/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Linux (Ubuntu) / Windows 10.
// IDE                  : Code::Blocks - 16.01 / 17.12
// COMPILADOR           : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream> // Libreria para la entrada y salida por consola
#include <string.h> // Libreria para el manejo de cadenas

#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "archivos.h" // Libreria con funciones de archivos
#include "auxiliares.h" // Libreria auxiliar

using namespace std;

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void intro()
{

    cout << "Hola" << endl;
    pedirEnter("\n\nPresione enter ");
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void salida()
{
    sys::cls();
    cout << "Chau" << endl;
    pedirEnter("\n\nPresione enter ");
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
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
