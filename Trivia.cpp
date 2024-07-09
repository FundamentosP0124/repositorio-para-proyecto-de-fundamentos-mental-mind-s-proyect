#include "iostream"
#include "cstdlib" //Para usar exit()
#include "string"
#include "cctype"
#include "limits"
#include "ctime"

using namespace std;

// Declaraciones Hector
void Menu();
void IniciarJuego();
void MostrarAyuda();
void RegistroDesarrolladores();
void TemasEvaluados();
void ObjetivosdelJuego();
void mostrarJugadoresInscritos();
void imprimirParrafo(const string &parrafo);
bool Salir();
void guardarPuntuacionesTemporales();
void EvaluarSolitario();
void EvaluarMultijugador();

// Declaraciones Cesar
int cantidadJugadores();
int SelecionTemas();
void temas();
int ModalidadJuego();
void LlamarArrePreguntasFutbol(string, string);
void LlamarArrePreguntasMitologia(string, string);
void LlamarArrePreguntasGeografia(string, string);
void LlamarArrePreguntasCultGeneral(string, string);
void registrarJugadores();
void multijugador();
int juegoIndividual();

const int Num_Preguntas = 15;
// DECLARACIONES

// Contadores que validaran que el maximo de jugadores no sobrepase
int cantidadActualJugadores = 0;
int cantidadActualPuntuaciones = 0;
const int maximoJugadores = 100;
const int maxiPuntuacion = 100;

// Variables para guardar Nombres y Puntuaciones
string guardarNombres[maximoJugadores];
int guardarPuntuaciones[maxiPuntuacion];
string nombresRecientes[2];

// Declaraciones de variables para enviar los valores

int puntuacionOneTemporales = 0;
int puntuacionTwoTemporales = 0;

int puntuacionIndividual = 0;

// Mostrar los nombres recientes

string NOMBRES_RECIENTES[2] = {};

// Reutilizar los valores que se obtengan

int CANTIDAD_JUGADORES = 0;
int SELECCIONAR_TEMAS = 0;
int OPCION_MODALIDAD_JUEGO = 0;

int main(void)
{
    Menu();

    return 0;
}

void imprimirParrafo(const string &parrafo)
{
    cout << parrafo << endl;
}

void Menu()
{
    int opcion;

    do
    {

        cout << endl;
        cout << "Presione enter para empezar";
        cin.get(); // En espera del enter para seguir

        cout << endl;
        cout << "============================" << endl;
        cout << "  Bienvenidos a TriviaZone  " << endl;
        cout << "============================" << endl;
        cout << "       MENU PRINCIPAL       " << endl;
        cout << "============================" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Ayuda" << endl;
        cout << "3. Creditos/Desarrolladores" << endl;
        cout << "4. Temas de las Preguntas" << endl;
        cout << "5. Objetivos del juego" << endl;
        cout << "6. Salir" << endl;
        cout << "============================" << endl;
        cout << endl;

        cout << "Ingrese la opcion a realizar: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
            IniciarJuego();
            break;
        case 2:
            MostrarAyuda();
            break;
        case 3:
            RegistroDesarrolladores();
            break;
        case 4:
            TemasEvaluados();
            break;
        case 5:
            ObjetivosdelJuego();
            break;
        case 6:
            if (Salir())
            {
                exit(0);
            }
            break;
        default:
            cout << "La opcion registrada no es valida. Por favor seleccione nuevamente." << endl;
            break;
        }
    } while (true);
}

