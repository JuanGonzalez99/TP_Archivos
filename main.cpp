//#############################################################################
// ARCHIVO              : main.cpp
// AUTORES              : Juan Gonzalez, Javier Pereyra.
// VERSION              : 0.01 beta.
// FECHA DE CREACION    : 30/08/2018.
// ULTIMA ACTUALIZACION : 25/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Windows 10, Linux (Ubuntu 16.04).
// IDE                 : Code::Blocks - 17.12 / 16.01.
// COMPILADOR          : MinGW (Windows), GNU GCC Compiler (Linux).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
#ifndef _WIN32
    # define _LINUX
#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

using namespace std; // Namespace de cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().


//*****************************************************************************
//                             DECLARACIONES GLOBALES
//=============================================================================
//Constantes para las direcciones de los archivos
const char PRECIOS [] = "./precios.dat";
const char FREELANCES [] = "./freelances.dat";

//Constantes para los tipos de empleados
const int DISENIADOR = 0, DESARROLLADOR = 1, ANALISTA = 2;

//Estructura para el resguardo de los precios
struct tPrecios
{
    int diseniadores;
    int desarrolladores;
    int analistas;
};

//Estructura generica para los freelancers
struct Freelance
{
    long long DNI;
    char nombre[30 + 1];
    char apellido[30 + 1];
    int horas;
    int tipo;
};

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "menu.h" // Libreria de menu.


//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main()
{
    bienvenida();
    menuPrincipal();
    despedida();
    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

