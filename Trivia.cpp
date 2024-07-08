#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

const int Num_Preguntas = 15;

// DECLARACIONES

void menu();
int cantidadJugadores(int);
int SelecionTemas(int);
void temas();
int ModalidadJuego(int);
void LlamarArrePreguntasFutbol(string, string);
int ValidarNumeros();
string ValidarEntradasText();
int validarNumeroRango(int, int);
void LlamarArrePreguntasMitologia(string, string);
void LlamarArrePreguntasGeografia(string, string);
void LlamarArrePreguntasCultGeneral(string, string);
void registrarJugadores(string[], int &);

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
    string confirmacion;

    // Almacenar mensajes para evitar repetirlos
    string mensajeOne = "¿Esta seguro de: 1 - '1' jugador";
    string mensajeTwo = "¿Esta seguro de: 2 - '2' jugadores";
    string mensajeThree = "Presione 's' para confirmar, 'n' para cambiar la cantidad de jugadores.";

    // Realizamos la confirmación
    while (true)
    {
        // Leemos la entrada
        cout << "1 - Solo '1' jugador." << endl;
        cout << "2 - De '2' jugadores." << endl;

        Cant = ValidarNumeros();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Llama a la funcion de validacion para obtener un numero valido

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

        confirmacion = ValidarEntradasText();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirmacion == "s" || confirmacion == "S")
        {
            break; // Salir del bucle si la confirmacion es 's' o 'S'
        }
    }

    return Cant;
}

void registrarJugadores(string guardarNombres[], int &cantidadActual)
{
    int cantidad = 0;
    cantidadJugadores(cantidad);

    cout << "Para registrar tu alias, puedes ocupar letras, números y símbolos" << endl
         << endl;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Registra tu alias";
        if (cantidad > 1)
        {
            cout << " (" << i + 1 << ")";
        }
        cout << ": ";
        cin >> guardarNombres[cantidadActual + i];
    }

    cantidadActual += cantidad; // Actualizar la cantidad actual de jugadores
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

