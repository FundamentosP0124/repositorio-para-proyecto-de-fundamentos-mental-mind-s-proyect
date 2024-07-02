#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

const int Num_Preguntas = 5;

// Necesitamos agregar vectores para, poder almacenar datos en diversas ocaciones sin perder los ya existentes

// B O R R A D O R

vector<string> nombres;   // Conservar los nombres de los jugadores en caso de que repitan el ciclo del juego y agreguen nuevos jugadores
vector<int> puntuaciones; // Conservar las puntuaciones con el mismo fin

// DECLARACIONES

void menu();
int cantidadJugadores(int);
int SelecionTemas(int);
void temas();
int ModalidadJuego(int);
void LlamarArrePreguntas(string, string);
int ValidarNumeros();
string ValidarEntradasText();
int validarNumeroRango(int, int);

int main(void)
{
    menu();

    return 0;
}

string ValidarEntradasText()
{
    string texto;
    while (true)
    {
        cout << "- ";
        getline(cin, texto);

        bool esValido = true;
        for (char c : texto)
        {
            if (!isalpha(c) && c != ' ') // Verificamos cada uno de los caracteres para saber si no es alfabetico
            {
                esValido = false;
                break;
            }
        }

        if (esValido && !texto.empty())
        {
            return texto;
        }
        else
        {
            cout << "Entrada invalida. Por favor, solo ingrese caracteres de tipo alfabeticos" << endl;
        }
    }
}

int ValidarNumeros()
{
    int numero;
    while (true)
    {
        cout << "- ";
        cin >> numero;

        if (cin.fail() || numero <= 0)
        {
            cin.clear(); // Limpia el error

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada invalida
            cout << "Entrada invalida. Por favor, ingrese numeros que no sean decimales o de cualquier otro tipo. Deben ser 1 o 2." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero; // Retorna el numero valido
        }
    }
}

int validarNumeroRango(int min, int max)
{
    int numero;
    while (true)
    {
        cout << "- ";
        cin >> numero;
        if (cin.fail() || numero < min || numero > max)
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, ingrese una opcion que este entre el rango de: " << min << " y de " << max << ": ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return numero;
}

void menu() // Agregar la funcion de validar la opcion ingresada
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
    string mensajeTwo = "¿Esta seguro de: 2 - '2' jugadores.";
    string mensajeThree = "Presione 's' para confirmar, 'n' para cambiar la cantidad de jugadores.";

    // Realizamos la confirmación
    while (true)
    {
        // Leemos la entrada
        cout << "1 - Solo '1' jugador." << endl;
        cout << "2 - De '2' jugadores." << endl;

        Cant = ValidarNumeros(); // Llama a la funcion de validacion para obtener un numero valido

        // Confirmamos la cantidad
        cout << endl;
        cout << mensajeTwo << Cant << "?" << endl;
        cout << mensajeThree << endl;
        cout << "- ";

        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirmacion == 's' || confirmacion == 'S')
        {
            break; // Salir del bucle si la confirmacion es 's' o 'S'
        }
    }

    return Cant;
}

int SelecionTemas(int temaSeleccionado)
{
    char confirmacion;
    int Cantiad;

    // Almacenar mensajes para evitar repetirlos
    string mensajeOne = "Seleccione el tema con el que desea jugar.";
    string mensajeTwo = "Importante: El tema seleccionado aplicara para todas las preguntas a los 2 jugadores.";
    string mensajeThree = "¿Esta seguro de que desea seleccionar este tema?";
    string mensajeFour = "Presione 's' para confirmar";
    string mensajeFive = "Presione 'n' para cambiar la seleccion del tema";
    string mensajeSix = "Seleccionen el tema con el que desean jugar.";
    string mensajeSeven = "Importante: El tema seleccionado aplicara para todas las preguntas.";

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
        temaSeleccionado = validarNumeroRango(1, 4); // Validamos que el tema esté entre 1 y 4
        cout << mensajeThree << endl;
        cout << mensajeFour << " / " << mensajeFive << endl;
        cout << "- ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S')
        {
            break; // Salir del bucle si la confirmación es 's'
        }
        else if (confirmacion == 'n' || confirmacion == 'N')
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
        }
    }

    return temaSeleccionado;
}

