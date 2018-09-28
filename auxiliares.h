////#############################################################################
// ARCHIVO              : auxiliares.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 01/09/2018.
// ULTIMA ACTUALIZACION : 28/09/2018.
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
// FUNCION : void pedirEnter(const char* txt = "")
// ACCION : recive una cadena.
// PARAMETROS: const char* txt -> .
// DEVUELVE : void.
//-----------------------------------------------------------------------------
void pedirEnter(const char* txt = "")
{
    char enter[2];
    cout << txt;
    sys::getline(enter, 2);
}

//=============================================================================
// FUNCION : bool strSub(char* cad, char* subc)
// ACCION : Recorre la primera cadena en busca de la aparición de la segunda
//          cadena.
// PARAMETROS: const char* cad ->
//             char* subc ->
// DEVUELVE : bool --> true si se encuentra la subcadena, false caso contrario.
//-----------------------------------------------------------------------------
bool strSub(const char* cad, char* subc)
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
// FUNCION : int validarOpcion(int _max)
// ACCION : validas el ingreso  de numeros.
// PARAMETROS: int _max -> valida el valor entero ingresado.
// DEVUELVE : int --> devuelve un valor del resultado de una
// operacion matematica de resta.
//-----------------------------------------------------------------------------
char validarOpcion(const char* opciones, const char* textoError="Ingrese una opcion del menu: ")
{
    char op[2];
    sys::getline(op, 2);

    while( strlen(op) != 1 || !strSub(opciones, op) )
    {
        if( strlen(op) != 1 )
            cout << "Ingrese un caracter: ";
        else
            cout << textoError;

        sys::getline(op, 2);
    }

    return op[0];
}

//=============================================================================
// FUNCION : bool confirmar(const char* texto = "Esta seguro? (s/n) ")
// ACCION : devuelve un valor booleando dependiendo de la opcion a tomar.
// PARAMETROS: const char* text -> .
// DEVUELVE : bool --> confirma si es verdadero o no.
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
// FUNCION : bool soloLetras(char* cad)
// ACCION : valida si el ingreso de la cadena es de solo letras de la a(A) a la z(Z)
// PARAMETROS: char* cad -> ingreso de cadena para validar si son todas letras.
// DEVUELVE : bool --> representa si la cadena esta armada totalmetne por caracteres.
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
// FUNCION : void validarNombre(char* cad, unsigned tam,
//           const char* textoErrorTam, const char*textoErrorLetras)
// ACCION : Ingresa una cadena, el tamaño de la misma, tambien un texto explicativo
//          en caso de error y ademas un error por si se ingresan letras incorrectas.
// PARAMETROS: char* cad ->
//             unsigend tam ->
//             const char* textoErrorTam ->
//             const char* textoErrorLetras ->
// DEVUELVE : void --> no devuelve nada, ya que es una funcion de tipo void.
//-----------------------------------------------------------------------------
void validarNombre(char* cad, unsigned tam, const char* textoErrorTam, const char* textoErrorLetras)
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
// FUNCION : void llenarEspacio(int cant)
// ACCION : Ingresa una cantidad de espacios las cuales luego las completa con una
//          salida vacia.
// PARAMETROS: int cant -> cantidad de espacios.
// DEVUELVE : void --> no devuelve ningun tipo de valor.
//-----------------------------------------------------------------------------
void llenarEspacio(int cant)
{
    for(int x=0; x<cant; x++)
        cout << " ";
}

//=============================================================================
// FUNCION : long long strToInt(char* cad)
// ACCION : Transforma caracteres numericos en caracteres long
// PARAMETROS: char* cad -> cadena que luego es transformada.
// DEVUELVE : long long --> devuelve la cadena como enteros.
//-----------------------------------------------------------------------------
long long strToInt(char* cad)
{
    long long cadenaInt = 0;
    int aux;
    long long base10 = 1;

    for(int x=strlen(cad)-1; x>=0; x--)
    {
        aux = (int)cad[x]-48;
        cadenaInt += aux*base10;
        base10 *= 10;
    }

    return cadenaInt;
}

//=============================================================================
// FUNCION : bool esEntero(char* cadena)
// ACCION : valida si el ingreso de la cadena dispone de numeros enteros.
// PARAMETROS: char*, cadena, recorre y valida que la misma disponga
//             de valores menores a 0 y 9
// DEVUELVE : bool --> valida si la cadena ingresa tiene caracteres numeros.
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
long long validarDNI()
{
    char dni[12];
    sys::getline(dni, 12);
    while(!esEntero(dni) || strlen(dni)<1 || strlen(dni)>10)
    {
        if(!esEntero(dni))
            cout << "Por favor, ingrese solo numeros: ";
        else if(strlen(dni)>10)
            cout << "Ingrese un DNI de no mas de 10 cifras: ";
        sys::getline(dni, 12);
    }
    return strToInt(dni);
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
int validarHoras()
{
    char hs[4];
    sys::getline(hs, 4);
    while(!esEntero(hs) || strlen(hs)<1 || strToInt(hs)>250)
    {
        if(!esEntero(hs))
            cout << "Ingrese solo numeros: ";
        else if(strToInt(hs)>250)
            cout << "No se acepta un ingreso mayor a 250, intente nuevamente: ";
        sys::getline(hs, 4);
    }
    return strToInt(hs);
}

//=============================================================================
// FUNCION : void toUpper(char* cadena)
// ACCION : transforma la cadena en Mayuscula.
// PARAMETROS: char* cadena -> recorre la cadena y hace una operacion matematica
//             para transformarla en mayuscula.
// DEVUELVE : void --> no devuelve ningun valor.
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
// FUNCION : void toLower(char* cadena)
// ACCION : transforma toda la cadena de caracteres en minuscula
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
//             que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : void.
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
// FUNCION : void firstUpper(char *cad)
// ACCION : Transformar el primero caracter de la cadena en mayuscula
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
//             que representa, y valores posibles si existieran limitaciones).
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
// FUNCION : int intlen(unsigned n)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
//             que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : int --> cantidad de cifras del número pasado por parámetro.
//-----------------------------------------------------------------------------
int intlen(unsigned n)
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