void MostrarAyuda()
{
    system("clear||cls");
    cout << endl;
    const string parrafo =
        "Usted ha seleccionado la opcion Ayuda. Permitanos explicarte el funcionamiento del juego.\n\n"
        "Bienvenidos a TriviaZone!!! En este juego podras dar a relucir tus conocimientos sobre cualquier tema; en esta ocasion te presentaremos una cierta\n"
        "cantidad de temas seleccionados por nosotros para que los disfrutes resolviendo intentando obtener la mayor cantidad de respuestas acertadas.\n\n"

        "A continuacion, te explicaremos brevemente de como funciona este juego de Preguntas y Respuestas. Esperamos que te guste :D .\n\n"

        "En TriviaZone hay dos modos para jugar, por lo tanto, cuando selecciones jugar el sistema te preguntara que tipo de modo te gustaria jugar. Existen\n"
        "dos modos: El primero es el Modo Solitario donde el usuario seleccionara el tema a jugar por su cuenta con el objetivo de contestar la mayor cantidad\n"
        "de preguntas presentadas durante el juego, el metodo de evaluacion sera que al final de la ronda de preguntas se llevara a cabo por medio de Insignias;\n"
        "estas insignias se tratan de Enciclopedia Viviente (Para los jugadores que han demostrado un dominio excepcional de preguntas de trivia), Sabio en Progreso\n"
        "(Para aquellos que estan comenzando a descubrir su potencial en trivia) y Rezagado del Saber (Para los jugadores que aun estan encontrando su camino en el mundo\n"
        "de la trivia). Para obtener Enciclopedia Viviente necesitas tener mas de 10 preguntas acertadas, mientras tanto con Sabio en Progreso lo unico que necesitas es\n"
        "tener 5 o mas preguntas acertadas, por ultimo, para obtener Rezagado del Saber necesitas haber obtenido solamente 4 preguntas acertadas. Esta explicacion es para\n"
        "quienes gusten jugar en el Modo Solitario.\n\n"

        "Para el segundo modo de juego se trata del Modo Multijugador donde se selecciona en numero de participantes y el tema a evaluar antes de empezar la trivia\n"
        "de preguntas y respuestas. El metodo de evaluacion planteado conlleva de que los usuarios van contestando cada pregunta simultaneamente antes de pasar a la\n"
        "siguiente, donde cada pregunta vale un punto; cuando los usuarios inscritos hayan terminado la ronda de preguntas, al final se mostrara el ganador del preguntas\n"
        "y respuestas de TriviaZone a traves de la comparacion entre las respuestas correctas de los dos jugadores, es decir, solo hay un ganador. Sin embargo, si al final\n"
        "los dos jugadores poseen la misma cantidad de preguntas acertadas, la ronda se declarara como un empate sin ganador.\n\n"

        "Basicamente de esto trata el juego, esperamos que lo disfrutes.";

    // Llamamos a la función para imprimir el párrafo
    imprimirParrafo(parrafo);
    cout << endl;

    char salir;

    cout << "Presiona 's' o 'S' para regresar al menu principal..." << endl;
    cin >> salir;

    if (salir == 's' || salir == 'S')
    {
        system("clear||cls");
        Menu();
    }
}

void RegistroDesarrolladores()
{
    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Creditos/Desarrolladores. Echemos un vistazo de los creadores de este juego!!!" << endl
         << endl;
    cout << endl;
    cout << "================================================" << endl;
    cout << "                    CREDITOS         " << endl;
    cout << "================================================" << endl;
    cout << "  De la O Ortiz, Cesar Daniel        00205824" << endl;
    cout << "  Casco Miranda, Hector Enrique      00141124" << endl;
    cout << "================================================" << endl;
    cout << endl;

    char salir;

    cout << "Presiona 's' o 'S' para regresar al menu principal..." << endl;
    cin >> salir;

    if (salir == 's' || salir == 'S')
    {
        system("clear||cls");
        Menu();
    }
}

void TemasEvaluados()
{
    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Temas de las Preguntas. Vamos a ver cuales son las tematicas evaluadas en esta Trivia." << endl
         << endl;
    cout << endl;
    cout << "Bienvenidos al apartado de Temas Evaluados en TriviaZone!!! En esta seccion solo te mostraremos los temas a evaluar en esta Trivia" << endl;
    cout << "para que puedas tener la mente en claro sobre las preguntas definidas que te apareceran segun la seccion que tu elijas." << endl;
    cout << "A continuacion, te presentamos los 4 temas evaluados en TriviaZone:" << endl
         << endl;
    cout << "1- Futbol" << endl;
    cout << "2- Mitologia" << endl;
    cout << "3- Geografia/Paises" << endl;
    cout << "4- Cultura General" << endl
         << endl
         << endl;
    cout << "Al momento que selecciones jugar, tu elegiras el tema de preguntas que te gustaria desafiar. Buena Suerte Triviano!!!" << endl;
    cout << endl;

    char salir;

    cout << "Presiona 's' o 'S' para regresar al menu principal..." << endl;
    cin >> salir;

    if (salir == 's' || salir == 'S')
    {
        system("clear||cls");
        Menu();
    }
}

void ObjetivosdelJuego()
{
    system("clear||cls");
    cout << endl;
    const string parrafo =
        "Realizar un juego en lenguaje C++ donde se abarquen todos los temas vistos en las\n"
        "clases, debe hacer uso de git para su trabajo colaborativo. El juego debe ser de\n"
        "competencia y reportar ganador. Por ejemplo: carreras de caballos, piedra papel o\n"
        "tijera, ahorcado, equis-cero, etc. Todo sera en modo texto, no se admitira modo\n"
        "grafico para el desarrollo de ninguna parte de su juego.\n\n "

        "Con el objetivo de desarrollar un programa en C++ que permita demostrar todas las habilidades\n"
        "adquiridas a lo largo del curso como el uso de instrucciones iterativas, condicionales,\n"
        "arreglos, funciones, entre otros.";

    // Llamamos a la función para imprimir el párrafo
    imprimirParrafo(parrafo);
    cout << endl;

    char salir;

    cout << "Presiona 's' o 'S' para regresar al menu principal..." << endl;
    cin >> salir;

    if (salir == 's' || salir == 'S')
    {
        system("clear||cls");
        Menu();
    }
}

