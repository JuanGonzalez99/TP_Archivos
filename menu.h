////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 30/08/2018.
// ULTIMA ACTUALIZACION : 26/09/2018.
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
#include "submenu.h" // Libreria auxiliar

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void bienvenida()
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
void despedida()
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
        cout << "|                      s.             Salir                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123Ss");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                menuPrecio();
            }break;
            case '2':
            {
                menuFreelancers();
            }break;
            case '3':
            {
                menuReportes();
            }break;
            case 'S':
            case 's':
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
        cout << "|                                                                            |" << endl;
        cout << "|                      2.  Configurar precio por hora                        |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                mostrarPrecios();
            }break;
            case '2':
            {
                menuConfigPrecios();
            }break;
            case '3':
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
        cout << "|                      3.     Modificar freelance                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.    Carga de horas por DNI                          |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      5.    Carga de horas general                          |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      6.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123456");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                menuAgregar();
            }break;
            case '2':
            {
                menuBusqueda();
            }break;
            case '3':
            {
                menuModificarFreelance();
            }break;
            case '4':
            {
                menuCargaDNI();
            }break;
            case '5':
            {
                menuCargaGral();
            }break;
            case '6':
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
        cout << "|                      1.     Horas trabajadas por                           |" << endl;
        cout << "|                               tipo de freelance                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.        Reporte general                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                reportePorTipo();
            }break;
            case '2':
            {
                reporteGeneral();
            }break;
            case '3':
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

