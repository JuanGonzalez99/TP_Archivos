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
// aquí va una descripción general de la libreria
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
// FUNCION : buscarEmpleado(*cad, *vec)
// ACCION : lee la cadena apartir de uno dos strings y devuelve el valor completo.
// PARAMETROS: XXXXXXXXXXx
// DEVUELVE : no devuelve nada al ser una funcion void.
//-----------------------------------------------------------------------------
void buscarFreelance(char *cad, Freelance *vec)
{

    Freelance aux;
    int i = 0;
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&aux,sizeof(aux),1,p) == 1)
    {

        if(strSub(cad,vec[i].nombre) == 1 || strSub(cad,vec[i].apellido) == 1)
        {

            aux = vec[i];
            i++;

        }

    }


}

//=============================================================================
// FUNCION : guardaFreelancers(reg,DNI,*NOMBRE,*)
// ACCION : Se ingresa tanto la estructura , tanto así como el resguardo de sus variables.
// PARAMETROS: DNI,NOMBRE,APELLIDO,HORAS,TIPO
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
void guardaFreelances(Freelance reg)
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
// FUNCION : fileSize(*v)
// ACCION : Se ingresa la estructura para luego cargar la misma.
// PARAMETROS: *v
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
long fileSize(const char *URL)
{
    FILE *p;
    p = fopen(URL,"ab");
    if(p==NULL){
        exit(1);
    }
    fseek(p,0,2);
    long cantidadBytes = ftell(p);
    fclose(p);
    return cantidadBytes;

}

//=============================================================================
// FUNCION : llenarFreelances(*v)
// ACCION : Se ingresa la estructura para luego cargar la misma.
// PARAMETROS: *v
// DEVUELVE : Nada, es una funcion void.
//-----------------------------------------------------------------------------
void llenarFreelances(Freelance *v)
{

    // Asignacion dinamica de memoria para el vector de estructuras Freelance.
    long tamanodeArchivo;
    tamanodeArchivo = fileSize(FREELANCES); //<< TODO:tengo que ver por que no me esta tomando la URL.

    v=(Freelance *) malloc(tamanodeArchivo);
    if(v==NULL){
        exit(2);
    }

    // Asignacion de datos de freelance al vector.
    FILE *p;
    p = fopen(FREELANCES,"rb");
    if(p==NULL){
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
// FUNCION : existeFreelancedni
// ACCION : Se ingresa el dni y devuelve un valor booleano.
// PARAMETROS: dni
// DEVUELVE : bool ( el mismo se usa para validar si existe o no el freelance ).
//-----------------------------------------------------------------------------
bool existeFreelancedni(int dni)
{

    bool existe = false;
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
            existe = true;
            fclose(p);
            return existe;

        }

    }

    fclose(p);
    return existe;


}

//=============================================================================
// FUNCION : buscarFreelance
// ACCION : se ingresa el dni y se devuelve la estructura para su posterior
// manipulacion.
// PARAMETROS: dni
// DEVUELVE : Freelance , estructura de datos.
//-----------------------------------------------------------------------------
Freelance buscarFreelance(int dni)
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



}


#endif // ARCHIVOS_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