bool Salir()
{
    system("clear||cls");
    int opcionS;

    cout << "Estas seguro de terminar el juego?" << endl
         << endl;
    cout << "Presiona 1 para salir o 0 para continuar: ";

    do
    {
        cin >> opcionS; // Leer la opción del usuario

        switch (opcionS)
        {
        case 1:
            cout << endl;
            cout << "Usted ha seleccionado la opcion Salir. See you next time Triviano!!!" << endl
                 << endl;
            return true; // Termina el programa
            break;
        case 0:
            cout << endl;
            cout << "Continuando el juego..." << endl;
            cout << endl;
            return false;
            break;
        default:
            cout << endl;
            cout << "Opcion inexistente. Intente nuevamente: ";
            cout << endl;
            break;
        }
    } while (opcionS != 1); // Salir del bucle cuando la opción sea válida

    return false;
}

void IniciarJuego()
{

    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Jugar. Disfrute de TriviaZone!!!" << endl
         << endl;
    // Aquí irá el funcionamiento del juego

    cantidadJugadores();

    registrarJugadores();

    mostrarJugadoresInscritos();

    SelecionTemas();

    ModalidadJuego();

    int Opcion = CANTIDAD_JUGADORES;

    if (Opcion == 1)
    {
        juegoIndividual();
    }
    else
    {
        multijugador();
    }
}

void EvaluarSolitario()
{

    int respuestasCorrectas = puntuacionIndividual;

    if (respuestasCorrectas > 10)
    {
        cout << endl;
        cout << "Eres increible!!! Felicidades por obtener la insignia mas aclamada: Enciclopedia Viviente."; // Enciclopedia Viviente
        cout << endl;
    }
    else if (respuestasCorrectas >= 5 && respuestasCorrectas <= 10)
    {
        cout << endl;
        cout << "Bien hecho Triviano!!! Tus habilidades innatas y conocimiento de la cultura general te han permitido hacerte de la insignia: Sabio en Progreso."; // Sabio en Progreso
        cout << endl;
    }
    else if (respuestasCorrectas >= 0 && respuestasCorrectas <= 4)
    {
        cout << endl;
        cout << "Que mala fortuna Triviano... Al parecer no has estado fino con tu conocimiento sobre estas diferentes tematicas evaluadas, vuelve a intentarlo." << endl;
        cout << "Buena Suerte!!! Tu insignia es: Rezagado del Saber."; // Rezagado del Saber
        cout << endl;
    }
}

void EvaluarMultijugador()
{
    int respuestasCorrectasPlayer1 = puntuacionOneTemporales, respuestasCorrectasPlayer2 = puntuacionTwoTemporales;

    if (respuestasCorrectasPlayer1 > respuestasCorrectasPlayer2)
    {
        cout << "El ganador es el jugador 1 por la cantidad de " << respuestasCorrectasPlayer1 << " puntos." << endl;
    }
    else if (respuestasCorrectasPlayer1 < respuestasCorrectasPlayer2)
    {
        cout << "El ganador es el jugador 2 por la cantidad de " << respuestasCorrectasPlayer2 << " puntos" << endl;
    }
    else
    {
        cout << "Los dos jugadores tienen el mismo puntaje con la cantidad de " << respuestasCorrectasPlayer1 << " puntos." << endl;
    }
}

void guardarPuntuacionesTemporales()
{
    if (cantidadActualJugadores < maxiPuntuacion)
    {
        guardarPuntuaciones[cantidadActualPuntuaciones++] = puntuacionOneTemporales;
        guardarPuntuaciones[cantidadActualPuntuaciones++] = puntuacionTwoTemporales;
    }
    else
    {
        cout << "No se pueden registrar mas jugadores o puntuaciones, se ha alcanzado el maximo." << endl;
    }
}

void mostrarJugadoresInscritos()
{
    cout << "Los nombres de los participantes inscritos en TriviaZone son los siguientes: " << endl
         << endl;

    for (int i = 0; i < CANTIDAD_JUGADORES; i++)
    {
        cout << NOMBRES_RECIENTES[i] << endl;
    }
}

