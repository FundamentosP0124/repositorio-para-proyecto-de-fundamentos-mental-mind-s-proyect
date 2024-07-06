#include "iostream"
#include "cstdlib" //Para usar exit()
using namespace std;

/*Juego de trivia de preguntas al azar con 3 niveles de dificultad y un maximo de 3 equivocaciones
de acuerdo a la modalidad seleccionada del juego sin es por limites de inaciertos puntuacion final
segun si es el modo multijugador o de manera individual*/

void Menu();
void IniciarJuego();
void MostrarAyuda();
void RegistroDesarrolladores();
void TemasEvaluados();
bool Salir();

int main(void)
{
    Menu();

    return 0;
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
    cout << "Usted ha seleccionado la opcion Ayuda. Permitanos explicarte el funcionamiento del juego." << endl << endl; 
    cout << endl;
    cout << "Bienvenidos a TriviaZone!!! En este juego podras dar a relucir tus conocimientos sobre cualquier tema; en esta ocasion te presentaremos una cierta" << endl;
    cout << "cantidad de temas seleccionados por nosotros para que los disfrutes resolviendo intentando obtener la mayor cantidad de respuestas acertadas. " << endl << endl;
    
    cout << "A continuacion, te explicaremos brevemente de como funciona este juego de Preguntas y Respuestas. Esperamos que te guste :D ." << endl << endl;
    
    cout << "En TriviaZone hay dos modos para jugar, por lo tanto, cuando selecciones jugar el sistema te preguntara que tipo de modo te gustaria jugar. Existen" << endl;
    cout << "dos modos: El primero es el Modo Solitario donde el usuario seleccionara el tema a jugar por su cuenta con el objetivo de contestar la mayor cantidad" << endl;
    cout << "de preguntas presentadas durante el juego, el metodo de evaluacion sera que al final de la ronda de preguntas se llevara a cabo por medio de Insignias;" << endl;
    cout << "estas insignias se tratan de Enciclopedia Viviente (Para los jugadores que han demostrado un dominio excepcional de preguntas de trivia), Sabio en Progreso" << endl;
    cout << "(Para aquellos que estan comenzando a descubrir su potencial en trivia) y Rezagado del Saber (Para los jugadores que aun estan encontrando su camino en el mundo" << endl;
    cout << "de la trivia). Para obtener Enciclopedia Viviente necesitas tener mas de 10 preguntas acertadas, mientras tanto con Sabio en Progreso lo unico que necesitas es" << endl;
    cout << "tener 5 o mas preguntas acertadas, por ultimo, para obtener Rezagado del Saber necesitas haber obtenido solamente 4 preguntas acertadas. Esta explicacion es para" << endl;
    cout << "quienes gusten jugar en el Modo Solitario" << endl << endl;
    
    cout << "Para el segundo modo de juego se trata del Modo Multijugador donde se selecciona en numero de participantes y el tema a evaluar antes de empezar la trivia" << endl;
    cout << "de preguntas y respuestas. El metodo de evaluacion planteado conlleva de que los usuarios van contestando la ronda de preguntas por turnos segun el numero" << endl;
    cout << "de participantes que van a jugar, cada pregunta valdra un punto y dentro de esas 15 preguntas va haber una que valdra 3 puntos (se le conocera como punto" << endl;
    cout << "dorado); cuando todos los usuarios hayan terminado la ronda de preguntas, al final se mostrara una clasificacion de los mejores en el podio, el usuario" << endl;
    cout << "ganador sera el que obtenga el mayor de puntos conseguidos en el preguntas y respuestas de TriviaZone." << endl << endl;
    
    cout << "Basicamente de esto trata el juego, esperamos que lo disfrutes.";
    cout << endl;
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
    cout << "  Casco Miranda, Hector Enrique      00141124" << endl;
    cout << "  De la O Ortiz, Cesar Daniel        00205824" << endl;
    cout << "  Aquino Figueroa, Rodrigo Javier    00024524" << endl;
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