void temas()
{
    string arre[4] = {"1 - TEMA: FUTBOL", "2 - TEMA: MITOLOGIA", "3 - TEMA: GEOGRAFIA", "4 - TEMA: CULTURA GENERAL"};

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

    Opcion = validarNumeroRango(1, 2);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

struct ResultadosIndividual
{
    int RespIncorrectas;
    int RespCorrectas;
};

ResultadosIndividual juegoIndividual()
{ // Funcion con limites de desaciertos y se necesita modificar para la configuracion seleccionada

    ResultadosIndividual resultados = {0, 0};

    int ConfOpcion = 0;

    ModalidadJuego(ConfOpcion);

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

    for (int i = 0; i < Num_Preguntas; i++)
    {
        cout << "Pregunta numero: " << i + 1 << endl;
        cout << preguntas[i] << endl;

        cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
        Guardarespuesta = ValidarNumeros();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        opcionCorrecta = stoi(respuestas[i]); // Convertir las respuestas en caracteres enteros para poder compararlas con la respuesta ingresada

        // Verificar que la respuesta ingresada sea correcta
        if (Guardarespuesta == opcionCorrecta)
        {
            resultados.RespCorrectas++;
            cout << "Correcto" << endl;
        }
        else
        {
            resultados.RespIncorrectas++;
            cout << "Incorrecto" << endl;
        }

        // Si la opcion seleccionada en el menu de configuracion es igual a 2 realizara la siguiente opcion si no, seguira con el proceso normal

        if (ConfOpcion == 2)
        {
            // Verificar si el usuario ha alcanzado el limite de respuestas incorrectas
            if (resultados.RespIncorrectas == 3)
            {
                break;
            }
        }
    }

    cout << "Juego terminado." << endl;
    cout << "Resultados" << endl;

    return resultados; // Devolver la cantidad de respuestas correctas e incorrectas que obtuvo
}

struct ResultadosMultijugador { //Para poder utilizar los valores en otras funciones para anunciar al ganador necesitamos recuperar los datos en una estructura
    int RespCorrectasPlayerOne;
    int RespIncorrectasPlayerOne;
    int RespCorrectasPlayerTwo;
    int RespIncorrectasPlayerTwo;
};

ResultadosMultijugador multijugador() // Retornamos una instancia a la estructura resultados de ambos jugadores
{
    ResultadosMultijugador resultados = {0, 0, 0, 0};
    int ConfOpcion = 0;
    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];

    ModalidadJuego(ConfOpcion);
    LlamarArrePreguntas(preguntas, respuestas);

    bool playerOneActive = true;
    bool playerTwoActive = true;

    for (int i = 0; i < Num_Preguntas; i++) // Definimos la cantidad de veces que se repetirá según la cantidad de preguntas
    {
        // Player One
        if (playerOneActive) {
            cout << "Pregunta numero " << i + 1 << " para el Jugador 1:" << endl;
            cout << preguntas[i] << endl;

            cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            int Guardarespuesta = ValidarNumeros();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int OpcionCorrecta = stoi(respuestas[i]);

            if (Guardarespuesta == OpcionCorrecta) {
                resultados.RespCorrectasPlayerOne++;
                cout << "Correcto" << endl;
            } else {
                resultados.RespIncorrectasPlayerOne++;
                cout << "Incorrecto" << endl;
            }

            if (ConfOpcion == 2 && resultados.RespIncorrectasPlayerOne >= 3) {
                playerOneActive = false;
                cout << "Jugador 1 ha alcanzado el limite de respuestas incorrectas y no participara en la siguiente ronda." << endl;
            }
        }

        // Player Two
        if (playerTwoActive) {
            cout << "Pregunta numero " << i + 1 << " para el Jugador 2:" << endl;
            cout << preguntas[i] << endl;

            cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            int Guardarespuesta = ValidarNumeros();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int OpcionCorrecta = stoi(respuestas[i]);

            if (Guardarespuesta == OpcionCorrecta) {
                resultados.RespCorrectasPlayerTwo++;
                cout << "Correcto" << endl;
            } else {
                resultados.RespIncorrectasPlayerTwo++;
                cout << "Incorrecto" << endl;
            }

            if (ConfOpcion == 2 && resultados.RespIncorrectasPlayerTwo >= 3) {
                playerTwoActive = false;
                cout << "Jugador 2 ha alcanzado el limite de respuestas incorrectas y no participará en la siguiente ronda." << endl;
            }
        }

        // Verificar si ambos jugadores han sido eliminados
        if (!playerOneActive && !playerTwoActive) {
            cout << "Ambos jugadores han alcanzado el limite de respuestas incorrectas. El juego ha terminado." << endl;
            break;
        }
    }

    return resultados; //Aqui le retorno los resultados obtenidos durante el juego a la estructura
}