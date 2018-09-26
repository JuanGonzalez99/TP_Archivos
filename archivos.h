////#############################################################################
// ARCHIVO              : archivos.h
// AUTOR                : Javier Pereyra
// FECHA DE CREACION    : 01/09/2018.
// ULTIMA ACTUALIZACION : 25/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Linux (Ubuntu).
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : GNU GCC Compiler (Linux).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aqu� va una descripci�n general de la libreria
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
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
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
// FUNCION : leerPrecioh()
// ACCION : Abre el archivo, procede a leerlo y devolver una estructura auxiliar
// DEVUELVE : tPrecios / Devuelve la estructura auxiliar para luego ser usada por
// otras subfunciones.
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
// FUNCION : guardarPrecios(tPrecios reg)
// ACCION : resguarda el precio de los freelancers.
// PARAMETROS: reg: tPrecio.
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
// FUNCION : guardaFreelancers(reg,DNI,*NOMBRE,*)
// ACCION : Se ingresa tanto la estructura , tanto as� como el resguardo de sus variables.
// PARAMETROS: DNI,NOMBRE,APELLIDO,HORAS,TIPO
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
// FUNCION : cantRegistros(*URL)
// ACCION : Se ingresa la estructura para luego cargar la misma.
// PARAMETROS: *v
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
long cantRegistros(const char *URL)
{
    FILE *p;
    p = fopen(URL,"ab");
    if(p==NULL){
        exit(1);
    }
    fseek(p,0,2);
    long cantidadBytes = ftell(p);
    fclose(p);
    return cantidadBytes/sizeof(struct Freelance);

}

//=============================================================================
// FUNCION : llenarFreelances(*v)
// ACCION : Se ingresa la estructura para luego cargar la misma.
// PARAMETROS: *v
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
void llenarFreelances(Freelance *v)
{

    // Asignacion de datos de freelance al vector.
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL){
        exit(1);
    }
    Freelance aux;
    int i = 0;

    while(fread(&aux,sizeof(Freelance),1,p)==1)
    {
        v[i] = aux;
        i++;
    }

    fclose(p);


}

//=============================================================================
// FUNCION : existeFreelancedni
// ACCION : Se ingresa el dni y devuelve un valor booleano.
// PARAMETROS: dni
// DEVUELVE : bool ( el mismo se usa para validar si existe o no el freelance ).
//-----------------------------------------------------------------------------
bool existeFreelance(int dni)
{
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL){
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
// FUNCION : buscarFreelance
// ACCION : se ingresa el dni y se devuelve la estructura para su posterior
// manipulacion.
// PARAMETROS: dni
// DEVUELVE : Freelance , estructura de datos.
//-----------------------------------------------------------------------------
Freelance buscarFreelanceDNI(int dni)
{

    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL)
    {
        exit(1);
    }
    Freelance auxiliar; // Armo una estructura auxiliar para la copia binaria de datos y la devuelvo a la misma si solo existe el DNI.

    while(fread(&auxiliar,sizeof(Freelance),1,p)){

    if(dni == auxiliar.DNI)
    {

    return auxiliar; //retorno toda la estructura

    }
    }

return auxiliar;

}

//=============================================================================
// FUNCION : contarReg
// ACCION : se ingresa el dni y se devuelve la estructura para su posterior
// manipulacion.
// PARAMETROS:
// DEVUELVE : int , cantidad de registros de un archivo.
//-----------------------------------------------------------------------------


#endif // ARCHIVOS_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

