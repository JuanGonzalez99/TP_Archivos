#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED


//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void mostrarPrecios()
{
    if(!existeArchivo(PRECIOS))
    {
        creaArchivo(PRECIOS);
        tPrecios aux;
        aux.diseniadores = 300;
        aux.desarrolladores = 350;
        aux.analistas = 400;
        guardarPrecios(aux);
    }
    tPrecios precios = leerPrecios();
    sys::cls();
    cout << "#============================================================================#" << endl;
    cout << "|                   PRECIO POR HORA SEGUN TIPO DE EMPLEADO                   |" << endl;
    cout << "#============================================================================#" << endl;
    cout << endl;
    cout << "Diseñadores: " << precios.diseniadores << endl;
    cout << "Desarrolladores: " << precios.desarrolladores << endl;
    cout << "Analistas: " << precios.analistas << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    pedirEnter("\n\nPresione enter para volver ");
}

#endif // SUBMENU_H_INCLUDED
