////#############################################################################
// ARCHIVO              : archivos.h
// AUTOR                : Javier Pereyra
// FECHA DE CREACION    : 01/09/2018.
// ULTIMA ACTUALIZACION : 01/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Linux (Ubuntu).
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : GNU GCC Compiler (Linux).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
// test
/////////////////////////////////////////////////////////////////////////////////
#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <cstdio> // Libreria para el manejo de archivos

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
bool existeArchivo(const char *URL)
{
    bool existe = false;

    FILE *archivo;
    archivo = fopen(URL,"rb");
    if( archivo != NULL )
    {
        fclose(archivo);
        existe = true;
    }

    return existe;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
bool creaArchivo(const char *URL)
{
    bool estado = false;

    FILE *archivo;
    archivo = fopen(URL,"wb");
    if( archivo != NULL )
    {
        fclose(archivo);
        estado = true;
    }

    return estado;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
template <typename T>
bool escribirArchivo(T *datos, const char *URL)
{
    bool error = true;

    FILE *archivo;
    archivo = fopen(URL,"rb");
    if( archivo != NULL )
    {
        fwrite(datos, sizeof(T), 1, archivo);
        fclose(archivo);
        error = false;
    }

    return error;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
template <typename T>
bool leerArchivo(T *datos, const char *URL)
{
    bool error = true;

    FILE *archivo;
    archivo = fopen(URL,"rb");
    if( archivo != NULL )
    {
        fread(datos, sizeof(T), 1, archivo);
        fclose(archivo);
        error = false;
    }

    return error;
}




#endif // ARCHIVOS_H_INCLUDED
