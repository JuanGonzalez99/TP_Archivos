#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "archivos.h"

using namespace std;


void iNtro(){
    cout<<"Hola"<<endl;
}

void sAlida(){
    cout<<"Chau"<<endl;
}

void mEnu(){

    bool salir = false;
    char op[2];

    cout<<"Ingresate una opción del Menu: "<<endl;
    sys::getline(op,2);
    while(!salir){
        switch(op[0]){



        }



    }



}


#endif // MENU_H_INCLUDED
