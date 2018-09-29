////#############################################################################
// ARCHIVO              : menu.h
// AUTORES              : Juan Gonzalez, Javier Pereyra.
// FECHA DE CREACION    : 30/08/2018.
// ULTIMA ACTUALIZACION : 29/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Linux (Ubuntu) / Windows 10.
// IDE                  : Code::Blocks - 16.01 / 17.12
// COMPILADOR           : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//*****************************************************************************
//                             INCLUSIONES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "archivos.h" // Libreria con funciones de archivos
#include "auxiliares.h" // Libreria de funciones auxiliares para validaciones
#include "submenu.h" // Libreria auxiliar

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void bienvenida(ninguno)
// ACCION : La siguiente funcion representa la bienvenida utilizando
//          Un conjunto de salidas.
// PARAMETROS: ninguno.
// DEVUELVE : nada --> esta funcion es void.
//-----------------------------------------------------------------------------
void bienvenida()
{
    cout   << "    Bienvenido a MAGIC SOFTWARE!" << endl << endl
		 <<	"                       ." << endl
		 <<	"            /^\\     ." << endl
		 <<	"       /\\   'V''" << endl
		 <<	"      /__\\   I      O  o" << endl
		 <<	"     //..\\\\  I     ." << endl
		 <<	"     \\].`[/  I" << endl
		 <<	"     /l\\/j\\  (]    .  O" << endl
		 <<	"    /. ~~ ,\\/I          ." << endl
		 <<	"    \\\\L__j^\\/I       o" << endl
		 <<	"     \\/--v}  I     o   ." << endl
		 <<	"     |    |  I   _________" << endl
		 <<	"     |    |  I c(`      ')o" << endl
		 <<	"     |    l  I   \\.    ,/      -Row" << endl
		 <<	"   _/j  L l\\_!  _//^---^\\_" << endl
		 <<	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    pedirEnter("\n\nPresione enter ");
}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void despedida(ninguno)
// ACCION : La siguiente funcion representa una despedida utilizando
//          Un conjunto de salidas.
// PARAMETROS: ninguno.
// DEVUELVE : nada --> esta funcion es void.
//-----------------------------------------------------------------------------
void despedida()
{
    sys::cls();
    cout   << " Hasta Luego y muchas gracias por usar nuestro software!!!" << endl << endl
		 <<	"         .                      ." << endl
		 <<	"         .                      ;" << endl
		 <<	"         :                  - --+- -" << endl
		 <<	"         !           .          !" << endl
		 <<	"         |        .             ." << endl
		 <<	"         |_         +" << endl
		 <<	"      ,  | `." << endl
		 <<	"--- --+-<#>-+- ---  --  -" << endl
		 <<	"      `._|_,'" << endl
		 <<	"         T" << endl
		 <<	"         |" << endl
		 <<	"         !" << endl
		 <<	"         :         . : " << endl
		 <<	"         .       *" << endl
		 <<	"Desarrolladores: Juan Gonzalez y Javier Pereyra" << endl;
    pedirEnter("\n\nPresione enter ");
}

void menuPrecio();
void menuFreelancers();
void menuReportes();
void menuAyuda();

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void menuPrincipal(ninguno)
// ACCION : La siguiente funcion representa un menu utilizando
//          Un conjunto de salidas validando el ingreso de las mismas.
// PARAMETROS: ninguno.
// DEVUELVE : nada --> esta funcion es void.
//-----------------------------------------------------------------------------
void menuPrincipal()
{
    bool salir = false;
    while(!salir)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                               MENU PRINCIPAL                               |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.        Precio por hora                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.          Freelancers                               |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Reportes                                |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.             Ayuda                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      s.             Salir                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("1234Ss");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                menuPrecio();
            }break;
            case '2':
            {
                menuFreelancers();
            }break;
            case '3':
            {
                menuReportes();
            }break;
            case '4':
            {
                menuAyuda();
            }break;
            case 'S':
            case 's':
            {
                if(confirmar())
                    return;
            }break;
        }//Fin switch

    }//Fin while

}

//=============================================================================
// FUNCION : void menuPrecio(Ninguno)
// ACCION : Representa un menu de opciones para el Precio por hora utilizando una
//          salida por consola.
// PARAMETROS: ninguno.
// DEVUELVE : void --> ninguno ya que es una funcion void.
//-----------------------------------------------------------------------------
void menuPrecio()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                               PRECIO POR HORA                              |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.    Mostrar precio por hora                         |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.  Configurar precio por hora                        |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                mostrarPrecios();
            }break;
            case '2':
            {
                menuConfigPrecios();
            }break;
            case '3':
            {
                return;
            }break;
        }//Fin switch

    }//Fin while
}

//=============================================================================
// FUNCION : void menuFreelancers(Ninguno)
// ACCION : Representa un menu de opciones para freelances utilizando una
//          salida por consola validando el ingreso de opciones.
// PARAMETROS: ninguno.
// DEVUELVE : void --> ninguno ya que es una funcion void.
//-----------------------------------------------------------------------------
void menuFreelancers()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                 FREELANCES                                 |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.      Agregar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.       Buscar freelance                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.     Modificar freelance                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      4.    Carga de horas por DNI                          |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      5.    Carga de horas general                          |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      6.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123456");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                menuAgregar();
            }break;
            case '2':
            {
                menuBusqueda();
            }break;
            case '3':
            {
                menuModificarFreelance();
            }break;
            case '4':
            {
                menuCargaDNI();
            }break;
            case '5':
            {
                menuCargaGral();
            }break;
            case '6':
            {
                return;
            }break;
        }//Fin switch


    }//Fin while

}

