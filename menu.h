////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 30/09/2018.
// ULTIMA ACTUALIZACION : 02/09/2018.
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

//*****************************************************************************
//                             INCLUSIONES
//=============================================================================
#include <iostream> // Libreria para la entrada y salida por consola
#include <string.h> // Libreria para el manejo de cadenas

#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "archivos.h" // Libreria con funciones de archivos
#include "auxiliares.h" // Libreria auxiliar

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

void menuConfig();
void menuBusqueda();
void menuListados();

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuPrincipal()
{
    bool salir = false;
    while(!salir)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                               MENU PRINCIPAL                               |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.   Configurar precio por hora                       |" << endl;
        cout << "|                                Cargar empleados                            |" << endl;
        cout << "|                                  Cargar horas                              |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.        Buscar empleado                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Listados                                |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.             Salir                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        int op = validarOpcion(4);

        sys::cls();
        switch(op)
        {
            case 1:
            {
                menuConfig();
            }break;
            case 2:
            {
                menuBusqueda();
            }break;
            case 3:
            {
                menuListados();
            }break;
            case 4:
            {
                salir = true;
                continue;
            }break;
        }//Fin switch

//        pedirEnter("Presione enter para volver ");

    }//Fin while

}//Fin función menu()

void menuConfig()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                CONFIG/CARGA                                |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.   Configurar precio por hora                       |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.       Cargar empleados                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.     Cargar horas de todos                          |" << endl;
        cout << "|                             Cargar horas por DNI                           |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        int op = validarOpcion(4);

        sys::cls();
        switch(op)
        {
            case 1:
            {
                cout << "uno" << endl;
            }break;
            case 2:
            {
                cout << "dos" << endl;
            }break;
            case 3:
            {
                cout << "tres" << endl;
            }break;
            case 4:
            {
                volver = true;
                continue;
            }break;
        }//Fin switch

        pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");

    }//Fin while
}

void menuBusqueda()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#==============================================================================#" << endl;
        cout << "|                            BUSQUEDA DE EMPLEADO                              |" << endl;
        cout << "#==============================================================================#" << endl;
        cout << endl;
        cout << "A quien desea buscar? ";

        if(validarOpcion(10))
            return;

    }//Fin while
}

void menuListados()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                  LISTADOS                                  |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.    Precio por hora segun                           |" << endl;
        cout << "|                               tipo de empleado                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.    Horas trabajadas por                            |" << endl;
        cout << "|                            cada tipo de empleado                           |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.       Listado general                              |" << endl;
        cout << "|                                 de empleados                               |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        int op = validarOpcion(4);

        sys::cls();
        switch(op)
        {
            case 1:
            {
                cout << "uno" << endl;
            }break;
            case 2:
            {
                cout << "dos" << endl;
            }break;
            case 3:
            {
                cout << "tres" << endl;
            }break;
            case 4:
            {
                volver = true;
                continue;
            }break;
        }//Fin switch

        pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");

    }//Fin while

}

#endif // MENU_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

