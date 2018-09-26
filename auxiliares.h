////#############################################################################
// ARCHIVO              : auxiliares.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 01/09/2018.
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
#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

//*****************************************************************************
//                             INCLUSIONES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include <cstring>

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

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
bool confirmar(const char* texto = "Esta seguro? (s/n) ")
{
    char conf[2];
    cout << texto;
    sys::getline(conf, 2);
    if(conf[0] == 's' || conf[0] == 'S')
        return true;
    else
        return false;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
bool soloLetras(char* cad)
{
    for(int x=0; cad[x]!='\0'; x++)
    {
        if((cad[x]<'A' || cad[x]>'Z') && (cad[x]<'a' || cad[x]>'z'))
            return false;
    }
    return true;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void validarNombre(char* cad, unsigned int tam, const char* textoErrorTam, const char* textoErrorLetras)
{
    char aux[tam + 2];
    sys::getline(aux, tam);
    while(!soloLetras(aux) || strlen(aux)>tam)
    {
        if(strlen(aux)>tam)
            cout << textoErrorTam;
        else
            cout << textoErrorLetras;
        sys::getline(aux, tam);
    }
    strcpy(cad, aux);
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void llenarEspacio(int cant)
{
    for(int x=0; x<cant; x++)
        cout << " ";
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
int strToInt(char* cad)
{
    int cadenaInt = 0;
    int aux;
    unsigned int base10 = 1;

    for(int x=strlen(cad)-1; x>=0; x--)
    {
        aux = (int)cad[x]-48;
        cadenaInt += aux*base10;
        base10 *= 10;
    }

    return cadenaInt;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
bool esEntero(char* cadena)
{
    for(int x=0; cadena[x]!='\0'; x++)
    {
        if(cadena[x]<'0' || cadena[x]>'9')
            return false;
    }
    return true;
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void toUpper(char* cadena)
{
    for(int x=0; cadena[x]!='\0'; x++)
    {
        if( cadena[x]>='a' && cadena[x]<='z' )
            cadena[x] = cadena[x]-32;
    }
}

//=============================================================================
// FUNCION : toLower(*cadena)
// ACCION : transforma toda la cadena de caracteres en minuscula
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void toLower(char* cadena)
{
    for(int x=0; cadena[x]!='\0'; x++)
    {
        if( cadena[x]>='a' && cadena[x]<='z' )
            cadena[x] = cadena[x]+32;
    }
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
bool strSub(char* cad, char* subc)
{
    bool igualdad;

    for(int x=0; cad[x]!='\0'; x++)
    {
        igualdad = true;
        if(cad[x]==subc[0])
        {
            for(int y=0; subc[y]!='\0'; y++)
            {
                if(cad[x+y]!=subc[y])
                    igualdad=false;
            }

            if(igualdad)
                return true;
        }
    }
    return false;
}

//=============================================================================
// FUNCION : primercaracterUpper(*cad)
// ACCION : Transformar el primero caracter de la cadena en mayuscula
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : no devuelve nada ya que es void.
//-----------------------------------------------------------------------------
void firstUpper(char *cad)
{
    if( cad[0]>='a' && cad[0]<='z')
        cad[0] -= 32;

    for(int x=1; cad[x]!='\0'; x++)
    {
        if( cad[x]>='A' && cad[x]<='Z' )
            cad[x] += 32;
    }
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
int intlen(unsigned int n)
{
    int cont = 0;
    do{
        n /= 10;
        cont++;
    }while(n > 0);

    return cont;
}

#endif // AUXILIARES_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