//=============================================================================
// FUNCION : void menuReportes(Ninguno)
// ACCION : Representa un menu de opciones para los reportes utilizando una
//          salida por consola validando el ingreso de opciones.
// PARAMETROS: ninguno.
// DEVUELVE : void --> ninguno ya que es una funcion void.
//-----------------------------------------------------------------------------
void menuReportes()
{
    bool volver = false;
    while(!volver)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                                  REPORTES                                  |" << endl;
        cout << "#============================================================================#" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      1.     Horas trabajadas por                           |" << endl;
        cout << "|                               tipo de freelance                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      2.        Reporte general                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                      3.            Volver                                  |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+----------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";

        char op = validarOpcion("123");

        sys::cls();
        switch(op)
        {
            case '1':
            {
                reportePorTipo();
            }break;
            case '2':
            {
                reporteGeneral();
            }break;
            case '3':
            {
                return;
            }break;
        }//Fin switch


    }//Fin while
}


//=============================================================================
// FUNCION : void menuAyuda(Ninguno)
// ACCION : Representa un menu de ayuda para el usuario utilizando salidas
//          por consola.
// PARAMETROS: ninguno.
// DEVUELVE : void --> ninguno ya que es una funcion void.
//-----------------------------------------------------------------------------
void menuAyuda()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|              BIENVENIDO AL  MENU DE AYUDA / Magic Software                 |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#                               MENU PRINCIPAL                               #" << endl;
    cout << "#----------------------------------------------------------------------------#" << endl;
    cout << "# El menu principal se compone de 4 opciones                                 #" << endl;
    cout << "# 1.Precio por hora: Esta opcion despliega las opciones que le permiten a    #" << endl;
    cout << "#                    usted ver (1) y configurar (2) los precios              #" << endl;
    cout << "#                    por hora de cada uno de los tipos de Freelances         #" << endl;
    cout << "#                    ( DISENADOR=1, DESARROLLADOR=2, ANALISTA=3 )            #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 2.Freelancers: Esta opcion despliega las opciones para                     #" << endl;
    cout << "#                'Agregar (1)','Buscar(2)','Modificar(3)' los diferentes     #" << endl;
    cout << "#                tipos de Freelance como asi tambien le permite  a usted     #" << endl;
    cout << "#                cargar la cantidad de horas por DNI (4) para cada uno de    #" << endl;
    cout << "#                los freelance. Tambien dispone de una opcion (5) para       #" << endl;
    cout << "#                cargar las horas trabajadas.                                #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 3.Reportes: Esta opcion le permite a usted ver la estadistica de horas     #" << endl;
    cout << "#             trabajadas por freelance (1) y ademas ver un reporte general   #" << endl;
    cout << "#             de todos los freelance cargados (2)                            #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 4.Ayuda: Ayuda general de la aplicacion                                    #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# s.Salir   :      Salir y Cerrar el software                                #" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#                              PRECIO POR HORA                               #" << endl;
    cout << "#----------------------------------------------------------------------------#" << endl;
    cout << "# 1.Mostrar precio por hora: Muestra el precio de cada tipo de Freelance.    #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 2.Configurar precio por hora: Ingresa el nuevo precio por hora de          #" << endl;
    cout << "#                               cada tipo de freelance                       #" << endl;
    cout << "#                               ( DISENADOR=1, DESARROLLADOR=2, ANALISTA=3 ) #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 3.Volver: volver al menu principal                        (presione enter) #"; pedirEnter();
    cout << "#============================================================================#" << endl;
    cout << "#                                 FREELANCES                                 #" << endl;
    cout << "#----------------------------------------------------------------------------#" << endl;
    cout << "# 1.Agregar freelance: Se agrega el Nombre,Apellido,Tipo de Freelance y DNI  #" << endl;
    cout << "#                      del nuevo freelance.                                  #" << endl;
    cout << "#                      ( ATENCION:POR FAVOR NO INGRESE UN DNI YA EXISTENTE ) #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 2.Buscar freelance: Busca el freelance ingresando el Nombre o Apellido     #" << endl;
    cout << "#                     Opcion 1: ayuda, Opcion 2: salir                       #" << endl;
    cout << "#                      ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )      #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 3.Modificar freelance: Ingrese el DNI y automaticamente usted podra        #" << endl;
    cout << "#                        cambiar los datos del mismo  ( Nombre, Apellido,    #" << endl;
    cout << "#                        y Tipo de Freelance )     .                         #" << endl;
    cout << "#                      ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )      #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 4.Carga de horas por DNI: Esta opcion le permite a usted ingresar las      #" << endl;
    cout << "#                           horas trabajadas del Freelance.                  #" << endl;
    cout << "#                      ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )      #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 5.Carga de horas general: Ingresa las horas trabajadas para cada uno       #" << endl;
    cout << "#                           de los Freelance                                 #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 6.Volver: Vuelve al menu principal.                       (presione enter) #"; pedirEnter();
    cout << "#============================================================================#" << endl;
    cout << "#                                  REPORTES                                  #" << endl;
    cout << "#----------------------------------------------------------------------------#" << endl;
    cout << "# 1.Horas trabajadas por tipo de freelance: Muestra el total de horas        #" << endl;
    cout << "#                                           trabajadas por cada uno de       #" << endl;
    cout << "#                                           los freelance                    #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 2.Reporte general: reporte general de todos los freelance                  #" << endl;
    cout << "#                                                                            #" << endl;
    cout << "# 3.Volver: Volver al menu principal.                                        #" << endl;
    cout << "#============================================================================#" << endl;
    pedirEnter("\n\nPresione enter para volver ");
}

#endif // MENU_H_INCLUDED

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

