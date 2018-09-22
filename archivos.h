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
void buscarEmpleado(char *cad, Empleado *vec)
{

    Empleado aux;
    int i = 0;
    FILE *p;
    p = fopen(EMPLEADOS,"rb");
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
void guardaFreelancers(Empleado reg)
{

    FILE *p;
    p = fopen(EMPLEADOS,"ab");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(&reg,sizeof(Empleado),1,p);
    fclose(p);


}


#endif // ARCHIVOS_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

