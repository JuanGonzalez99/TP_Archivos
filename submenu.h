////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 22/09/2018.
// ULTIMA ACTUALIZACION : 26/09/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO    : Windows 10.
// IDE                  : Code::Blocks - 17.12
// COMPILADOR           : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// aquí va una descripción general de la libreria
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void verificarPrecios()
// ACCION : valida la existencia del archivo y  en casi de que no sea así
// automaticamente genera un nuevo archivo preasignado valores.
// PARAMETROS: -.
// DEVUELVE : void --> no devuelve ningun valor al ser void.
//-----------------------------------------------------------------------------
void verificarPrecios()
{
    if(!existeArchivo(PRECIOS))
    {
        tPrecios aux;
        aux.diseniadores = 300;
        aux.desarrolladores = 350;
        aux.analistas = 400;
        guardarPrecios(aux);
    }
}

//=============================================================================
// FUNCION : void mostrarPrecios()
// ACCION : verifica precios, genera una estructura p y lee y
// asigna los valores a esta estructura.
// PARAMETROS: -.
// DEVUELVE : void --> no devuelve ningun valor.
//-----------------------------------------------------------------------------
void mostrarPrecios()
{
    verificarPrecios();
    tPrecios p = leerPrecios();
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                   PRECIO POR HORA SEGUN TIPO DE FREELANCE                  |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "|          Tipo de freelance          |                 $$$                  |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "|             Diseñadores             |  $" << p.diseniadores; llenarEspacio(35-intlen(p.diseniadores)); cout << "|" << endl;
    cout << "|           Desarrolladores           |  $" << p.desarrolladores; llenarEspacio(35-intlen(p.desarrolladores)); cout << "|" << endl;
    cout << "|              Analistas              |  $" << p.analistas; llenarEspacio(35-intlen(p.analistas)); cout << "|" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    pedirEnter("\n\nPresione enter para volver ");
}

//=============================================================================
// FUNCION : void menuConfigPrecios(ninguno)
// ACCION : Se Ingresan los precios por hora para cada
// uno de los tipos de Freelance.
// PARAMETROS: -.
// DEVUELVE : void --> no devuelve ningun valor al ser funcion void.
//-----------------------------------------------------------------------------
void menuConfigPrecios()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                    CONFIGURACION DE LOS PRECIOS POR HORA                   |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    pedirEnter("\n\n\nEnter ");
}

//=============================================================================
// FUNCION : Freelance leerFreelance()
// ACCION : Captura y devuelve un nuevo freelance
// PARAMETROS: -.
// DEVUELVE : Freelance, nuevo --> devuelve una estructura freelance para luego
// ser resguardada.
//-----------------------------------------------------------------------------
Freelance leerFreelance()
{
    Freelance nuevo;
    cout << "Nombre: ";
    sys::getline(nuevo.nombre, 30);
    cout << "Apellido: ";
    sys::getline(nuevo.apellido, 30);
    cout << "Tipo de freelance (DISEÑADOR=0, DESARROLLADOR=1, ANALISTA=2): ";
    cin >> nuevo.tipo;
    cout << "DNI: ";
    cin >> nuevo.DNI; cin.ignore();
    nuevo.horas = 0;
    return nuevo;
}

//=============================================================================
// FUNCION : void mostrarFreelance(Freelance f)
// ACCION : muestra los datos de los freelance.
// PARAMETROS: Freelance f -> representa la estructura freelance la cual luego
//             se utiliza para mostrar la informacion de la misma.
// DEVUELVE : void --> nada, debido a que es una funcion void.
//-----------------------------------------------------------------------------
void mostrarFreelance(Freelance f)
{
    cout << "Nombre             : " << f.nombre << endl;
    cout << "Apellido           : " << f.apellido << endl;
    cout << "DNI                : " << f.DNI << endl;
    cout << "Tipo de freelance  : "; if(f.tipo == DISENIADOR) cout << "Diseñador"; else if(f.tipo == DESARROLLADOR) cout << "Desarrollador"; else cout << "Analista"; cout << endl;
    cout << "Horas              : " << f.horas << endl;
    cout << endl;
}

