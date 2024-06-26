#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*Juego de trivia de preguntas al azar con 3 niveles de dificultad y un maximo de 3 equivocaciones
de acuerdo a la modalidad seleccionada del juego sin es por limites de inaciertos puntuacion final
segun si es el modo multijugador o de manera individual*/

void menu();

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

    char confirmacion;

    // Almacenar mensajes para evitar repetirlos

    string mensajeOne = "Ingrese la cantidad de jugadores que desean inscribirse.";
    string mensajeTwo = "¿Esta seguro de la cantidad de jugadores que desea inscribir sean?: ";
    string mensajeThree = "Presione 's' para confirmar";
    string mensajeFoor = "Presione 'n' para cambiar la cantidad de jugadores";

    // Leemos la entrada

    cout << endl;
    cout << mensajeOne << endl;
    cout << "- ";
    cin >> Cant;
    cout << endl;

    cout << mensajeTwo;
    cin >> confirmacion;

    // Realizamos la confirmacion

    while (true)
    {
        if (confirmacion == 'n')
        {
            cout << mensajeOne << endl;
            cout << "- ";
            cin >> Cant;
            continue;
        }
        break;
    }
}

int RandorizarPosicionArreglo(int PosicionRan) // Vamos a randorizar la poscion del arreglo para las preguntas
{
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

    cout << "- ";
    cin >> temaSeleccionado;

    // Realizamos la confirmacion

    while (true)
    {
        if (confirmacion == 'n')
        {
            cout << mensajeOne << endl;
            cout << "- ";
            // cin >> ;
            continue;
        }
        break;
    }
}

