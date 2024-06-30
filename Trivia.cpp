#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

const int Num_Preguntas = 5;

void menu();
int cantidadJugadores(int);
int RandorizarPosicionArreglo(int);
int SelecionTemas(int);
void temas();
int ModalidadJuego(int);

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
    string mensajeTwo = "¿Está seguro de que la cantidad de jugadores que desea inscribir sea: ";
    string mensajeThree = "Presione 's' para confirmar, 'n' para cambiar la cantidad de jugadores.";

    // Realizamos la confirmación
    while (true)
    {
        // Leemos la entrada
        cout << endl
             << mensajeOne << endl;
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

    return Cant;
}

// Esta funcion se debe repetir para cada arreglo de cada nivel y se utilizara para las preguntas de todos los temas

int RandorizarPosicionArreglo(int PosicionRan) // Vamos a randorizar la poscion del arreglo para las preguntas
{
    int arre[0];

    srand(time(0));

    int posicionAletoria = rand() % 5;

    // Le regresamos el valor a la funcion para ser utilizada mas adelante
    PosicionRan = posicionAletoria;

    return PosicionRan;
}

int SelecionTemas(int temaSeleccionado) // Seleccionar los temas que los jugadores desean jugar
{

    char confirmacion;

    int Cantiad;

    // Almacenar mensajes para evitar repetirlos
    string mensajeOne = "Seleccione el tema con el que desea jugar.";
    string mensajeTwo = "Importante: El tema seleccionado aplicará para todas las preguntas a todos los jugadores."; // Plural
    string mensajeThree = "¿Está seguro de que desea seleccionar este tema?";
    string mensajeFour = "Presione 's' para confirmar";
    string mensajeFive = "Presione 'n' para cambiar la selección del tema";
    string mensajeSix = "Seleccionen el tema con el que desean jugar.";
    string mensajeSeven = "Importante: El tema seleccionado aplicará para todas las preguntas."; // Individual

    cantidadJugadores(Cantiad);

    if (Cantiad == 1)
    {
        cout << mensajeOne << endl;
        cout << mensajeSeven << endl;
    }
    else
    {
        cout << mensajeSix << endl;
        cout << mensajeTwo << endl;
    }

    temas();

    while (true)
    {
        cout << "- ";
        cin >> temaSeleccionado;
        cout << mensajeThree << endl;
        cout << mensajeFour << " / " << mensajeFive << endl;
        cout << "- ";
        cin >> confirmacion;

        if (confirmacion == 's')
        {
            break; // Salir del bucle si la confirmación es 's'
        }
        else if (confirmacion == 'n')
        {
            if (Cantiad == 1)
            {
                cout << mensajeOne << endl;
                cout << mensajeSeven << endl;
            }
            else
            {
                cout << mensajeSix << endl;
                cout << mensajeTwo << endl;
            }

            temas();
        }
    }

    return temaSeleccionado;
}

void temas()
{
    string arre[4] = {"TEMA: FUTBOL", "TEMA: MITOLOGIA", "TEMA: GEOGRAFIA", "TEMA: CULTURA GENERAL"};

    cout << "        TEMAS       " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << arre[i] << endl;
    }
}

int ModalidadJuego(int Opcion) // Selecciona de la modalidad del juego
{

    string mensajeOne = "Seleccione con que modalidad desean jugar.";
    string mensajeTwoo = "Seleccione con que modalidad desea jugar.";

    int Cantiad;

    cantidadJugadores(Cantiad);

    if (Cantiad == 1)
    {
        cout << mensajeOne << endl;
    }
    else
    {
        cout << mensajeTwoo << endl;
    }

    cout << "Las modalidades disposnibles son:" << endl;
    cout << " 1 - HASTA FINALIZAR" << endl;
    cout << " 2 - CON LIMITES DE DERROTAS (3) MAXIMO" << endl;

    cin >> Opcion;

    return Opcion;
}

void LlamarArrePreguntas(string enviarPreguntas[], string enviarRespuestas[])
{ // Bosquejo para utilizar los datos de la libreria en las funciones de jugar

    // Tema 1:

    /*Hay que simular que las preguntas son estas porque se necesita este formato
   para poder validar las respuestas cuando el juego se este ejecutando*/

    string arrePreguntas[Num_Preguntas] = {
        "¿Cual es la capital de Francia?\n1. Berlin\n2. Madrid\n3. Paris",
        "¿Cual es el rio mas largo del mundo?\n1. Nilo\n2. Amazonas\n3. Yangtse",
        "¿Quien escribio Cien años de soledad?\n1. Gabriel García Marquez\n2. Mario Vargas Llosa\n3. Julio Cortazar",
        "¿En que año llegó el hombre a la Luna?\n1. 1965\n2. 1969\n3. 1971",
        "¿Cual es el planeta mas cercano al sol?\n1. Venus\n2. Tierra\n3. Mercurio"};

    /*El indice de las respuesta deben estar en el orden de las respuestas correctas segun la
    posicion que se coloco la respuesta correcta en el arreglo de las preguntas*/

    string arreRespuestas[Num_Preguntas] = {
        "3",
        "2",
        "1",
        "2",
        "3"};

    for (int i = 0; i < Num_Preguntas; i++)
    {
        enviarPreguntas[i] = arrePreguntas[i];
        enviarRespuestas[i] = arreRespuestas[i];
    }

    // Tema 2: ...
}

int multijugador() // Es el are en que la jugabilidad de las preguntas sera entre 2 o mas participantes
{
}