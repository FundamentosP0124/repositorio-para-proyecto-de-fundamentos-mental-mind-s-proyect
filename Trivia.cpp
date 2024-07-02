#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

const int Num_Preguntas = 5;

// Necesitamos agregar vectores para, poder almacenar datos en diversas ocaciones sin perder los ya existentes

// B O R R A D O R

vector<string> nombres;   // Conservar los nombres de los jugadores en caso de que repitan el ciclo del juego y agreguen nuevos jugadores
vector<int> puntuaciones; // Conservar las puntuaciones con el mismo fin

void menu();
int cantidadJugadores(int);
int SelecionTemas(int);
void temas();
int ModalidadJuego(int);
void LlamarArrePreguntas(string, string);
int juegoIndividual();

int main(void)
{
    int respuestasCorrectas = juegoIndividual();
    cout << "El juego ha terminado." << endl;
    cout << "Respuestas correctas: " << respuestasCorrectas << endl;

    return 0;
}

string ValidarEntradasText()
{ // Necesitamos validar entradas de texto desde teclado para que no surgan errores en el procesamiento de datos en las funciones
}

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int ValidarEntradasNum()
{
    int numero;
    while (true)
    {
        cout << "- ";
        cin >> numero;

        if (cin.fail() || numero <= 0)
        {
            cin.clear();                                         // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada inválida
            cout << "Entrada inválida. Por favor, ingrese un número entero positivo." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero; // Retorna el número válido
        }
    }
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

int cantidadJugadores(int Cant)
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

        Cant = ValidarEntradasNum(); // Llama a la función de validación para obtener un número válido

        // Confirmamos la cantidad
        cout << endl;
        cout << mensajeTwo << Cant << "?" << endl;
        cout << mensajeThree << endl;
        cout << "- ";

        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

        if (confirmacion == 's' || confirmacion == 'S')
        {
            break; // Salir del bucle si la confirmación es 's' o 'S'
        }
    }

    return Cant;
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

void LlamarArrePreguntas(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "¿Cual es la capital de Francia?\n1. Berlin\n2. Madrid\n3. Paris",
        "¿Cual es el rio mas largo del mundo?\n1. Nilo\n2. Amazonas\n3. Yangtse",
        "¿Quien escribio Cien años de soledad?\n1. Gabriel Garcia Marquez\n2. Mario Vargas Llosa\n3. Julio Cortazar",
        "¿En que año llego el hombre a la Luna?\n1. 1965\n2. 1969\n3. 1971",
        "¿Cual es el planeta mas cercano al sol?\n1. Venus\n2. Tierra\n3. Mercurio"};

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
}

int juegoIndividual()
{ // Funcion con limites de desaciertos y se necesita modificar para la configuracion seleccionada

    int ConfOpcion = 0;

    ModalidadJuego(ConfOpcion);

    int RespIncorrectas = 0, RespCorrectas = 0;
    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];

    // Llamar a la funcion para obtener preguntas y respuestas
    LlamarArrePreguntas(preguntas, respuestas);

    int opcionCorrecta;
    int Guardarespuesta;

    cout << "__¿ESTAS LISTO PARA EMPEZAR?__" << endl;
    cout << "__Presiona enter para empezar__";
    cin.ignore();
    cin.get(); // Esperar a que el usuario presione enter

    cout << "NIVEL FACIL" << endl;

    for (int i = 0; i < Num_Preguntas; i++)
    {
        cout << "Pregunta numero: " << i + 1 << endl;
        cout << preguntas[i] << endl;

        cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
        cin >> Guardarespuesta;

        opcionCorrecta = stoi(respuestas[i]); // Convertir las respuestas en caracteres enteros para poder compararlas con la respuesta ingresada

        // Verificar que la respuesta ingresada sea correcta
        if (Guardarespuesta == opcionCorrecta)
        {
            RespCorrectas++;
            cout << "Correcto" << endl;
        }
        else
        {
            RespIncorrectas++;
            cout << "Incorrecto" << endl;
        }

        // Si la opcion seleccionada en el menu de configuracion es igual a 2 realizara la siguiente opcion si no, seguira con el proceso normal

        if (ConfOpcion == 2)
        {
            // Verificar si el usuario ha alcanzado el limite de respuestas incorrectas
            if (RespIncorrectas == 3)
            {
                break;
            }
        }
    }

    cout << "Juego terminado." << endl;
    cout << "Respuestas correctas: " << RespCorrectas << endl;
    cout << "Respuestas incorrectas: " << RespIncorrectas << endl;

    return RespCorrectas; // Devolver la cantidad de respuestas correctas que obtuvo
}

int multijugador() // Es el area en que la jugabilidad de las preguntas sera entre 2 o mas participantes
{
}