void LlamarArrePreguntasFutbol(string (&enviarPreguntas)[Num_Preguntas], string (&enviarRespuestas)[Num_Preguntas])
{
    string arrePreguntas[Num_Preguntas] = {
        "¿En que pais se jugo la primera copa del mundo de la fifa?\n1) Argentina\n2) Uruguay\n3) Inglaterra",                                                  // 1
        "A la fecha, ¿Quién es el máximo goleador de todos los tiempos en la historia de la copa del mundo?\n1) Misrolav\n2) Ronaldo Nazarino\n3) Gerd Muller", // 2
        "Pele gano 3 copas del mundo\n1) Verdadero\n2) Falso",                                                                                                  // 3
        "¿En qué país se inventó el futbol moderno?\n1) Brasil\n2) España\n3) Inglaterra",                                                                      // 4
        "Cristiano Ronaldo hizo su debut oficial en el real Madrid con el numero 19. \n1) Verdadero\n2) Falso",                                                 // 5
        "¿En qué año se fundó la FIFA? \n1) 1910\n2) 1904\n3) 1901",                                                                                            // 6
        "Brasil es la única selección que ha participado en todas las ediciones de la copa del mundo. \n1) Verdadero\n2) Falso",                                // 7
        "¿Quién ganó el premio al mejor jugador de la FIFA en 2020? \n1) Lionel Messi\n3) Robert Lewandoski\n3) Luca Modric",                                   // 8
        "Canada es uno de los países que desarrollara la copa del mundo 2026. \n1) Verdadero\n2) Falso",                                                        // 9
        "¿Cuál es el club de futbol que ha ganado más veces la UEFA champions league?\n1) Barcelona\n2) Bayern de munich\n3) Real Madrid cf",                   // 10
        "Italia gano la copa del mundo del 2006\n1) Verdadero\n2) Falso",                                                                                       // 11
        "¿En que año se jugo la primera copa del mundo de la fifa?\n1) 1930\n2) 1926\n3) 1934",                                                                 // 12
        "La primera edición de la UEFA champions league se realizo en 1959\n1) Verdadero\n2) Falso",                                                            // 13
        "¿Quién es el máximo ganador del balón de oro de la historia?\n1) Lionel Messi\n2) Cristiano Ronaldo\n3) Vinicius Junior",                              // 14
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
        "¿Quién es el dios del trueno en la mitología nórdica?\n1) Loki\n2) Thor\n3) Odin\n4) Balder",                                                              // 1
        "¿Cómo se llama el caballo de ocho patas de Odin en la mitología nórdica?\n1) Fenrir\n2) Jormungandr\n3) Garm\n4) Sleipnir",                                // 2
        "¿Qué héroe griego completó los Doce Trabajos?\n1) Perseo\n2) Teseo\n3) Hércules\n4) Aquiles",                                                              // 3
        "¿Cuál es el nombre del lobo gigante que está destinado a matar a Odin durante el Ragnarök?\n1) Fenrir\n2) Garm\n3) Skoll\n4) Hati",                        // 4
        "¿Cuál de las siguientes diosas griegas es la diosa de la sabiduría?\n1) Hera\n2) Atenea\n3) Afrodita\n4) Deméter",                                         // 5
        "¿Cuál es el nombre del puente que conecta Asgard con el mundo de los humanos en la mitología nórdica?\n1) Yggdrasil\n2) Bifröst\n3) Valhalla\n4) Mjolnir", // 6
        "¿Quién es el dios de la luz y la belleza, asesinado por una flecha de muérdago en la mitología nórdica?\n1) Tyr\n2) Frey\n3) Balder\n4) Vidar",            // 7
        "¿Cuál es el nombre del titán griego que sostiene el cielo sobre sus hombros?\n1) Cronos\n2) Atlas\n3) Prometeo\n4) Oceanus",                               // 8
        "¿Quién es la diosa del amor y la belleza en la mitología griega?\n1) Hera\n2) Atenea\n3) Afrodita\n4) Artemisa",                                           // 9
        "¿Quién es el dios del fuego y la forja en la mitología griega?\n1) Hefesto\n2) Tyr\n3) Heimdall\n4) Freyr",                                                // 10
        "¿Cómo se llama el martillo de Thor en la mitología nórdica?\n1) Gungnir\n2) Mjolnir\n3) Brisingamen\n4) Gram",                                             // 11
        "¿Quién es el mensajero de los dioses en la mitología griega?\n1) Ares\n2) Hermes\n3) Apolo\n4) Dionisio",                                                  // 12
        "¿Quién es el dios del sol en la mitología griega?\n1) Hades\n2) Apolo\n3) Dionisio\n4) Poseidón",                                                          // 13
        "¿Qué animal persigue continuamente al sol y la luna en la mitología nórdica?\n1) Lobos\n2) Cuervos\n3) Serpientes\n4) Dragones",                           // 14
        "¿Cómo se llama el gigante que guarda la entrada al reino de los muertos en la mitología nórdica?\n1) Ymir\n2) Hel\n3) Garm\n4) Surtr"};                    // 15

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
        "¿Cuál es el país más grande del mundo en términos de superficie?\n1) Canadá\n2) China\n3) Rusia\n4) Estados Unidos",                        // 1
        "¿Cuál es el río más largo del mundo?\n1) Nilo\n2) Amazonas\n3) Yangtsé\n4) Misisipi",                                                       // 2
        "¿En qué continente se encuentra el desierto del Sahara?\n1) Asia\n2) África\n3) América del Sur\n4) Oceanía",                               // 3
        "¿Cuál es la capital de Japón?\n1) Beijing\n2) Seúl\n3) Tokyo\n4) Bangkok",                                                                  // 4
        "¿Cuál es el país más pequeño del mundo en términos de superficie?\n1) Mónaco\n2) San Marino\n3) Liechtenstein\n4) Ciudad del Vaticano",     // 5
        "¿Cuál es el país más grande de América del Sur por superficie?\n1) Argentina\n2) Brasil\n3) Perú\n4) Colombia",                             // 6
        "¿Cuál es la capital de Canadá?\n1) Toronto\n2) Vancouver\n3) Ottawa\n4) Montreal",                                                          // 7
        "¿Cuál es el país más poblado del mundo?\n1) India\n2) Estados Unidos\n3) Indonesia\n4) China",                                              // 8
        "¿Qué país está completamente rodeado por Sudáfrica?\n1) Suazilandia\n2) Lesoto\n3) Botsuana\n4) Namibia",                                   // 9
        "¿Cuál es la capital de Australia?\n1) Sídney\n2) Melbourne\n3) Canberra\n4) Brisbane",                                                      // 10
        "¿Qué país tiene la mayor cantidad de islas?\n1) Indonesia\n2) Filipinas\n3) Noruega\n4) Suecia",                                            // 11
        "¿Cuál es el lago más profundo del mundo?\n1) Lago Baikal\n2) Lago Tanganica\n3) Lago Superior\n4) Lago Victoria",                           // 12
        "¿En qué país se encuentra el Monte Kilimanjaro?\n1) Kenia\n2) Tanzania\n3) Uganda\n4) Etiopía",                                             // 13
        "¿Cuál es el desierto más grande del mundo?\n1) Desierto del Gobi\n2) Desierto de Arabia\n3) Desierto del Kalahari\n4) Desierto del Sahara", // 14
        "¿Cuál es la cordillera más larga del mundo?\n1) Montañas Rocosas\n2) Andes\n3) Alpes\n4) Himalayas"                                         // 15
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
        "¿Cuál es el nombre del tratado que puso fin a la Primera Guerra Mundial?\n1) Tratado de Versalles\n2) Tratado de París\n3) Tratado de Tordesillas\n4) Tratado de Ginebra",                            // 1
        "¿Cuál es el país con la mayor cantidad de volcanes activos?\n1) Japón\n2) Indonesia\n3) Islandia\n4) Italia",                                                                                         // 2
        "¿Qué artista es conocido por cortar su propia oreja?\n1) Pablo Picasso\n2) Salvador Dalí\n3) Vincent van Gogh\n4) Claude Monet",                                                                      // 3
        "¿Cuál es el órgano más grande del cuerpo humano?\n1) Corazón\n2) Hígado\n3) Piel\n4) Pulmones",                                                                                                       // 4
        "¿Cuál es la ciudad más antigua continuamente habitada del mundo?\n1) Jerusalén\n2) Atenas\n3) Damasco\n4) Roma",                                                                                      // 5
        "¿Cuál es el nombre del proceso por el cual las plantas convierten la luz solar en energía?\n1) Respiración\n2) Fermentación\n3) Fotosíntesis\n4) Metabolismo",                                        // 6
        "¿Cuál es el libro sagrado del Islam?\n1) La Biblia\n2) El Talmud\n3) El Corán\n4) Los Vedas",                                                                                                         // 7
        "¿Cuál es el país más joven del mundo, habiéndose independizado en 2011?\n1) Timor Oriental\n2) Montenegro\n3) Kosovo\n4) Sudán del Sur",                                                              // 8
        "¿Qué movimiento artístico surgió a principios del siglo XX y es conocido por sus formas geométricas y su enfoque en la abstracción?\n1) Impresionismo\n2) Expresionismo\n3) Cubismo\n4) Surrealismo", // 9
        "¿Cuál es el idioma más hablado en el mundo?\n1) Inglés\n2) Español\n3) Chino mandarín\n4) Árabe",                                                                                                     // 10
        "¿En qué año llegó el hombre a la Luna por primera vez?\n1) 1965\n2) 1969\n3) 1972\n4) 1959",                                                                                                          // 11
        "¿Cuál es la moneda oficial de Japón?\n1) Yuan\n2) Won\n3) Yen\n4) Dólar",                                                                                                                             // 12
        "¿En qué país se encuentra la ciudad de Petra?\n1) Jordania\n2) Egipto\n3) Turquía\n4) Grecia",                                                                                                        // 13
        "¿Cuál es el elemento químico más abundante en el universo?\n1) Helio\n2) Oxígeno\n3) Hidrógeno\n4) Carbono",                                                                                          // 14
        "¿Quién pintó 'La última cena'?\n1) Pablo Picasso\n2) Leonardo da Vinci\n3) Vincent van Gogh\n4) Claude Monet"                                                                                         // 15
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

    int ConfOpcion = 0, temaSELECCIONADO = 0;

    int RespCorrectas = 0, RespIncorrectas = 0;

    // Importaciones para configurar las modalidades del juego
    ModalidadJuego(ConfOpcion);
    SelecionTemas(temaSELECCIONADO);

    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];

    // Importar las funciones que contienen las preguntas y respuestas
    switch (temaSELECCIONADO)
    {
    case 1:
        LlamarArrePreguntasCultGeneral(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : CULTURA GENERAL" << endl;
        cout << endl;
        break;
    case 2:
        LlamarArrePreguntasFutbol(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : FUTBOL" << endl;
        cout << endl;
        break;
    case 3:
        LlamarArrePreguntasGeografia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : GEOGRAFIA" << endl;
        cout << endl;
        break;
    case 4:
        LlamarArrePreguntasMitologia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : MITOLOGIA" << endl;
        cout << endl;
        break;
    }

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
    cout << "Resultados" << endl;

    return RespCorrectas; // Devolver la cantidad de respuestas correctas e incorrectas que obtuvo
}

int multijugador(int RespCorrectasPlayerOne, int RespCorrectasPlayerTwo) // Retornamos una instancia a la estructura resultados de ambos jugadores
{
    int RespIncorrectasPlayerOne = 0, RespIncorrectasPlayerTwo = 0;

    int ConfOpcion = 0, temaSELECCIONADO = 0;

    string preguntas[Num_Preguntas];
    string respuestas[Num_Preguntas];

    // Importaciones para configurar las modalidades del juego
    ModalidadJuego(ConfOpcion);
    SelecionTemas(temaSELECCIONADO);

    // Importar las funciones que contienen las preguntas y respuestas
    switch (temaSELECCIONADO)
    {
    case 1:
        LlamarArrePreguntasCultGeneral(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : CULTURA GENERAL" << endl;
        break;
    case 2:
        LlamarArrePreguntasFutbol(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : FUTBOL" << endl;
        break;
    case 3:
        LlamarArrePreguntasGeografia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : GEOGRAFIA" << endl;
        break;
    case 4:
        LlamarArrePreguntasMitologia(preguntas, respuestas);
        cout << "TEMA SELECCIONADO : MITOLOGIA" << endl;
        break;
    }

    bool playerOneActive = true;
    bool playerTwoActive = true;

    for (int i = 0; i < Num_Preguntas; i++) // Definimos la cantidad de veces que se repetirá según la cantidad de preguntas
    {
        // Player One
        if (playerOneActive)
        {
            cout << "Pregunta numero " << i + 1 << " para el Jugador 1:" << endl;
            cout << preguntas[i] << endl;

            cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            int Guardarespuesta = ValidarNumeros();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int OpcionCorrecta = stoi(respuestas[i]);

            if (Guardarespuesta == OpcionCorrecta)
            {
                RespCorrectasPlayerOne++;
                cout << "Correcto" << endl;
            }
            else
            {
                RespIncorrectasPlayerOne++;
                cout << "Incorrecto" << endl;
            }

            if (ConfOpcion == 2 && RespIncorrectasPlayerOne >= 3)
            {
                playerOneActive = false;
                cout << "Jugador 1 ha alcanzado el limite de respuestas incorrectas y no participara en la siguiente ronda." << endl;
            }
        }

        // Player Two
        if (playerTwoActive)
        {
            cout << "Pregunta numero " << i + 1 << " para el Jugador 2:" << endl;
            cout << preguntas[i] << endl;

            cout << "¿Cual es tu respuesta? (Ingresa el numero de la opcion): ";
            int Guardarespuesta = ValidarNumeros();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int OpcionCorrecta = stoi(respuestas[i]);

            if (Guardarespuesta == OpcionCorrecta)
            {
                RespCorrectasPlayerTwo++;
                cout << "Correcto" << endl;
            }
            else
            {
                RespIncorrectasPlayerTwo++;
                cout << "Incorrecto" << endl;
            }
            if (ConfOpcion == 2 && RespIncorrectasPlayerTwo >= 3)
            {
                playerTwoActive = false;
                cout << "Jugador 2 ha alcanzado el limite de respuestas incorrectas y no participará en la siguiente ronda." << endl;
            }
        }

        // Verificar si ambos jugadores han sido eliminados
        if (!playerOneActive && !playerTwoActive)
        {
            cout << "Ambos jugadores han alcanzado el limite de respuestas incorrectas. El juego ha terminado." << endl;
            break;
        }
    }
}
