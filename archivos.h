#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <cstdio>
using namespace std;

//verifica si existe el Archivo
bool existeArchivo(const char *URL){

    bool existe = false;
    FILE *archivo;
    archivo = fopen(URL,"rb");
    if(archivo!=NULL){
        fclose(archivo);
        existe = true;
    }
    return existe;
}

//crea Archivo
bool creaArchivo(const char *URL){

    bool estado = false;
    FILE *archivo;
    archivo = fopen(URL,"wb");
    if(archivo!=NULL){
        fclose(archivo);
        estado = true;
    }

    return estado;


}

//Resguardo de datos de los usuarios.
template <typename T>
bool escribirArchivo(T *datos, const char *URL){

    bool error = true;
    FILE *archivo;
    archivo = fopen(URL,"rb");
    if(archivo!=NULL){

        fwrite(datos,sizeof(T),1,archivo);
        fclose(archivo);
        error = false;

    }
    return error;



}

//Lectura de datos de los usuarios.
template <typename T>
bool leerArchivo(T *datos, const char *URL){

    bool error = true;
    FILE *archivo;
    archivo = fopen(URL,"rb");
    if(archivo!=NULL){

        f(datos,sizeof(T),1,archivo);
        fclose(archivo);
        error = false;

    }
    return error;



}




#endif // ARCHIVOS_H_INCLUDED
