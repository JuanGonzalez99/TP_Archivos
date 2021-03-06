////#############################################################################
// ARCHIVO              : archivos.h
// AUTOR                : Javier Pereyra
// FECHA DE CREACION    : 01/09/2018.
// ULTIMA ACTUALIZACION : 28/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Linux (Ubuntu).
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : GNU GCC Compiler (Linux).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//  Esta libreria contiene todas las funciones que trabajan con archivos.
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

//*****************************************************************************
//                             INCLUSIONES
//=============================================================================
#include <cstdio> // Libreria para el manejo de archivos
#include "auxiliares.h" //Libreria auxiliar de manejo de strings.

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : bool existeArchivo(const char *URL)
// ACCION : abre el archivo en modo lectura, valida si
// tiene contenido NULO devolviendo falso
// si es as� o verdadero si as� no es.
// PARAMETROS: const char *URL -> representa el puntero al archivo.
// DEVUELVE : bool --> representa la existencia del archivo
//-----------------------------------------------------------------------------
bool existeArchivo(const char *URL)
{
    FILE *p;
    p = fopen(URL,"rb");
    if( p == NULL )
    {

        return false;
    }

    fclose(p);
    return true;
}

//=============================================================================
// FUNCION : tPrecios leerPrecios()
// ACCION : Abre el archivo, procede a leerlo y devolver una estructura auxiliar
// DEVUELVE : tPrecios -> Devuelve la estructura auxiliar para luego ser usada por
//            otras subfunciones relacionadas con el submenu y menu.
//-----------------------------------------------------------------------------
tPrecios leerPrecios()
{
    FILE *p;
    p = fopen(PRECIOS,"rb");
    if(p==NULL)
    {
        exit(1);
    }
    tPrecios auxiliar; // Armo una estructura para la cosa

    fread(&auxiliar,sizeof(tPrecios),1,p); // leo el archivo abierto

    fclose(p);

    return auxiliar; //retorno toda la estructura

}

//=============================================================================
// FUNCION : void guardarPrecios(tPrecios reg)
// ACCION : resguarda el precio de los freelancers por unica vez
// PARAMETROS: tPrecios, reg, representa el ingreso de
// una estructura de tipo tPrecios.
// DEVUELVE : no devuelve nada al ser una funcion void.
//-----------------------------------------------------------------------------
void guardarPrecios(tPrecios reg)
{

    FILE *p;
    p = fopen(PRECIOS,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(&reg,sizeof(tPrecios),1,p);
    fclose(p);

}

//=============================================================================
// FUNCION : void guardaFreelancers(Freelance reg)
// ACCION : Se ingresa tanto la estructura , tanto as� como el resguardo de sus variables.
// PARAMETROS: Freelance, reg, la misma se utiliza para el ingreso de una estructura
// de tipo Freelance para el resguardo de estos datos en el archivo.
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
void guardarFreelance(Freelance reg)
{

    FILE *p;
    p = fopen(FREELANCES,"ab");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(&reg,sizeof(Freelance),1,p);
    fclose(p);


}

//=============================================================================
// FUNCION : long cantRegistros()
// ACCION : se dispone a leer la cantidad de registros.
// DEVUELVE : long -> la cantidad de bytes dividido la estructura Freelance
//-----------------------------------------------------------------------------
long cantRegistros()
{
    FILE *p;
    p = fopen(FREELANCES,"ab");
    if(p==NULL)
    {
        exit(1);
    }
    fseek(p,0,2);
    long cantidadBytes = ftell(p);
    fclose(p);
    return cantidadBytes/sizeof(Freelance);

}

//=============================================================================
// FUNCION : void llenarFreelances(Freelance *v)
// ACCION : Se ingresa la estructura como un puntero para luego ser posible
// para el procesamiento de un vector de estructuras y asi realizar
// la copia binaria de los datos de la estructura
// haciendo referencia al vector sub indice.
// PARAMETROS: Freelance *v -> permite el ingreso de un vector de estructuras.
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
void llenarFreelances(Freelance *v)
{

    // Asignacion de datos de freelance al vector.
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    int i = 0;

    while(fread(&v[i],sizeof(Freelance),1,p)==1)
    {
        i++;
    }

    fclose(p);


}

//=============================================================================
// FUNCION : bool existeFreelance(long long dni)
// ACCION : Se ingresa el dni para luego leer el
// archivo y validar la existencia del Freelance.
// PARAMETROS: long long dni -> Se ingresa el dni para luego hacer la busqueda.
// DEVUELVE : bool ( el mismo se usa para validar si existe o no el freelance ).
//-----------------------------------------------------------------------------
bool existeFreelance(long long dni)
{
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL)
    {
        exit(1);
    }
    Freelance reg;

    while(fread(&reg,sizeof(Freelance),1,p))
    {

        if(dni == reg.DNI)
        {

            fclose(p);
            return true;

        }
    }

    fclose(p);
    return false;


}

//=============================================================================
// FUNCION : Freelance buscarFreelanceDNI(dni)
// ACCION : se ingresa el dni y se devuelve la estructura para su posterior
// manipulacion.
// PARAMETROS: long long dni -> se valida la existencia del freelance y se devuelve
//             la estructura del mismo.
// DEVUELVE : Freelance --> estructura de datos.
//-----------------------------------------------------------------------------
Freelance buscarFreelanceDNI(long long dni)
{

    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL)
    {
        exit(1);
    }
    Freelance auxiliar; // Armo una estructura auxiliar para la copia binaria de datos y la devuelvo a la misma si solo existe el DNI.

    while(fread(&auxiliar,sizeof(Freelance),1,p))
    {

        if(dni == auxiliar.DNI)
        {

            fclose(p);
            return auxiliar; //retorno toda la estructura

        }
    }
    fclose(p);
    return auxiliar;

}

//=============================================================================
// FUNCION : Freelance modificarFreelance(reg)
// ACCION : Se ingresa la estructura para luego obtener el dato de DNI
//          para luego comparar contra el dato del DNI del archivo.
// PARAMETROS: Freelance reg -> se valida la existencia del mismo en cuanto su DNI
//              sea el mismo.
// DEVUELVE : void --> ningun dato, ya que se proceden a modificar registros
//-----------------------------------------------------------------------------
void modificarFreelance(Freelance reg)
{

//Set de variables, para modificar valores de Freelance
    FILE *p;
    p = fopen(FREELANCES,"rb+");
    Freelance aux;
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&aux,sizeof(Freelance),1,p)==1)
    {
    // Valido el registro de DNI que me pasastes con el registro de DNI que leo del disco.
        if(reg.DNI == aux.DNI){
            fseek(p, ftell(p)-sizeof aux, 0);
            fwrite(&reg, sizeof(Freelance), 1, p);
            fclose(p);
            return;
            }
    }

    fclose(p);



}



#endif // ARCHIVOS_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

