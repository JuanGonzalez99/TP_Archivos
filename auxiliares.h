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
//  En esta libreria se desarrollan funciones para la validacion de ingresos,
//  en su mayoria, y tambien se encuentran funciones auxiliares para el
//  emprolijamiento de la salida por pantalla.
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
// ACCION : esta funcion es llamada cuando se quiera pedir un enter al usuario.
//          está especializada para que un ingreso accidental de caracteres extra
//          no perjudique al buen funcionamiento programa.
// PARAMETROS: const char* txt -> texto que se le mostrará al usuario,
//                                generalmente indicando para qué se le precisa
//                                apretar la tecla enter.
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
// PARAMETROS: const char* cad -> cadena que será recorrida.
//             char* subc -> cadena que será buscada.
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
// FUNCION : char validarOpcion(const char* opciones,
//           const char* textoError="Ingrese una opcion del menu: ")
// ACCION : validas el ingreso  de numeros.
// PARAMETROS: const char* opciones -> valida el valor entero ingresado.
//             const char* textoError -> .
// DEVUELVE : char -->
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
// ACCION : pide al usuario la confirmacion de una accion. Generalmente se
//          utiliza para confirmar la eliminacion de un registro o el cierre
//          del programa, que es su fin en este trabajo.
// PARAMETROS: const char* text -> texto aclarando qué se le pide al usuario.
// DEVUELVE : bool --> true si el usuario confirma, false caso contrario.
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
// ACCION : valida si el ingreso de la cadena es de solo letras, y tambien se
//          permiten espacios, ya que se utiliza para validar nombres, los cuales
//          pueden ser compuestos (ej: De La Torre).
// PARAMETROS: char* cad -> cadena de caracteres a validar.
// DEVUELVE : bool --> true si solo contiene letras y/o espacios, false caso contrario.
//-----------------------------------------------------------------------------
bool soloLetras(char* cad)
{
    for(int x=0; cad[x]!='\0'; x++)
    {
        if((cad[x]<'A' || cad[x]>'Z') && (cad[x]<'a' || cad[x]>'z') && cad[x]!=' ')
            return false;
    }
    return true;
}

//=============================================================================
// FUNCION : void validarNombre(char* cad, unsigned tam,
//           const char* textoErrorTam, const char*textoErrorLetras)
// ACCION :
// PARAMETROS: char* cad -> cadena a validar
//             unsigend tam -> tamaño maximo de caracteres permitidos.
//             const char* textoErrorTam -> texto que se le dispondrá al
//                                          usuario si se pasa del tamaño
//                                          previamente mencionado.
//             const char* textoErrorLetras -> texto que se le dispondrá al
//                                             usuario si ingresa caracteres
//                                             que no sean letras o espacios.
// DEVUELVE : void --> no devuelve nada, ya que es una funcion de tipo void.
//-----------------------------------------------------------------------------
void validarNombre(char* cad, unsigned tam, const char* textoErrorTam, const char* textoErrorLetras)
{
    char aux[tam + 2];
    sys::getline(aux, tam);
    while(!soloLetras(aux) || strlen(aux)>tam || strlen(aux)<1)
    {
        if(strlen(aux)>tam)
            cout << textoErrorTam;
        else if(!soloLetras(aux))
            cout << textoErrorLetras;
        sys::getline(aux, tam);
    }
    strcpy(cad, aux);
}

//=============================================================================
// FUNCION : void llenarEspacio(int cant)
// ACCION : saca por pantalla una cantidad cant de espacios. Se utiliza para
//          el alineamiento de datos dinamicos.
// PARAMETROS: int cant -> cantidad de espacios.
// DEVUELVE : void --> no devuelve nada.
//-----------------------------------------------------------------------------
void llenarEspacio(int cant)
{
    for(int x=0; x<cant; x++)
        cout << " ";
}

//=============================================================================
// FUNCION : long long strToInt(char* cad)
// ACCION : Transforma una cadena de caracteres en un numero.
// PARAMETROS: char* cad -> cadena a ser transformada.
// DEVUELVE : long long --> cadena pasada a numeros.
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
// ACCION : valida si la cadena ingresada dispone unicamente de numeros enteros.
// PARAMETROS: char* cadena -> cadena sobre la que se hara la validacion
// DEVUELVE : bool --> true si solo tiene numeros, false caso contrario.
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
// FUNCION : long long validarDNI()
// ACCION : pide al usuario el ingreso de un DNI, y se asegura de que sea un
//          ingreso valido.
// PARAMETROS: -.
// DEVUELVE : long long --> DNI validado.
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
// FUNCION : int validarHoras()
// ACCION : pide al usuario el ingreso de horas (trabajadas) y no permite
//          ingresos no validos.
// PARAMETROS: -.
// DEVUELVE : int --> un numero de horas validadas.
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
// ACCION : transforma todas las letras la cadena en Mayuscula.
// PARAMETROS: char* cadena -> cadena a transformar.
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
// FUNCION : void firstUpper(char *cad)
// ACCION : Transformar el primer caracter de la cadena en mayuscula y el resto
//          en minuscula
// PARAMETROS: char *cad -> cadena que sufrira la transformacion.
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
// ACCION : cuenta las cifras del numero pasado por parametro y retorna la cantidad.
// PARAMETROS: unsigned n
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

//=============================================================================
// FUNCION : void cortarEn(int fin, const char* cpy, char* paste)
// ACCION : toma una cadena y le copia los caracteres de otra hasta la posicion
//          fin.
// PARAMETROS: int fin -> posicion en la que se desea cortar la cadena.
//             const char* cpy -> cadena de la que se tomaran los caracteres.
//             char* paste -> cadena a modificar.
// DEVUELVE : void --> no devuleve nada.
//-----------------------------------------------------------------------------
void cortarEn(int fin, const char* cpy, char* paste)
{
    for(int x=0; x<fin; x++)
    {
        paste[x] = cpy[x];
    }
    paste[fin] = '\0';
}

#endif // AUXILIARES_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

