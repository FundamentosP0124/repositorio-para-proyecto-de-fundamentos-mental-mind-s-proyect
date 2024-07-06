#include <iostream>

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
}