//=============================================================================
// FUNCION : void verificarFreelances()
// ACCION : valida si el archivo freelance existe y de no ser asi automaticamente
// asigna valores pre-definidos para este Trabajo Practico.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void verificarFreelances()
{
    if(!existeArchivo(FREELANCES))
    {
        Freelance _1; _1.DNI=36938292; strcpy(_1.nombre, "Pedro"); strcpy(_1.apellido, "Vega"); _1.horas=35; _1.tipo=DISENIADOR; guardarFreelance(_1);
        Freelance _2; _2.DNI=32119232; strcpy(_2.nombre, "Pablo"); strcpy(_2.apellido, "Sardulex"); _2.horas=28; _2.tipo=DISENIADOR; guardarFreelance(_2);
        Freelance _3; _3.DNI=33213333; strcpy(_3.nombre, "Marta"); strcpy(_3.apellido, "Martulo"); _3.horas=100; _3.tipo=DISENIADOR; guardarFreelance(_3);
        Freelance _4; _4.DNI=39222823; strcpy(_4.nombre, "Miguel"); strcpy(_4.apellido, "Andaro"); _4.horas=33; _4.tipo=DISENIADOR; guardarFreelance(_4);
        Freelance _5; _5.DNI=34232999; strcpy(_5.nombre, "Jesus"); strcpy(_5.apellido, "Aragon"); _5.horas=130; _5.tipo=DESARROLLADOR; guardarFreelance(_5);
        Freelance _6; _6.DNI=35098098; strcpy(_6.nombre, "Natanel"); strcpy(_6.apellido, "Semilla"); _6.horas=22; _6.tipo=DESARROLLADOR; guardarFreelance(_6);
        Freelance _7; _7.DNI=92003990; strcpy(_7.nombre, "Orlando"); strcpy(_7.apellido, "Satur"); _7.horas=57; _7.tipo=DESARROLLADOR; guardarFreelance(_7);
        Freelance _8; _8.DNI=93003998; strcpy(_8.nombre, "Matias"); strcpy(_8.apellido, "Latero"); _8.horas=80; _8.tipo=DESARROLLADOR; guardarFreelance(_8);
        Freelance _9; _9.DNI=27203199; strcpy(_9.nombre, "Ramiro"); strcpy(_9.apellido, "Simero"); _9.horas=33; _9.tipo=ANALISTA; guardarFreelance(_9);
        Freelance _10; _10.DNI=28391955; strcpy(_10.nombre, "Santiago"); strcpy(_10.apellido, "Sasa"); _10.horas=39; _10.tipo=ANALISTA; guardarFreelance(_10);
        Freelance _11; _11.DNI=33058999; strcpy(_11.nombre, "Gonzalo"); strcpy(_11.apellido, "Reibon"); _11.horas=28; _11.tipo=ANALISTA; guardarFreelance(_11);
        Freelance _12; _12.DNI=32252495; strcpy(_12.nombre, "Rodrigo"); strcpy(_12.apellido, "Latete"); _12.horas=10; _12.tipo=ANALISTA; guardarFreelance(_12);
    }
}

//=============================================================================
// FUNCION : void menuAgregar()
// ACCION : verifica los frealances, y luego ingresa nuevos
// validando que los mismos ya no existan actualmente en el archivo.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void menuAgregar()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                              AGREGAR FREELANCE                             |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    Freelance nuevo = leerFreelance();

    verificarFreelances();

    if(existeFreelance(nuevo.DNI))
    {
        cout << "DNI ya existente" << endl;
        pedirEnter("Enter ");
        return;
    }
    guardarFreelance(nuevo);
    if(existeFreelance(nuevo.DNI))
    {
        cout << "Freelance agregado correctamente" << endl;
    }
    else
    {
        cout << "Ha ocurrido un error, intente nuevamente o pongase en contacto" << endl;
        cout << "con el soporte de la aplicacion" << endl;
    }
    pedirEnter("\n\n(Presione enter para volver) ");
}

//=============================================================================
// FUNCION : void menuBusqueda()
// ACCION : busca al freelance por DNI.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void menuBusqueda()
{
    int dni;

    sys::cls();
    cout << "#==============================================================================#" << endl;
    cout << "|                           BUSQUEDA DE FREELANCES  por (DNI)                  |" << endl;
    cout << "#==============================================================================#" << endl;
    cout << endl;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dni; cin.ignore();
    cout << endl;

    verificarFreelances();

    if(!existeFreelance(dni))
    {
        cout << "Freelance inexistente" << endl;
        pedirEnter("Enter ");
        return;
    }
    mostrarFreelance(buscarFreelanceDNI(dni));
    pedirEnter("\n\n(Presione enter para volver) ");
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuCargaGral()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                               CARGA GENERAL                                |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    pedirEnter("\n\n\nEnter ");
}

//=============================================================================
// FUNCION : void menuCargaDNInada)
// ACCION : carga al freelance por DNI.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void menuCargaDNI()
{
    int dni;
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                               CARGA POR DNI                                |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Ingrese el DNI: ";
    cin >> dni; cin.ignore();

    verificarFreelances();

    if(!existeFreelance(dni))
    {
        cout << "Freelance inexistente" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }
    Freelance buscado = buscarFreelanceDNI(dni);
    mostrarFreelance(buscado);
    pedirEnter("\n\nPresione enter para volver ");
}

//=============================================================================
// FUNCION : void reportePorTipo()
// ACCION : Reporte de Freelance por tipo.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void reportePorTipo()
{
    verificarFreelances();

    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                        REPORTE POR TIPO DE FREELANCE                       |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    pedirEnter("\n\n\nEnter ");

}

//=============================================================================
// FUNCION : void reporteGeneral()
// ACCION : muestra un reporte general de cada Freelancer.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void reporteGeneral()
{
    verificarFreelances();

    Freelance *registros = (Freelance*)malloc(cantRegistros(FREELANCES)*sizeof(Freelance));
    if(registros == NULL) exit(2);

    llenarFreelances(registros);

    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                              REPORTE GENERAL                               |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    for(int x=0; x<cantRegistros(FREELANCES); x++)
    {
        mostrarFreelance(registros[x]);
        pedirEnter();
    }
}

#endif // SUBMENU_H_INCLUDED