int cantidadJugadores()
{

    int Cant = 0;

    string confirmacion;
    // Almacenar mensajes para evitar repetirlos
    string mensajeOne = "Esta seguro de: 1 - jugador";
    cout << endl;
    string mensajeTwo = "Esta seguro de: 2 - jugadores";
    cout << endl;
    string mensajeThree = "Presione 's' para confirmar, 'n' para cambiar la cantidad de jugadores.";
    cout << endl;
    // Realizamos la confirmación
    while (true)
    {
        // Leemos la entrada
        cout << "1 - Solo '1' jugador." << endl;
        cout << "2 - De '2' jugadores." << endl;
        cin >> Cant;

        // Confirmamos la cantidad
        if (Cant == 2)
        {
            cout << endl;
            cout << mensajeTwo << Cant << "?" << endl;
            cout << mensajeThree << endl;
            cout << "- ";
        }
        else
        {
            cout << endl;
            cout << mensajeOne << Cant << "?" << endl;
            cout << mensajeThree << endl;
            cout << "- ";
        }
        cin >> confirmacion;
        if (confirmacion == "s" || confirmacion == "S")
        {
            break; // Salir del bucle si la confirmacion es 's' o 'S'
        }
    }
    CANTIDAD_JUGADORES = Cant;
}

void registrarJugadores()
{
    int cantidadActual = 0;

    string nombresRecientes[2] = {};

    string confirmacion;

    cout << endl;
    string mensajeOne = "Presione 's' para confirmar, 'n' para cambiar los nombres de los jugadores.";

    int cantidad = CANTIDAD_JUGADORES;

    while (true)
    {
        cout << endl;
        cout << "Para registrar tu alias, puedes ocupar letras, numeros y simbolos" << endl
             << endl;

        for (int i = 0; i < cantidad; i++)
        {
            cout << endl;
            cout << "Registra tu alias" << endl 
                 << endl;
            if (cantidad > 1)
            {
                cout << " (" << i + 1 << ")";
            }
            cout << ": ";
            cin >> nombresRecientes[i]; // Luego pasar a guardarNombres
        }

        cout << mensajeOne;

        cin >> confirmacion;
        if (confirmacion == "s" || confirmacion == "S")
        {
            break; // Salir del bucle si la confirmacion es 's' o 'S'
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        NOMBRES_RECIENTES[i] = nombresRecientes[i];
    }

    for (int i = 0; i < cantidad; i++)
    {
        guardarNombres[cantidadActual + i] = nombresRecientes[i];
    }

    cantidadActual += cantidad; // Actualizar la cantidad actual de jugadores
}

int SelecionTemas()
{
    char confirmacion;
    int Cantiad = CANTIDAD_JUGADORES, temaSeleccionado;
    // Almacenar mensajes para evitar repetirlos
    cout << endl;
    string mensajeOne = "Seleccione el tema con el que desea jugar.";
    cout << endl;
    string mensajeTwo = "Importante: El tema seleccionado aplicara para todas las preguntas a los 2 jugadores.";
    cout << endl;
    string mensajeThree = "Esta seguro de que desea seleccionar este tema?";
    string mensajeFour = "Presione 's' para confirmar";
    string mensajeFive = "Presione 'n' para cambiar la seleccion del tema";
    cout << endl;
    string mensajeSix = "Seleccionen el tema con el que desean jugar.";
    cout << endl;
    string mensajeSeven = "Importante: El tema seleccionado aplicara para todas las preguntas.";
    cout << endl;
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
        cin >> temaSeleccionado; // Validamos que el tema esté entre 1 y 4
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
    SELECCIONAR_TEMAS = temaSeleccionado;
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
int ModalidadJuego() // Selecciona de la modalidad del juego
{

    int Opcion;
    cout << endl;
    string mensajeOne = "Seleccione con que modalidad desean jugar.";
    cout << endl;
    string mensajeTwoo = "Seleccione con que modalidad desea jugar.";
    cout << endl;
    int Cantiad = CANTIDAD_JUGADORES;
    if (Cantiad == 1)
    {
        cout << mensajeOne << endl;
    }
    else
    {
        cout << mensajeTwoo << endl;
    }
    cout << "Las modalidades disponibles son:" << endl;
    cout << " 1 - HASTA FINALIZAR" << endl;
    cout << " 2 - CON LIMITES DE DERROTAS (3) MAXIMO" << endl;
    cin >> Opcion;

    OPCION_MODALIDAD_JUEGO = Opcion;
}
void LlamarArrePreguntasFutbol(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "En que pais se jugo la primera copa del mundo de la fifa?\n1) Argentina\n2) Uruguay\n3) Inglaterra",                                                  // 1
        "A la fecha, ¿Quien es el maximo goleador de todos los tiempos en la historia de la copa del mundo?\n1) Misrolav\n2) Ronaldo Nazarino\n3) Gerd Muller", // 2
        "Pele gano 3 copas del mundo\n1) Verdadero\n2) Falso",                                                                                                  // 3
        "En que pais se invento el futbol moderno?\n1) Brasil\n2) España\n3) Inglaterra",                                                                      // 4
        "Cristiano Ronaldo hizo su debut oficial en el real Madrid con el numero 19. \n1) Verdadero\n2) Falso",                                                 // 5
        "En que año se fundo la FIFA? \n1) 1910\n2) 1904\n3) 1901",                                                                                            // 6
        "Brasil es la unica seleccion que ha participado en todas las ediciones de la copa del mundo. \n1) Verdadero\n2) Falso",                                // 7
        "Quien gano el premio al mejor jugador de la FIFA en 2020? \n1) Lionel Messi\n3) Robert Lewandoski\n3) Luca Modric",                                   // 8
        "Canada es uno de los paises que desarrollara la copa del mundo 2026. \n1) Verdadero\n2) Falso",                                                        // 9
        "Cual es el club de futbol que ha ganado mas veces la UEFA champions league?\n1) Barcelona\n2) Bayern de Munich\n3) Real Madrid CF",                   // 10
        "Italia gano la copa del mundo del 2006\n1) Verdadero\n2) Falso",                                                                                       // 11
        "En que año se jugo la primera copa del mundo de la fifa?\n1) 1930\n2) 1926\n3) 1934",                                                                 // 12
        "La primera edicion de la UEFA champions league se realizo en 1959\n1) Verdadero\n2) Falso",                                                            // 13
        "Quien es el maximo ganador del balon de oro de la historia?\n1) Lionel Messi\n2) Cristiano Ronaldo\n3) Vinicius Junior",                              // 14
        "La FIFA se fundo en Francia. \n1) Verdadero\n2) Falso"};                                                                                               // 15
    string arreRespuestas[Num_Preguntas] = {
        "2",  // 1
        "1",  // 2
        "1",  // 3
        "3",  // 4
        "2",  // 5
        "2",  // 6
        "1",  // 7
        "2",  // 8
        "1",  // 9
        "3",  // 10
        "1",  // 11
        "1",  // 12
        "2",  // 13
        "1",  // 14
        "1"}; // 15
    for (int i = 0; i < Num_Preguntas; i++)
    {
        enviarPreguntas[i] = arrePreguntas[i];
        enviarRespuestas[i] = arreRespuestas[i];
    }
}
void LlamarArrePreguntasMitologia(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "Quien es el dios del trueno en la mitologia nordica?\n1) Loki\n2) Thor\n3) Odin\n4) Balder",                                                              // 1
        "Como se llama el caballo de ocho patas de Odin en la mitologia nordica?\n1) Fenrir\n2) Jormungandr\n3) Garm\n4) Sleipnir",                                // 2
        "Que heroe griego completo los Doce Trabajos?\n1) Perseo\n2) Teseo\n3) Hercules\n4) Aquiles",                                                              // 3
        "Cual es el nombre del lobo gigante que esta destinado a matar a Odin durante el Ragnarök?\n1) Fenrir\n2) Garm\n3) Skoll\n4) Hati",                        // 4
        "Cual de las siguientes diosas griegas es la diosa de la sabiduria?\n1) Hera\n2) Atenea\n3) Afrodita\n4) Deméter",                                         // 5
        "Cual es el nombre del puente que conecta Asgard con el mundo de los humanos en la mitologia nordica?\n1) Yggdrasil\n2) Bifröst\n3) Valhalla\n4) Mjolnir", // 6
        "Quien es el dios de la luz y la belleza, asesinado por una flecha de muerdago en la mitologia nordica?\n1) Tyr\n2) Frey\n3) Balder\n4) Vidar",            // 7
        "Cual es el nombre del titan griego que sostiene el cielo sobre sus hombros?\n1) Cronos\n2) Atlas\n3) Prometeo\n4) Oceanus",                               // 8
        "Quien es la diosa del amor y la belleza en la mitologia griega?\n1) Hera\n2) Atenea\n3) Afrodita\n4) Artemisa",                                           // 9
        "Quien es el dios del fuego y la forja en la mitologia griega?\n1) Hefesto\n2) Tyr\n3) Heimdall\n4) Freyr",                                                // 10
        "Como se llama el martillo de Thor en la mitologia nordica?\n1) Gungnir\n2) Mjolnir\n3) Brisingamen\n4) Gram",                                             // 11
        "Quien es el mensajero de los dioses en la mitologia griega?\n1) Ares\n2) Hermes\n3) Apolo\n4) Dionisio",                                                  // 12
        "Quien es el dios del sol en la mitologia griega?\n1) Hades\n2) Apolo\n3) Dionisio\n4) Poseidón",                                                          // 13
        "Que animal persigue continuamente al sol y la luna en la mitologia nordica?\n1) Lobos\n2) Cuervos\n3) Serpientes\n4) Dragones",                           // 14
        "Como se llama el gigante que guarda la entrada al reino de los muertos en la mitologia nordica?\n1) Ymir\n2) Hel\n3) Garm\n4) Surtr"};                    // 15
    string arreRespuestas[Num_Preguntas] = {
        "2", // 1
        "4", // 2
        "3", // 3
        "1", // 4
        "2", // 5
        "2", // 6
        "3", // 7
        "2", // 8
        "3", // 9
        "1", // 10
        "2", // 11
        "2", // 12
        "2", // 13
        "1", // 14
        "3"  // 15
    };
    for (int i = 0; i < Num_Preguntas; i++)
    {
        enviarPreguntas[i] = arrePreguntas[i];
        enviarRespuestas[i] = arreRespuestas[i];
    }
}
void LlamarArrePreguntasGeografia(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "Cual es el pais mas grande del mundo en terminos de superficie?\n1) Canada\n2) China\n3) Rusia\n4) Estados Unidos",                        // 1
        "Cual es el rio mas largo del mundo?\n1) Nilo\n2) Amazonas\n3) Yangtse\n4) Misisipi",                                                       // 2
        "En que continente se encuentra el desierto del Sahara?\n1) Asia\n2) Africa\n3) America del Sur\n4) Oceania",                               // 3
        "Cual es la capital de Japon?\n1) Beijing\n2) Seul\n3) Tokyo\n4) Bangkok",                                                                  // 4
        "Cual es el pais mas pequeño del mundo en terminos de superficie?\n1) Monaco\n2) San Marino\n3) Liechtenstein\n4) Ciudad del Vaticano",     // 5
        "Cual es el pais mas grande de America del Sur por superficie?\n1) Argentina\n2) Brasil\n3) Peru\n4) Colombia",                             // 6
        "Cual es la capital de Canada?\n1) Toronto\n2) Vancouver\n3) Ottawa\n4) Montreal",                                                          // 7
        "Cual es el pais mas poblado del mundo?\n1) India\n2) Estados Unidos\n3) Indonesia\n4) China",                                              // 8
        "Que pais esta completamente rodeado por Sudafrica?\n1) Suazilandia\n2) Lesoto\n3) Botsuana\n4) Namibia",                                   // 9
        "Cual es la capital de Australia?\n1) Sidney\n2) Melbourne\n3) Canberra\n4) Brisbane",                                                      // 10
        "Que pais tiene la mayor cantidad de islas?\n1) Indonesia\n2) Filipinas\n3) Noruega\n4) Suecia",                                            // 11
        "Cual es el lago mas profundo del mundo?\n1) Lago Baikal\n2) Lago Tanganica\n3) Lago Superior\n4) Lago Victoria",                           // 12
        "En que pais se encuentra el Monte Kilimanjaro?\n1) Kenia\n2) Tanzania\n3) Uganda\n4) Etiopia",                                             // 13
        "Cual es el desierto más grande del mundo?\n1) Desierto del Gobi\n2) Desierto de Arabia\n3) Desierto del Kalahari\n4) Desierto del Sahara", // 14
        "Cual es la cordillera más larga del mundo?\n1) Montañas Rocosas\n2) Andes\n3) Alpes\n4) Himalayas"                                         // 15
    };
    string arreRespuestas[Num_Preguntas] = {
        "3", // 1
        "2", // 2
        "2", // 3
        "3", // 4
        "4", // 5
        "2", // 6
        "3", // 7
        "4", // 8
        "2", // 9
        "3", // 10
        "4", // 11
        "1", // 12
        "2", // 13
        "4", // 14
        "2"  // 15
    };
    for (int i = 0; i < Num_Preguntas; i++)
    {
        enviarPreguntas[i] = arrePreguntas[i];
        enviarRespuestas[i] = arreRespuestas[i];
    }
}
void LlamarArrePreguntasCultGeneral(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "Cual es el nombre del tratado que puso fin a la Primera Guerra Mundial?\n1) Tratado de Versalles\n2) Tratado de Paris\n3) Tratado de Tordesillas\n4) Tratado de Ginebra",                            // 1
        "Cual es el pais con la mayor cantidad de volcanes activos?\n1) Japon\n2) Indonesia\n3) Islandia\n4) Italia",                                                                                         // 2
        "Que artista es conocido por cortar su propia oreja?\n1) Pablo Picasso\n2) Salvador Dali\n3) Vincent van Gogh\n4) Claude Monet",                                                                      // 3
        "Cual es el organo mas grande del cuerpo humano?\n1) Corazon\n2) Higado\n3) Piel\n4) Pulmones",                                                                                                       // 4
        "Cual es la ciudad mas antigua continuamente habitada del mundo?\n1) Jerusalen\n2) Atenas\n3) Damasco\n4) Roma",                                                                                      // 5
        "Cual es el nombre del proceso por el cual las plantas convierten la luz solar en energia?\n1) Respiracion\n2) Fermentacion\n3) Fotosintesis\n4) Metabolismo",                                        // 6
        "Cual es el libro sagrado del Islam?\n1) La Biblia\n2) El Talmud\n3) El Coran\n4) Los Vedas",                                                                                                         // 7
        "Cual es el pais mas joven del mundo, habiendose independizado en 2011?\n1) Timor Oriental\n2) Montenegro\n3) Kosovo\n4) Sudan del Sur",                                                              // 8
        "Que movimiento artistico surgio a principios del siglo XX y es conocido por sus formas geometricas y su enfoque en la abstraccion?\n1) Impresionismo\n2) Expresionismo\n3) Cubismo\n4) Surrealismo", // 9
        "Cual es el idioma más hablado en el mundo?\n1) Ingles\n2) Español\n3) Chino mandarin\n4) Arabe",                                                                                                     // 10
        "En que año llego el hombre a la Luna por primera vez?\n1) 1965\n2) 1969\n3) 1972\n4) 1959",                                                                                                          // 11
        "Cual es la moneda oficial de Japon?\n1) Yuan\n2) Won\n3) Yen\n4) Dolar",                                                                                                                             // 12
        "En que pais se encuentra la ciudad de Petra?\n1) Jordania\n2) Egipto\n3) Turquia\n4) Grecia",                                                                                                        // 13
        "Cual es el elemento químico mas abundante en el universo?\n1) Helio\n2) Oxigeno\n3) Hidrogeno\n4) Carbono",                                                                                          // 14
        "Quien pinto 'La ultima cena'?\n1) Pablo Picasso\n2) Leonardo da Vinci\n3) Vincent van Gogh\n4) Claude Monet"                                                                                         // 15
    };
    string arreRespuestas[Num_Preguntas] = {
        "1", // 1
        "2", // 2
        "3", // 3
        "3", // 4
        "3", // 5
        "3", // 6
        "3", // 7
        "4", // 8
        "3", // 9
        "3", // 10
        "2", // 11
        "3", // 12
        "1", // 13
        "3", // 14
        "2"  // 15
    };
    for (int i = 0; i < Num_Preguntas; i++)
    {
        enviarPreguntas[i] = arrePreguntas[i];
        enviarRespuestas[i] = arreRespuestas[i];
    }
}
int juegoIndividual()
{ // Funcion con limites de desaciertos y se necesita modificar para la configuracion seleccionada
    int ConfOpcion = OPCION_MODALIDAD_JUEGO, temaSELECCIONADO = SELECCIONAR_TEMAS;
    int RespCorrectas = 0, RespIncorrectas = 0;
    // Importaciones para configurar las modalidades del juego
    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];
    // Importar las funciones que contienen las preguntas y respuestas
    switch (temaSELECCIONADO)
    {
    case 1:
        LlamarArrePreguntasFutbol(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : FUTBOL" << endl;
        cout << endl;
        break;
    case 2:
        LlamarArrePreguntasMitologia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : MITOLOGIA" << endl;
        cout << endl;
        break;
    case 3:
        LlamarArrePreguntasGeografia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : GEOGRAFIA" << endl;
        cout << endl;
        break;
    case 4:
        LlamarArrePreguntasCultGeneral(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : CULTURA GENERAL" << endl;
        cout << endl;
        break;
    }
    int opcionCorrecta;
    int Guardarespuesta;
    cout << "__ESTAS LISTO PARA EMPEZAR?__" << endl;
    cout << "__Presiona enter para empezar__";
    cin.ignore();
    cin.get(); // Esperar a que el usuario presione enter
    for (int i = 0; i < Num_Preguntas; i++)
    {
        cout << "Pregunta numero: " << i + 1 << endl;
        cout << preguntas[i] << endl;
        cout << endl;
        cout << "Cual es tu respuesta? (Ingresa el numero de la opcion): ";
        cin >> Guardarespuesta;
        opcionCorrecta = stoi(respuestas[i]); // Convertir las respuestas en caracteres enteros para poder compararlas con la respuesta ingresada
        // Verificar que la respuesta ingresada sea correcta
        if (Guardarespuesta == opcionCorrecta)
        {
            RespCorrectas++;
            cout << endl;
            cout << "Correcto" << endl;
        }
        else
        {
            RespIncorrectas++;
            cout << endl;
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
    cout << endl,
    cout << "Juego terminado." << endl
         << endl;
    cout << "Resultados" << endl 
         << endl;

    puntuacionIndividual = RespCorrectas; // Devolver la cantidad de respuestas correctas e incorrectas que obtuvo

    EvaluarSolitario();
}

void multijugador() // Retornamos una instancia a la estructura resultados de ambos jugadores
{

    int RespCorrectasPlayerOne, RespCorrectasPlayerTwo;

    int Guardarespuesta;

    int RespIncorrectasPlayerOne = 0, RespIncorrectasPlayerTwo = 0;
    int ConfOpcion = OPCION_MODALIDAD_JUEGO, temaSELECCIONADO = SELECCIONAR_TEMAS;
    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];

    // Importar las funciones que contienen las preguntas y respuestas
    switch (temaSELECCIONADO)
    {
    case 1:
        LlamarArrePreguntasFutbol(preguntas, respuestas);
        cout << endl;
        cout << "TEMA SELECCIONADO : FUTBOL" << endl;
        cout << endl;
        break;
    case 2:
        LlamarArrePreguntasMitologia(preguntas, respuestas);
        cout << endl;
        cout << "TEMA SELECCIONADO : MITOLOGIA" << endl;
        cout << endl;
        break;
    case 3:
        LlamarArrePreguntasGeografia(preguntas, respuestas);
        cout << endl;
        cout << "TEMA SELECCIONADO : GEOGRAFIA" << endl;
        cout << endl;
        break;
    case 4:
        LlamarArrePreguntasCultGeneral(preguntas, respuestas);
        cout << endl;
        cout << "TEMA SELECCIONADO : CULTURA GENERAL" << endl;
        cout << endl;
        break;
    }
    bool playerOneActive = true;
    bool playerTwoActive = true;
    for (int i = 0; i < Num_Preguntas; i++) // Definimos la cantidad de veces que se repetirá según la cantidad de preguntas
    {
        // Player One
        if (playerOneActive)
        {
            cout << endl;
            cout << "Pregunta numero " << i + 1 << " para el Jugador 1:" << endl;
            cout << preguntas[i] << endl;
            cout << endl;
            cout << "Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            cin >> Guardarespuesta;
            int OpcionCorrecta = stoi(respuestas[i]);
            if (Guardarespuesta == OpcionCorrecta)
            {
                RespCorrectasPlayerOne++;
                cout << endl;
                cout << "Correcto" << endl;
                cout << endl;
            }
            else
            {
                RespIncorrectasPlayerOne++;
                cout << endl;
                cout << "Incorrecto" << endl;
                cout << endl;
            }
            if (ConfOpcion == 2 && RespIncorrectasPlayerOne >= 3)
            {
                playerOneActive = false;
                cout << "Jugador 1 ha alcanzado el limite de respuestas incorrectas y no participara en la siguiente ronda." << endl 
                     << endl;
            }
        }
        // Player Two
        if (playerTwoActive)
        {
            cout << endl;
            cout << "Pregunta numero " << i + 1 << " para el Jugador 2:" << endl;
            cout << preguntas[i] << endl;
            cout << endl;
            cout << "Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            cin >> Guardarespuesta;
            int OpcionCorrecta = stoi(respuestas[i]);
            if (Guardarespuesta == OpcionCorrecta)
            {
                RespCorrectasPlayerTwo++;
                cout << endl;
                cout << "Correcto" << endl;
                cout << endl;
            }
            else
            {
                RespIncorrectasPlayerTwo++;
                cout << endl;
                cout << "Incorrecto" << endl;
                cout << endl;
            }
            if (ConfOpcion == 2 && RespIncorrectasPlayerTwo >= 3)
            {
                playerTwoActive = false;
                cout << endl;
                cout << "Jugador 2 ha alcanzado el limite de respuestas incorrectas y no participara en la siguiente ronda." << endl 
                     << endl;
            }
        }
        // Verificar si ambos jugadores han sido eliminados
        if (!playerOneActive && !playerTwoActive)
        {
            cout << "Ambos jugadores han alcanzado el limite de respuestas incorrectas. El juego ha terminado." << endl;
            break;
        }
    }
    puntuacionOneTemporales = RespCorrectasPlayerOne;
    puntuacionTwoTemporales = RespCorrectasPlayerTwo;

    EvaluarMultijugador();
}