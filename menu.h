////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 30/08/2018.
// ULTIMA ACTUALIZACION : 25/09/2018.
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
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "archivos.h" // Libreria con funciones de archivos
#include "auxiliares.h" // Libreria auxiliar
#include "submenu.h"

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

void menuPrecio();
void menuFreelancers();
void menuReportes();

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
        cout << "|                      1.        Precio por hora                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.          Freelancers                               |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Reportes                                |" << endl;
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
                menuPrecio();
            }break;
            case 2:
            {
                menuFreelancers();
            }break;
            case 3:
            {
                menuReportes();
            }break;
            case 4:
            {
                if(confirmar())
                    return;
            }break;
        }//Fin switch

    }//Fin while

}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuPrecio()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                               PRECIO POR HORA                              |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.    Mostrar precio por hora                         |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.  Configurar precio por hora                        |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.             Nada                                   |" << endl;
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
                mostrarPrecios();
            }break;
            case 2:
            {
                cambiarPrecios();
            }break;
            case 3:
            {
                cout << "Nada" << endl;
                pedirEnter("Presion enter para volver ");
            }break;
            case 4:
            {
                return;
            }break;
        }//Fin switch

    }//Fin while
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuFreelancers()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                 FREELANCES                                 |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.      Agregar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.       Buscar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.             Nada                                   |" << endl;
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
                pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");
            }break;
            case 2:
            {
                menuBusqueda();
            }break;
            case 3:
            {
                cout << "tres" << endl;
                pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");
            }break;
            case 4:
            {
                return;
            }break;
        }//Fin switch


    }//Fin while

}

void menuReportes()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                  REPORTES                                  |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.      Agregar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.       Buscar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.             Nada                                   |" << endl;
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
                pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");
            }break;
            case 2:
            {
                cout << "dos" << endl;
                pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");
            }break;
            case 3:
            {
                cout << "tres" << endl;
                pedirEnter("\n\n[pedido de enter auxiliar/temporal] ");
            }break;
            case 4:
            {
                return;
            }break;
        }//Fin switch


    }//Fin while
}

#endif // MENU_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

