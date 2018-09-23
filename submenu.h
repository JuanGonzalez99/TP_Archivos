////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 22/09/2018.
// ULTIMA ACTUALIZACION : 23/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Windows 10.
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void verificarPrecios()
{
    if(!existeArchivo(PRECIOS))
    {
        tPrecios aux;
        aux.diseniadores = 300;
        aux.desarrolladores = 350;
        aux.analistas = 400;
        guardarPrecios(aux);
    }
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void mostrarPrecios()
{
    verificarPrecios();
    tPrecios precios = leerPrecios();
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                   PRECIO POR HORA SEGUN TIPO DE EMPLEADO                   |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Diseñadores: $" << precios.diseniadores << endl;
    cout << "Desarrolladores: $" << precios.desarrolladores << endl;
    cout << "Analistas: $" << precios.analistas << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    pedirEnter("\n\nPresione enter para volver ");
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void verificarEmpleados()
{
    if(!existeArchivo(EMPLEADOS))
    {
        Empleado _1; _1.DNI=36938292; strcpy(_1.nombre, "Pedro"); strcpy(_1.apellido, "Vega"); _1.horas=35; _1.tipo=DISENIADOR; guardaFreelancers(_1);
        Empleado _2; _2.DNI=32119232; strcpy(_2.nombre, "Pablo"); strcpy(_2.apellido, "Sardulex"); _2.horas=28; _2.tipo=DISENIADOR; guardaFreelancers(_2);
        Empleado _3; _3.DNI=33213333; strcpy(_3.nombre, "Marta"); strcpy(_3.apellido, "Martulo"); _3.horas=100; _3.tipo=DISENIADOR; guardaFreelancers(_3);
        Empleado _4; _4.DNI=39222823; strcpy(_4.nombre, "Miguel"); strcpy(_4.apellido, "Andaro"); _4.horas=33; _4.tipo=DISENIADOR; guardaFreelancers(_4);
        Empleado _5; _5.DNI=34232999; strcpy(_5.nombre, "Jesus"); strcpy(_5.apellido, "Aragon"); _5.horas=130; _5.tipo=DESARROLLADOR; guardaFreelancers(_5);
        Empleado _6; _6.DNI=35098098; strcpy(_6.nombre, "Natanel"); strcpy(_6.apellido, "Semilla"); _6.horas=22; _6.tipo=DESARROLLADOR; guardaFreelancers(_6);
        Empleado _7; _7.DNI=92003990; strcpy(_7.nombre, "Orlando"); strcpy(_7.apellido, "Satur"); _7.horas=57; _7.tipo=DESARROLLADOR; guardaFreelancers(_7);
        Empleado _8; _8.DNI=93003998; strcpy(_8.nombre, "Matias"); strcpy(_8.apellido, "Latero"); _8.horas=80; _8.tipo=DESARROLLADOR; guardaFreelancers(_8);
        Empleado _9; _9.DNI=27203199; strcpy(_9.nombre, "Ramiro"); strcpy(_9.apellido, "Simero"); _9.horas=33; _9.tipo=ANALISTA; guardaFreelancers(_9);
        Empleado _10; _10.DNI=28391955; strcpy(_10.nombre, "Santiago"); strcpy(_10.apellido, "Sasa"); _10.horas=39; _10.tipo=ANALISTA; guardaFreelancers(_10);
        Empleado _11; _11.DNI=33058999; strcpy(_11.nombre, "Gonzalo"); strcpy(_11.apellido, "Reibon"); _11.horas=28; _11.tipo=ANALISTA; guardaFreelancers(_11);
        Empleado _12; _12.DNI=32252495; strcpy(_12.nombre, "Rodrigo"); strcpy(_12.apellido, "Latete"); _12.horas=10; _12.tipo=ANALISTA; guardaFreelancers(_12);
    }
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuBusqueda()
{
    verificarEmpleados();

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

#endif // SUBMENU_H_INCLUDED
