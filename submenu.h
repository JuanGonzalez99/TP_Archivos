////#############################################################################
// ARCHIVO              : menu.h
// AUTOR                : Juan Gonzalez.
// FECHA DE CREACION    : 22/09/2018.
// ULTIMA ACTUALIZACION : 28/09/2018.
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
// DEVUELVE : nada --> no devuelve ningun valor.
//-----------------------------------------------------------------------------
void mostrarPrecios()
{
    verificarPrecios();
    tPrecios p = leerPrecios();
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                   PRECIO POR HORA SEGUN TIPO DE FREELANCE                  |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "|          Tipo de freelance          |              Valor hora              |" << endl;
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
// DEVUELVE : nada --> no devuelve ningun valor al ser funcion void.
//-----------------------------------------------------------------------------
void menuConfigPrecios()
{
    bool volver = false;

    while(!volver)
    {
        verificarPrecios();
        tPrecios p = leerPrecios();

        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                    CONFIGURACION DE LOS PRECIOS POR HORA                   |" << endl;
        cout << "#============================================================================#" << endl;
        cout << endl;
        cout << "Diseñadores (1): $" << p.diseniadores << endl;
        cout << "Desarrolladores (2): $" << p.desarrolladores << endl;
        cout << "Analistas (3): $" << p.analistas << endl;
        cout << endl;
        cout << "Ingrese un tipo de freelance o 'S' para salir: ";

        char op = validarOpcion("123Ss");

        switch(op)
        {
            case '1':
            {
                int n;
                cout << "Ingrese el nuevo precio por hora: ";
                cin >> n; cin.ignore();
                if(n < 100) cout << "Rata";
                p.diseniadores = n;
            }break;
            case '2':
            {
                int n;
                cout << "Ingrese el nuevo precio por hora: ";
                cin >> n; cin.ignore();
                if(n < 100) cout << "Rata";
                p.desarrolladores = n;
            }break;
            case '3':
            {
                int n;
                cout << "Ingrese el nuevo precio por hora: ";
                cin >> n; cin.ignore();
                if(n < 100) cout << "Rata";
                p.analistas = n;
            }break;
            case 'S':
            case 's':
            {
                return;
            }
        }//Fin switch

        guardarPrecios(p);

    }//Fin while
}

//=============================================================================
// FUNCION : Freelance leerFreelance()
// ACCION : Captura y devuelve un nuevo freelance
// PARAMETROS: -.
// DEVUELVE : Freelance, nuevo --> devuelve una estructura freelance para luego
//            ser resguardada.
//-----------------------------------------------------------------------------
Freelance leerFreelance(bool esNuevo=true)
{
    Freelance nuevo;
    cout << "Nombre: ";
    validarNombre(nuevo.nombre, 30, "Ingrese un nombre de no mas de 30 caracteres: ", "Por favor, solo ingrese letras: ");
    firstUpper(nuevo.nombre);
    cout << "Apellido: ";
    validarNombre(nuevo.apellido, 30, "Ingrese un apellido de no mas de 30 caracteres: ", "Por favor, solo ingrese letras: ");
    firstUpper(nuevo.apellido);
    cout << "Tipo de freelance (DISEÑADOR=1, DESARROLLADOR=2, ANALISTA=3): ";
    nuevo.tipo = (int)validarOpcion("123", "Ingrese una de las opciones mostradas: ")-49;
    if(esNuevo)
    {
        cout << "DNI: ";
        nuevo.DNI = validarDNI();
        nuevo.horas = 0;
    }
    return nuevo;
}

//=============================================================================
// FUNCION : void mostrarFreelance(Freelance f, int modo=0)
// ACCION : muestra los datos de los freelance.
// PARAMETROS: Freelance f -> representa la estructura freelance la cual luego
//                            se utiliza para mostrar la informacion de la misma.
//             int modo ->
// DEVUELVE : void --> nada, debido a que es una funcion void.
//-----------------------------------------------------------------------------
void mostrarFreelance(Freelance f, int modo=0)
{
    if(modo == 0)
    {
        cout << "Nombre             : " << f.nombre << endl;
        cout << "Apellido           : " << f.apellido << endl;
        cout << "DNI                : " << f.DNI << endl;
        cout << "Tipo de freelance  : "; if(f.tipo == DISENIADOR) cout << "Diseñador"; else if(f.tipo == DESARROLLADOR) cout << "Desarrollador"; else cout << "Analista"; cout << endl;
        cout << "Horas              : " << f.horas << endl;
        cout << endl;
    }
    else
    {
        verificarPrecios();
        tPrecios p = leerPrecios();
        int sueldo;
        if(f.tipo == DISENIADOR) sueldo = f.horas*p.diseniadores;
        if(f.tipo == DESARROLLADOR) sueldo = f.horas*p.desarrolladores;
        if(f.tipo == ANALISTA) sueldo = f.horas*p.analistas;

        if(modo == 1)
        {
            char n[14]; if(strlen(f.nombre)>13) cortarEn(13, f.nombre, n); else strcpy(n, f.nombre);
            char a[15]; if(strlen(f.apellido)>14) cortarEn(14, f.apellido, a); else strcpy(a, f.apellido);

            cout << "|" << f.DNI; llenarEspacio(10-intlen(f.DNI)); cout << "|" << n; llenarEspacio(14-strlen(n));
            cout << "|" << a; llenarEspacio(15-strlen(a)); cout << "|";
            if(f.tipo == 0) cout << "Diseñador"; if(f.tipo == 1) cout << "Desarrollador"; if(f.tipo == 2) cout << "Analista";
            cout << "|" << f.horas; llenarEspacio(9-intlen(f.horas)); cout << "|" << sueldo; llenarEspacio(12-intlen(sueldo));
            cout << "|" << endl;
        }
        else
        {
            char n[16]; if(strlen(f.nombre)>15) cortarEn(15, f.nombre, n); else strcpy(n, f.nombre);
            char a[16]; if(strlen(f.apellido)>15) cortarEn(15, f.apellido, a); else strcpy(a, f.apellido);

            cout << "|" << f.DNI; llenarEspacio(14-intlen(f.DNI)); cout << "|" << n; llenarEspacio(15-strlen(n));
            cout << "|" << a; llenarEspacio(15-strlen(a)); cout << "|" << f.horas; llenarEspacio(13-intlen(f.horas));
            cout << "|" << sueldo; llenarEspacio(15-intlen(sueldo)); cout << "|" << endl;
        }
    }
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
        pedirEnter("\nPresione enter para volver ");
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
    sys::cls();
    cout << "#==============================================================================#" << endl;
    cout << "|                           BUSQUEDA DE FREELANCES (ni a alfa llega)           |" << endl;
    cout << "#==============================================================================#" << endl;
    cout << endl;
//    cout << "¿A quien desea buscar? ('h' para ayuda): ";

//    char busqueda[30];
//    validarNombre(busqueda, 30, "", "");
//
//    verificarFreelances();
//    Freelance *freelances = (Freelance*)malloc(cantRegistros()*sizeof(Freelance));
//    if(freelances == NULL)
//    {
//        cout << "Usted no dispone de la memoria suficiente para realizar esta operacion" << endl;
//        pedirEnter("\nPresione enter para volver ");
//        return;
//    }

    cout << "Ingrese el DNI a buscar: ";
    int dni = validarDNI();
    cout << endl << endl;
    verificarFreelances();
    if(!existeFreelance(dni))
    {
        cout << "Freelance inexistente" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }
    mostrarFreelance(buscarFreelanceDNI(dni));

//    free(freelances);
    pedirEnter("\n\n(Presione enter para volver) ");
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuModificarFreelance()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                       MODIFICAR DATOS DE FREELANCE                         |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Ingrese el DNI a buscar: ";

    long long DNI = validarDNI();

    cout << endl;

    verificarFreelances();
    if(!existeFreelance(DNI))
    {
        cout << "Freelance inexistente" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }
    mostrarFreelance(buscarFreelanceDNI(DNI));
    cout << endl;
    Freelance aux = leerFreelance(false);
    aux.DNI = DNI; aux.horas = buscarFreelanceDNI(DNI).horas;
    modificarFreelance(aux);

    pedirEnter("\n\n(Presione enter para volver) ");

}

//=============================================================================
// FUNCION : void menuCargaDNI()
// ACCION : carga al freelance por DNI.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void menuCargaDNI()
{
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                               CARGA POR DNI                                |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Ingrese el DNI: ";

    long long DNI = validarDNI();

    verificarFreelances();

    if(!existeFreelance(DNI))
    {
        cout << "Freelance inexistente" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }

    Freelance buscado = buscarFreelanceDNI(DNI);
    mostrarFreelance(buscado);

    cout << "Ingrese las horas trabajadas: ";

    int horas = validarHoras();

    verificarFreelances();

    buscado.horas = horas;
    modificarFreelance(buscado);

    cout << endl;
    if(buscarFreelanceDNI(buscado.DNI).horas == horas)
    {
        cout << "Horas cargadas correctamente" << endl;
    }
    else
    {
        cout << "Ha ocurrido un error, intente nuevamente o pongase en contacto" << endl;
        cout << "con el soporte de la aplicacion" << endl;
    }
    pedirEnter("\n(Presione enter para volver) ");
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
    verificarFreelances();
    Freelance *freelances = (Freelance*)malloc(cantRegistros()*sizeof(Freelance));
    if(freelances == NULL)
    {
        cout << "Usted no dispone de la memoria suficiente para realizar esta operacion" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }
    llenarFreelances(freelances);

    for(int x=0; x<cantRegistros(); x++)
    {
        sys::cls();
        cout << "#============================================================================#" << endl;
        cout << "|                               CARGA GENERAL                                |" << endl;
        cout << "#============================================================================#" << endl;
        cout << endl;
        mostrarFreelance(freelances[x]);
        cout << "Ingrese las horas trabajadas: ";
        freelances[x].horas = validarHoras();
        modificarFreelance(freelances[x]);
    }
    sys::cls();
    free(freelances);
    pedirEnter("Presione enter para volver ");
}

//=============================================================================
// FUNCION : void reportePorTipo()
// ACCION : Reporte de horas trabajadas por tipo de freelance con sus totales.
// PARAMETROS: -.
// DEVUELVE : void --> ninguno, es una funcion de tipo void.
//-----------------------------------------------------------------------------
void reportePorTipo()
{
    verificarFreelances();
    Freelance *freelances = (Freelance*)malloc(cantRegistros()*sizeof(Freelance));
    if(freelances == NULL)
    {
        cout << "Usted no dispone de la memoria suficiente para realizar esta operacion" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }
    llenarFreelances(freelances);

    verificarPrecios();
    tPrecios p = leerPrecios();

    int horasDis=0, horasDes=0, horasAn=0;

    for(int x=0; x<cantRegistros(); x++)
    {
        switch(freelances[x].tipo)
        {
        case DISENIADOR: horasDis += freelances[x].horas; break;
        case DESARROLLADOR: horasDes += freelances[x].horas; break;
        case ANALISTA: horasAn += freelances[x].horas; break;
        }
    }

    free(freelances);

    int sueldoDis=horasDis*p.diseniadores, sueldoDes=horasDes*p.desarrolladores, sueldoAn=horasAn*p.analistas;
    int totHoras=horasAn+horasDes+horasDis, totSueldo=sueldoAn+sueldoDes+sueldoDis;

    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                        REPORTE POR TIPO DE FREELANCE                       |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "|          Tipo           |    Horas trabajadas    |      Sueldo a pagar     |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "|    Diseñadores          |";llenarEspacio(24-intlen(horasDis));cout<<horasDis<<"|";llenarEspacio(24-intlen(sueldoDis));cout<<"$"<<sueldoDis<<"|"<<endl;
    cout << "|    Desarrolladores      |";llenarEspacio(24-intlen(horasDes));cout<<horasDes<<"|";llenarEspacio(24-intlen(sueldoDes));cout<<"$"<<sueldoDes<<"|"<<endl;
    cout << "|    Analistas            |";llenarEspacio(24-intlen(horasAn)); cout<<horasAn<<"|";llenarEspacio(24-intlen(sueldoAn)); cout<<"$"<<sueldoAn <<"|"<<endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "|         TOTALES         |";llenarEspacio(24-intlen(totHoras));cout<<totHoras<<"|";llenarEspacio(24-intlen(totSueldo));cout<<"$"<<totSueldo<<"|"<<endl;
    cout << "------------------------------------------------------------------------------" << endl;
    pedirEnter("\n\nPresione enter para volver ");
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

    Freelance *registros = (Freelance*)malloc(cantRegistros()*sizeof(Freelance));
    if(registros == NULL)
    {
        cout << "Usted no dispone de la memoria suficiente para realizar esta operacion" << endl;
        pedirEnter("\nPresione enter para volver ");
        return;
    }

    llenarFreelances(registros);

    verificarPrecios();
    tPrecios p = leerPrecios();

    long long horasDis = 0, horasDes = 0, horasAn = 0;
    long long sueDis = 0, sueDes = 0, sueAn = 0;

    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                              REPORTE GENERAL                               |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "|      DNI     |    Nombre     |   Apellido    |    Horas    |     Sueldo    |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "|                                DISEÑADORES                                 |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    for(int x=0; x<cantRegistros(); x++)
    {
        if(registros[x].tipo == DISENIADOR)
        {
            mostrarFreelance(registros[x], 2);
            horasDis += registros[x].horas;
            sueDis += registros[x].horas * p.diseniadores;
        }
    }
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "                               |    Totales    |"<<horasDis;llenarEspacio(13-intlen(horasDis));cout<<"|"<<sueDis;llenarEspacio(15-intlen(sueDis));cout<<"|"<<endl;
    cout << "#============================================================================#" << endl;
    cout << "|                              DESARROLLADORES                               |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    for(int x=0; x<cantRegistros(); x++)
    {
        if(registros[x].tipo == DESARROLLADOR)
        {
            mostrarFreelance(registros[x], 2);
            horasDes += registros[x].horas;
            sueDes += registros[x].horas * p.desarrolladores;
        }
    }
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "                               |    Totales    |"<<horasDes;llenarEspacio(13-intlen(horasDes));cout<<"|"<<sueDes;llenarEspacio(15-intlen(sueDes));cout<<"|"<<endl;
    cout << "#============================================================================#" << endl;
    cout << "|                                 ANALISTAS                                  |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    for(int x=0; x<cantRegistros(); x++)
    {
        if(registros[x].tipo == ANALISTA)
        {
            mostrarFreelance(registros[x], 2);
            horasAn += registros[x].horas;
            sueAn += registros[x].horas * p.analistas;
        }
    }
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "                               |    Totales    |"<<horasAn;llenarEspacio(13-intlen(horasAn));cout<<"|"<<sueAn;llenarEspacio(15-intlen(sueAn));cout<<"|"<<endl;
    cout << "------------------------------------------------------------------------------" << endl;

    free(registros);
    pedirEnter("\nPresione enter para volver ");
}

void ayuda()
{

    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|           BIENVENIDO AL  MENU DE AYUDA / Software Magic                    |" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#===========    AYUDA:   MENU PRINCIPAL                         =============#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#=El menu principal se compone de 4 opciones                                =#" << endl;
    cout << "#=1.Precio por hora: Esta opcion despliega las opciones que le permiten a   =#" << endl;
    cout << "#=                   usted ver (1) y configurar (2) los precios             =#" << endl;
    cout << "#=                   por hora de cada uno de los tipos de Freelances        =#" << endl;
    cout << "#=                   ( DISENADOR=1, DESARROLLADOR=2, ANALISTA=3 )           =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=2.Freelancers: Esta opcion despliega las opciones para                    =#" << endl;
    cout << "#=               'Agregar (1)','Buscar(2)','Modificar(3)' los diferentes    =#" << endl;
    cout << "#=               tipos de Freelance como asi tambien le permite  a usted    =#" << endl;
    cout << "#=               cargar la cantidad de horas por DNI (4) para cada uno de   =#" << endl;
    cout << "#=               los freelance. Tambien dispone de una opcion (5) para      =#" << endl;
    cout << "#=               cargar las horas trabajadas.                               =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=3.Reportes: Esta opcion le permite a usted ver la estadistica de horas    =#" << endl;
    cout << "#=            trabajadas por freelance (1) y ademas ver un reporte general  =#" << endl;
    cout << "#=            de todos los freelance cargados (2)                           =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=s.Salir   :      Salir y Cerrar el software                               =#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#========= AYUDA:   PRECIO POR HORA ( 1° submenu/Precio por hora )===========#" << endl;
    cout << "#=1.Mostrar precio por hora: Muestra el precio de cada tipo de Freelance.   =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=2.Configurar precio por hora: Ingresa el nuevo precio por hora de         =#" << endl;
    cout << "#=                              cada tipo de freelance                      =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=3.Volver: volver al menu principal                                        =#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#==========  AYUDA:    Freelancers  ( 2° submenu/Freelancers )  =============#" << endl;
    cout << "#=1.Agregar freelance: Se agrega el Nombre,Apellido,Tipo de Freelance y DNI =#" << endl;
    cout << "#=                     del nuevo freelance.                                 =#" << endl;
    cout << "#=                     ( ATENCION:POR FAVOR NO INGRESE UN DNI YA EXISTENTE )=#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=2.Buscar freelance: Busca el freelance ingresando el numero               =#" << endl;
    cout << "#=                    de DNI del mismo                                      =#" << endl;
    cout << "#=                     ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )     =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=3.Modificar freelance: Ingrese el DNI y automaticamente usted podra       =#" << endl;
    cout << "#=                       cambiar los datos del mismo  ( Nombre, Apellido,   =#" << endl;
    cout << "#=                       y Tipo de Freelance )     .                        =#" << endl;
    cout << "#=                     ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )     =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=4.Carga de horas por DNI: Esta opcion le permite a usted ingresar las     =#" << endl;
    cout << "#=                          horas trabajadas del Freelance.                 =#" << endl;
    cout << "#=                     ( ATENCION:INGRESAR UN DNI PREVIAMENTE CARGADO )     =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=5.Carga de horas general: Ingresa las horas trabajadas para cada uno      =#" << endl;
    cout << "#=                          de los Freelance                                =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=6.Volver: Vuelve al menu principal.                                       =#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#===========   AYUDA:       Reportes ( 3° submenu )             =============#" << endl;
    cout << "#=1.Horas trabajadas por tipo de freelance: Muestra el total de horas       =#" << endl;
    cout << "                                            trabajadas por cada uno de      =#" << endl;
    cout << "                                            los freelance                   =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=2.Reporte general: reporte general de todos los freelance                 =#" << endl;
    cout << "#=                                                                          =#" << endl;
    cout << "#=3.Volver: Volver al menu principal.                                       =#" << endl;
    cout << "#============================================================================#" << endl;
    cout << "#============================================================================#" << endl;
    pedirEnter("\n\nPresione enter para volver ");


}

#endif // SUBMENU_H_INCLUDED
