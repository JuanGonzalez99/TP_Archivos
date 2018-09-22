////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 22/09/2018.
// ULTIMA ACTUALIZACION : 22/09/2018.
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
void mostrarPrecios()
{
    if(!existeArchivo(PRECIOS))
    {
        creaArchivo(PRECIOS);
        tPrecios aux;
        aux.diseniadores = 300;
        aux.desarrolladores = 350;
        aux.analistas = 400;
        guardarPrecios(aux);
    }
    tPrecios precios = leerPrecios();
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                   PRECIO POR HORA SEGUN TIPO DE EMPLEADO                   |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Diseñadores: " << precios.diseniadores << endl;
    cout << "Desarrolladores: " << precios.desarrolladores << endl;
    cout << "Analistas: " << precios.analistas << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    pedirEnter("\n\nPresione enter para volver ");
}

void verificarPrecios(tPrecios reg)
{

    FILE *p;
    p = fopen(PRECIOS,"rb");
    if(p == NULL)
    {
            exit(1);
    }

    while(fread(&reg,sizeof(tPrecios),1,p)==1)
    {

    if(!existeArchivo(PRECIOS))
    {
        creaArchivo(PRECIOS);
        tPrecios aux;
        aux.diseniadores = 300;
        aux.desarrolladores = 350;
        aux.analistas = 400;
        guardarPrecios(aux);
    }

    }



}

void verificarEmpleados(Empleado reg)
{




}

#endif // SUBMENU_H_INCLUDED
