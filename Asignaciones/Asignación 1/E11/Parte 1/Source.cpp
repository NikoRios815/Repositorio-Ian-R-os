/*
	Incluimos las librerías necesarias para el programa que desarrollaremos.
*/
#include <iostream>
#include <vector>
#include <stdlib.h> 

//Agregamos la librería time para generar distintos "seeds" para rand().
#include <time.h>


// Librerías para manejar el tiempo. 
#include <chrono>
#include <thread>

/*
	Hacemos la declaración para el uso del namespace std.
*/
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//funcion que se encarga de imprimir el menu por cada iteracion
void printmenu() {
	system("cls");
	cout << "Presione m para minar" << endl;
	cout << "Presione h para recoger hoja" << endl;
	cout << "Presione i para mostrar el inventario" << endl;
	cout << "Escriba exit o presione 0 para salir" << endl;
};

/*
	Creamos el main del programa.
*/
int main() {
	//string que controla la opcion que elige el jugador
	string playeroption = "NA";

	//vector que contiene todos los minerales
	vector<string> mineral = { "Cristal Azul(A)", "Cristal Verde(V)" };

	//vector que contiene todas las hojas
	vector<string> hoja = { "Verila Pluma(VP)", "Secta Doralis(SD)", "Crystalia Fulminis" };

	//Vectores que controlan el inventario del jugador
	vector<string> inv_mineral;
	vector<string> inv_hoja;

	//do que controla las opciones del menu
	do {
		printmenu();
		cin >> playeroption;

		if (playeroption == "m" || playeroption == "M") {

			if (inv_mineral.size() < 3) {
				//mensaje de minando por 1 segundo
				cout << "Minando. ";
				sleep_for(milliseconds(500));
				cout << ". ";
				sleep_for(milliseconds(500));
				cout << ".\n\n";
				//aqui es donde se agrega un espacio al vector para introducir un nuevo elemento
				inv_mineral.push_back(mineral[rand() % 2]);
				//esto imprime los espacios restantes
				cout << "Espacio restante: " << 3 - inv_mineral.size() << endl;

			}

			system("pause");
		}
		else if (playeroption == "h" || playeroption == "H") {

			if (inv_hoja.size() < 5) {
				//mensaje de recogiendo por 1 segundo
				cout << "Recogiendo. ";
				sleep_for(milliseconds(500));
				cout << ". ";
				sleep_for(milliseconds(500));
				cout << ".\n\n";
				//aqui es donde se agrega un espacio al vector para introducir un nuevo elemento
				inv_hoja.push_back(hoja[rand() % 3]);
				//esto imprime los espacios restantes
				cout << "Espacio restante: " << 5 - inv_hoja.size() << endl;
			}

			system("pause");

		}
		else if (playeroption == "i" || playeroption == "I") {
			//Minerales
			if (inv_mineral.size() == 3) {
				cout << "Minerales:" << endl;
				cout << inv_mineral[0] << endl;
				cout << inv_mineral[1] << endl;
				cout << inv_mineral[2] << endl;
			}
			else if (inv_mineral.size() == 2) {
				cout << "Minerales:" << endl;
				cout << inv_mineral[0] << endl;
				cout << inv_mineral[1] << endl;
				cout << "1 espacio restante" << endl;
			}
			else if (inv_mineral.size() == 1) {
				cout << "Minerales:" << endl;
				cout << inv_mineral[0] << endl;
				cout << "2 espacios restantes" << endl;
			}
			else if (inv_mineral.size() == 0) {
				cout << "No se tiene ningun mineral en posesion (3 espacios restantes)" << endl;
			}

			//Hojas
			if (inv_hoja.size() == 5) {
				cout << "Hojas:" << endl;
				cout << inv_hoja[0] << endl;
				cout << inv_hoja[1] << endl;
				cout << inv_hoja[2] << endl;
				cout << inv_hoja[3] << endl;
				cout << inv_hoja[4] << endl;
			}
			else if (inv_hoja.size() == 4) {
				cout << "Hojas:" << endl;
				cout << inv_hoja[0] << endl;
				cout << inv_hoja[1] << endl;
				cout << inv_hoja[2] << endl;
				cout << inv_hoja[3] << endl;
				cout << "1 espacio restante" << endl;
			}
			else if (inv_hoja.size() == 3) {
				cout << "Hojas:" << endl;
				cout << inv_hoja[0] << endl;
				cout << inv_hoja[1] << endl;
				cout << inv_hoja[2] << endl;
				cout << "2 espacios restantes" << endl;
			}
			else if (inv_hoja.size() == 2) {
				cout << "Hojas:" << endl;
				cout << inv_hoja[0] << endl;
				cout << inv_hoja[1] << endl;
				cout << "3 espacios restantes" << endl;
			}
			else if (inv_hoja.size() == 1) {
				cout << "Hojas:" << endl;
				cout << inv_hoja[0] << endl;
				cout << "4 espacios restantes" << endl;
			}
			else if (inv_mineral.size() == 0) {
				cout << "No se tiene ninguna hoja en posesion (5 espacios restantes)" << endl;
			}
			system("pause");
		}
		else if (playeroption == "exit" || playeroption == "0") {

		}


	} while (playeroption != "exit" && playeroption != "0");

}