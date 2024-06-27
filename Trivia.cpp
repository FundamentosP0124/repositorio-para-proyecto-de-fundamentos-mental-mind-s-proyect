#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void menu();
int cantidadJugadores(int);
int RandorizarPosicionArreglo(int);
int SelecionTemas(int);
void temas();

int main(void)
{
    menu();

    return 0;
}

void menu()
{

    int opcion;

    cout << endl;
    cout << "Presione enter para empezar";
    cin.get(); // En espera del enter para seguir

    cout << endl;
    cout << "////MENU////" << endl;
    /*Agregar el resto de opciones en el menu*/

    cout << "0? - TERMINAR JUEGO";

    switch (opcion)
    {
    case 4:
        exit(0);
        break;

    default:
        cout << "Opcion inexistente";
        break;
    }
}

int cantidadJugadores(int Cant) // Obtendremos la cantiad de jugadores con los que desean iniciar
{

   int Cant;
    char confirmacion;

    // Almacenar mensajes para evitar repetirlos
    string mensajeOne = "Ingrese la cantidad de jugadores que desean inscribirse.";
    string mensajeTwo = "¿Está seguro de que la cantidad de jugadores que desea inscribir sea: ";
    string mensajeThree = "Presione 's' para confirmar, 'n' para cambiar la cantidad de jugadores.";

    // Realizamos la confirmación
    while (true)
    {
        // Leemos la entrada
        cout << endl << mensajeOne << endl;
        cout << "- ";
        cin >> Cant;
        cout << endl;

        // Confirmamos la cantidad
        cout << mensajeTwo << Cant << "?" << endl;
        cout << mensajeThree << endl;
        cout << "- ";
        cin >> confirmacion;

        if (confirmacion == 's')
        {
            break; // Salir del bucle si la confirmación es 's'
        }
    }
}

// Esta funcion se debe repetir para cada arreglo de cada nivel y se utilizara para las preguntas de todos los temas

int RandorizarPosicionArreglo(int PosicionRan) // Vamos a randorizar la poscion del arreglo para las preguntas
{
    int arre[0];

    srand(time(0));

    int posicionAletoria = rand() % 5;

    // Le regresamos el valor a la funcion para ser utilizada mas adelante
    PosicionRan = posicionAletoria;
}

int SelecionTemas(int temaSeleccionado) // Seleccionar los temas que los jugadores desean jugar
{

    char confirmacion;

    string mensajeOne = "Selecccione los temas con los que desean jugar.";
    string mensajeTwo = "Recuerden que el tema seleccionado aplicara para todas las preguntas a todo los jugadores.";
    string mensajeThree = "¿Esta seguro de la cantidad de jugadores que desea inscribir sean?: ";
    string mensajeFoor = "Presione 's' para confirmar";
    string mensajeFive = "Presione 'n' para cambiar la cantidad de jugadores";

    cout << mensajeOne << endl;
    cout << mensajeTwo << endl;
    temas();

    cout << "- ";
    cin >> temaSeleccionado;

    // Realizamos la confirmacion

    while (true)
    {
        if (confirmacion == 'n')
        {
            cout << mensajeOne << endl;
            cout << "- ";
            cin >> temaSeleccionado;
            continue;
        }
        break;
    }
}

void temas()
{
    string arre[4] = {"TEMA 1", "TEMA 2", "TEMA 3", "TEMA 4"};

    cout << "    TEMAS   ";

    for (int i = 0; i < 4; i++)
    {
        cout << arre[i] << endl;
    }
}

int ExtraerPuntuacion() // Sistema principal para extraer los puntos obtenidos por los jugadores
{
}

int ModalidadJuego(int Opcion) //Selecciona de la modalidad del juego 
{

    
    string mensajeOne = "Seleccione con modalidad desean jugar.";
    string mensajeTwoo = "Seleccione con que modalidad desea jugar.";

    int Cantiad;

    cantidadJugadores(Cantiad);

    if (Cantiad == 1)
    {
        cout << mensajeOne << endl;
    }else
    {
        cout << mensajeTwoo << endl;
    }

    cout << "Las modalidades disposnibles son:" << endl;
    cout << " 1 - HASTA FINALIZAR" << endl;
    cout << " 2 - CON LIMITES DE DERROTAS (3) MAXIMO" << endl;

    cin >> Opcion;

}