////#############################################################################
// ARCHIVO              : auxiliares.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 01/09/2018.
// ULTIMA ACTUALIZACION : 02/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Windows 10.
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : MinGW (Windows).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

//*****************************************************************************
//                             INCLUSIONES
//=============================================================================
#include <iostream> // Libreria para la entrada y salida por consola
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
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
void pedirEnter(const char* txt = "")
{
    char enter[2];
    cout << txt;
    sys::getline(enter, 2);
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
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

#endif // AUXILIARES_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

