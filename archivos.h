#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <cstdio>
using namespace std;

const

//lee Archivo
bool lArchivo(){

    bool estado = false;
    FILE *archivo;
    archivo = fopen(ARCHIVO,"rb");
    if(archivo!=NULL){
        fclose(archivo);
        estado = true;
    }
    return estado;
}

//crea Archivo
bool cArchivo(){

    bool estado = false;
    FILE *archivo;
    archivo = fopen(ARCHIVO,"wb");
    if(archivo!=NULL){
        fclose(archivo);
        estado = true;
    }

    return estado;


}

//Resguardo de datos de los usuarios.
bool sStruct(Empleado *datos){

    bool estado = false;
    FILE *archivo;
    archivo = fopen(ARCHIVO,"rb");



}





#endif // ARCHIVOS_H_INCLUDED
