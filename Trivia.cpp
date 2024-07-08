#include "iostream"
#include "cstdlib" //Para usar exit()
#include "string"
using namespace std;

/*Juego de trivia de preguntas al azar con 3 niveles de dificultad y un maximo de 3 equivocaciones
de acuerdo a la modalidad seleccionada del juego sin es por limites de inaciertos puntuacion final
segun si es el modo multijugador o de manera individual*/

void Menu();
void IniciarJuego();
void MostrarAyuda();
void RegistroDesarrolladores();
void TemasEvaluados();
void imprimirParrafo(const string& parrafo);
bool Salir();
void registrarDatos(const string &, int);
void mostrarDatos();


int main(void)
{
    Menu();

    return 0;
}

void imprimirParrafo(const string& parrafo) {
    cout << parrafo << endl;
}

void Menu() {
    int opcion;

    do {
        

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
        cout << "5. Salir" << endl;
        cout << "============================" << endl;
        cout << endl;

        cout << "Ingrese la opcion a realizar: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
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
                if (Salir()) {
                    exit(0);
                }
                break;
            default:
                cout << "La opcion registrada no es valida. Por favor seleccione nuevamente." << endl;
                break;
            }
        } while(true);
}

void MostrarAyuda() {
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

void RegistroDesarrolladores() {
    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Creditos/Desarrolladores. Echemos un vistazo de los creadores de este juego!!!" << endl << endl;
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

void TemasEvaluados() {
    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Temas de las Preguntas. Vamos a ver cuales son las tematicas evaluadas en esta Trivia." << endl << endl;
    cout << endl;
    cout << "Bienvenidos al apartado de Temas Evaluados en TriviaZone!!! En esta seccion solo te mostraremos los temas a evaluar en esta Trivia" << endl;
    cout << "para que puedas tener la mente en claro sobre las preguntas definidas que te apareceran segun la seccion que tu elijas." << endl;
    cout << "A continuacion, te presentamos los 4 temas evaluados en TriviaZone:" << endl << endl;
    cout << "1- Futbol" << endl;
    cout << "2- Mitologia" << endl;
    cout << "3- Geografia/Paises" << endl;
    cout << "4- Cultura General" << endl << endl << endl;
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

bool Salir() {
    system("clear||cls");
    int opcionS;

    cout << "Estas seguro de terminar el juego?" << endl << endl;
    cout << "Presiona 1 para salir o 0 para continuar: ";
    
    do {
        cin >> opcionS;  // Leer la opción del usuario

        switch(opcionS) {
            case 1:
                cout << endl;
                cout << "Usted ha seleccionado la opcion Salir. See you next time Triviano!!!" << endl << endl;
                return true; // Termina el programa 
                break;
            case 0:
                cout << "Continuando el juego..." << endl;
                return false;
                break;
            default:
                cout << "Opcion inexistente. Intente nuevamente: ";
                break;
        }
    } while (opcionS != 1);  // Salir del bucle cuando la opción sea válida

    return false;
}

void IniciarJuego() {
    system("clear||cls");
    cout << endl;
    cout << "Usted ha seleccionado la opcion Jugar. Disfrute de TriviaZone!!!" << endl << endl;
    // Aquí irá el funcionamiento del juego

    char salir;

    cout << "Presiona 's' o 'S' para regresar al menu principal..." << endl;
    cin >> salir;
    
    if (salir == 's' || salir == 'S')
    {
        system("clear||cls");
        Menu();
    }
}