// Importamos las librerías necesarias para el programa. 
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<ctime>

// Incluimos el namespace std. 
using namespace std;

//Declaramos las funciones que usaremos en este programa. 
vector<string> generateInventory();
bool uniqueCrystalVerification(vector<string> itemList);
vector<string> openInventory(vector<string> inventory);
vector<string> opaqueCraftMenu(vector<string> inventory);
bool createOpaque(string rawCrystal, vector<string> inventory);
vector<string> replace(string rawCrystal, string opaqueCrystal, vector<string> inventory);

//Definimos una variable que nos diga si hay un cristal presente en el inventario.
bool containsCrystal = false;

//Pointer que apunta a la direccion de memoria donde se guarda el bool containsCrystal
bool *contcrystal_dir = &containsCrystal;

//Creamos un vector con todos los objetos posibles. 
vector<string> allItems = { "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash", "Fishermen's Plate", "Iron Plate" };

//Escribimos el cuerpo de la función generateInventory().
vector<string> generateInventory()
{

	//Declaramos un inventario (local).
	vector<string> randomInventory(20, "NA");

	//Definimos las variables para el uso del rand().
	int randomItemPos;
	int min = 0;
	int max = allItems.size() - 1;

	//Declaramos una variable booleana, "longBooleanExpression". Para el control de cristales únicos. 
	bool longBooleanExpression;

	//Declaramos una variable booleana para el control de Fishermen's Plates.
	bool shortBooleanExpression;

	//Declaramos una variable contador para el ciclo while. 
	int counter = 0;

	//Creamos el ciclo que llena el inventario "random". 
	while (counter < 7) {

		//Generamos la posición "random".
		randomItemPos = rand() % (max - min + 1) + min;

		//Usando la función uniqueCrystalVerification, verificamos si hay un cristal en el inventario.
		*contcrystal_dir = uniqueCrystalVerification(randomInventory);

		//Si hay el item random escogido es un cristal y HAY un cristal presente en el inventario, entonces esta expresión tomará el valor de true. 
		longBooleanExpression = ((allItems[randomItemPos] == "Crystallized Azure Dragon's Tears") || (allItems[randomItemPos] == "Crystallized Exiled Heretic's Bone") || (allItems[randomItemPos] == "Crystallized Great Feline's Ash")) && containsCrystal;

		//Si hay tres o más Fisherme's Plate en el inventario Y el item random es un Fisherme's Plate, esta variable tomará el valor de true. 
		shortBooleanExpression = (count(randomInventory.begin(), randomInventory.end(), "Fishermen's Plate") >= 3) && (allItems[randomItemPos] == "Fishermen's Plate");

		//Si no hay cristal, entonces se puede agregar cualquier cosa al inventario.
		if (!longBooleanExpression && !shortBooleanExpression) {

			randomInventory[counter] = allItems[randomItemPos];
			counter++; //El counter solo se aumenta cuando se haya agregado algo al inventario. 

		}
	}

	system("CLS");
	cout << "INVENTORY GENERATED! \n\n" << endl;
	system("pause"); //Para esperar que el usuario presione alguna tecla. 

	return randomInventory;

}

//Creamos una función que verifique si ya existe un cristal en la lista pasada como argumento. 
bool uniqueCrystalVerification(vector<string> itemList)
{

	//Declaramos una variable counter por motivos prácticos. 
	int counter = 0;

	//Declaramos una variable que "diga" si hay un cristal en la lista pasada. 
	bool isCrystalPresent = false;

	//Declaramos el "longBooleanExpression". 
	bool longBooleanExpression;

	//Creamos el ciclo que verifica si hay un cristal en el vector (en la lista).
	while ((counter < itemList.size()) && (!isCrystalPresent)) {

		//Verificamos si hay alguno de los cristales en la lista de objetos. 
		longBooleanExpression = (itemList[counter] == "Crystallized Azure Dragon's Tears") || (itemList[counter] == "Crystallized Exiled Heretic's Bone") || (itemList[counter] == "Crystallized Great Feline's Ash");

		//Si hay un cristal, entonces cambiamos el valor de "isCrystalPresent" a "true".
		if (longBooleanExpression) {
			isCrystalPresent = true;
		}

		//Aumentamos el counter (ya que el while no lo hace solo).
		counter++;

	}

	return isCrystalPresent;

}

//Creamos una función para ver el inventario y tirar objetos del mismo. 
vector<string> openInventory(vector<string> inventory)
{

	//Declaramos la variable que mantiene el inventario abierto. 
	bool inventoryOpened = true;

	//variable que recibe un valor del usuario para decidir si va a eliminar un cristal o no
	int op;

	//Declaramos la variable para la entrada del usuario. 
	int userInput;

	//Creamos el ciclo que nos mantiene el inventario abierto. 
	while (inventoryOpened) {

		//Encabezado. 
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << "\n" << endl;

		//Creamos el ciclo que itera sobre el inventario para imprimirlo (mostrarlo en pantalla).
		for (int counter = 0; counter < inventory.size(); counter++) {

			cout << counter + 1 << ". " << inventory[counter] << endl;

		}

		//Creamos la opción EXIT.
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;

		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> userInput;

		//Si el usuario introduce el número de algún item, entonces borra el item usando erase(). De otra forma, cierra el inventory. 
		if (userInput <= inventory.size()) {
			if (inventory[userInput - 1] != "Crystallized Azure Dragon's Tears" && inventory[userInput - 1] != "Crystallized Exiled Heretic's Bone" && inventory[userInput - 1] != "Crystallized Great Feline's Ash") {
				inventory.erase(inventory.begin() + userInput - 1);
			}
			else {
				cout << "Are you sure you want to destroy this crystal? You won’t be able to gather this unique crystal anymore." << endl;
				cout << "Introduce 1 to accept, press any other number to cancel." << endl;
				cin >> op;
				if (op == 1) {
					*contcrystal_dir = false;
					if (inventory[userInput - 1] == "Crystallized Azure Dragon's Tears") {

						for (int i = 0; i < allItems.size(); i++) {
							if (allItems[i] == "Crystallized Azure Dragon's Tears") {
								allItems.erase(allItems.begin() + i);
							}
						}
						inventory.erase(inventory.begin() + userInput - 1);
					}
					else if (inventory[userInput - 1] == "Crystallized Exiled Heretic's Bone") {

						for (int i = 0; i < allItems.size(); i++) {
							if (allItems[i] == "Crystallized Exiled Heretic's Bone") {
								allItems.erase(allItems.begin() + i);
							}
						}
						inventory.erase(inventory.begin() + userInput - 1);
						system("pause");

					}
					else if (inventory[userInput - 1] == "Crystallized Great Feline's Ash") {

						for (int i = 0; i < allItems.size(); i++) {
							if (allItems[i] == "Crystallized Great Feline's Ash") {
								allItems.erase(allItems.begin() + i);
							}
						}
						inventory.erase(inventory.begin() + userInput - 1);
						system("pause");


					}
				}
			}

		}
		else if (userInput == inventory.size() + 1) {

			inventoryOpened = false;

		}

	}

	return inventory;

}

vector<string> opaqueCraftMenu(vector<string> inventory)
{

	//Declaro la variable que mantiene el inventario abierto.
	bool craftMenuOpen = true;

	//Declaro la variable para la entrada del usuario
	int craftMenuOption;

	while (craftMenuOpen) {

		//Declaro dos variables que serán útiles para "craftear" los items. 
		string rawCrystal = "NA";
		string opaqueCrystal = "NA";

		//Declaro la variable para saber si se puede crear el cristal deseado. 
		bool isCrafted = false;

		//Creamos el UI.
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = OPAQUE CRYSTAL CRAFTING = =" << "\n" << endl;
		cout << "1. Opaque Azure Dragon's Sapphire" << endl;
		cout << "2. Opaque Humanity's Emerald" << endl;
		cout << "3. Opaque Feline's Ruby" << endl;
		cout << "4. Exit" << endl;
		cout << "===============================================================" << endl;

		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> craftMenuOption;

		//Controlamos el menú usando un switch. 
		switch (craftMenuOption) {

		case 1:
			rawCrystal = "Crystallized Azure Dragon's Tears";
			opaqueCrystal = "Opaque Azure Dragon's Sapphire";
			isCrafted = createOpaque(rawCrystal, inventory);
			break;

		case 2:
			rawCrystal = "Crystallized Exiled Heretic's Bone";
			opaqueCrystal = "Opaque Humanity's Emerald";
			isCrafted = createOpaque(rawCrystal, inventory);
			break;

		case 3:
			rawCrystal = "Crystallized Great Feline's Ash";
			opaqueCrystal = "Opaque Feline's Ruby";
			isCrafted = createOpaque(rawCrystal, inventory);
			break;

		case 4:
			craftMenuOpen = false;
			break;

		default:
			system("CLS");
			break;
		}

		//Solo hará el cambio al inventario si se ha creado algo.
		if (isCrafted) {

			inventory = replace(rawCrystal, opaqueCrystal, inventory);
			cout << "Opaque crystal crafted!" << endl;
			system("pause");

		}

	}

	return inventory;

}

//Funcion encargada del menu de recolección
vector<string> recolectmenu(vector<string> inventory)
{

	//Declaro la variable que mantiene el inventario abierto.
	bool recolectMenuOpen = true;

	//Declaro la variable para la entrada del usuario
	int recolectMenuOption;

	while (recolectMenuOpen) {

		//Declaro dos variables que serán útiles para "craftear" los items. 
		string rawCrystal = "NA";
		string opaqueCrystal = "NA";

		//Declaro la variable para saber si se puede recoger el objeto. 
		bool iteminv = false;
		bool iteminv1 = false;
		bool iteminv2 = false;
		bool iteminv3 = false;
		bool iteminv4 = false;

		string item1 = allItems[rand() % allItems.size()];
		string item2 = allItems[rand() % allItems.size()];
		string item3 = allItems[rand() % allItems.size()];
		string item4 = allItems[rand() % allItems.size()];
		string item5 = allItems[rand() % allItems.size()];

		//Creamos el UI.
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = RECOLECT MENU = =" << "\n" << endl;
		cout << "1. " << item1 << endl;
		cout << "2. " << item2 << endl;
		cout << "3. " << item3 << endl;
		cout << "4. " << item4 << endl;
		cout << "5. " << item5 << endl;
		cout << "6. Exit" << endl;
		cout << "===============================================================" << endl;

		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> recolectMenuOption;

		//Controlamos el menú usando un switch. 
		switch (recolectMenuOption) {

		case 1:
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i] == "NA" && iteminv == false) {
					//If que se encarga de revisar si ya hay un cristal en el inventario para no agarrar otro	
					if (item1 != "Crystallized Azure Dragon's Tears" && item1 != "Crystallized Exiled Heretic's Bone" && item1 != "Crystallized Great Feline's Ash") {
						inventory[i] = item1;
						iteminv = true;
					}
					else {
						if (*contcrystal_dir == true) {
							if (i == inventory.size() - 1) {
								cout << "You can't grab this item because you already have a crystal" << endl;
								system("pause");
							}
							else {
								inventory[i] = item1;
								iteminv = true;
								*contcrystal_dir = true;
							}
						}
					}
				}
			}
			break;

		case 2:
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i] == "NA" && iteminv == false) {
					//If que se encarga de revisar si ya hay un cristal en el inventario para no agarrar otro	
					if (item2 != "Crystallized Azure Dragon's Tears" && item2 != "Crystallized Exiled Heretic's Bone" && item2 != "Crystallized Great Feline's Ash") {
						inventory[i] = item2;
						iteminv = true;
					}
					else {
						if (*contcrystal_dir == true) {
							if (i == inventory.size() - 1) {
								cout << "You can't grab this item because you already have a crystal" << endl;
								system("pause");
							}
						}
						else {
							inventory[i] = item2;
							iteminv = true;
							*contcrystal_dir = true;
						}
					}
				}
			}
			break;

		case 3:
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i] == "NA" && iteminv == false) {
					//If que se encarga de revisar si ya hay un cristal en el inventario para no agarrar otro	
					if (item3 != "Crystallized Azure Dragon's Tears" && item3 != "Crystallized Exiled Heretic's Bone" && item3 != "Crystallized Great Feline's Ash") {
						inventory[i] = item3;
						iteminv = true;
					}
					else {
						if (*contcrystal_dir == true) {
							if (i == inventory.size() - 1) {
								cout << "You can't grab this item because you already have a crystal" << endl;
								system("pause");
							}
						}
						else {
							inventory[i] = item3;
							iteminv = true;
							*contcrystal_dir = true;
						}
					}
				}
			}
			break;

		case 4:
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i] == "NA" && iteminv == false) {
					//If que se encarga de revisar si ya hay un cristal en el inventario para no agarrar otro	
					if (item4 != "Crystallized Azure Dragon's Tears" && item4 != "Crystallized Exiled Heretic's Bone" && item4 != "Crystallized Great Feline's Ash") {
						inventory[i] = item4;
						iteminv = true;
					}
					else {
						if (*contcrystal_dir == true) {
							if (i == inventory.size() - 1) {
								cout << "You can't grab this item because you already have a crystal" << endl;
								system("pause");
							}
						}
						else {
							inventory[i] = item4;
							iteminv = true;
							*contcrystal_dir = true;
						}
					}
				}
			}
			break;

		case 5:
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i] == "NA" && iteminv == false) {
					//If que se encarga de revisar si ya hay un cristal en el inventario para no agarrar otro	
					if (item5 != "Crystallized Azure Dragon's Tears" && item5 != "Crystallized Exiled Heretic's Bone" && item5 != "Crystallized Great Feline's Ash") {
						inventory[i] = item5;
						iteminv = true;
					}
					else {
						if (*contcrystal_dir == true) {
							if (i == inventory.size() - 1) {
								cout << "You can't grab this item because you already have a crystal" << endl;
								system("pause");
							}
						}
						else {
							inventory[i] = item5;
							iteminv = true;
							*contcrystal_dir = true;
						}
					}
				}
			}
			break;

		case 6:
			recolectMenuOpen = false;
			break;

		default:
			system("CLS");
			break;
		}


	}

	return inventory;

}

//Función que se encarga de verificar si existe el cristal adecuado en el inventario.
bool createOpaque(string rawCrystal, vector<string> inventory)
{

	bool isCrafted = false;

	if (find(inventory.begin(), inventory.end(), rawCrystal) != inventory.end()) {

		isCrafted = true;

	}

	return isCrafted;

}

//Función que se encarga de reemplazar el rawCrystal por el opaqueCrystal. 
vector<string> replace(string rawCrystal, string opaqueCrystal, vector<string> inventory) {

	int counter = 0;
	bool replaced = false;

	while (counter < inventory.size() && !replaced) {

		if (inventory[counter] == rawCrystal)
		{

			inventory[counter] = opaqueCrystal;
			replaced = true;

		}

		counter++;

	}

	return inventory;

}


int main()
{

	//RANDOM SEED.
	srand(time(0));

	//Creamos un vector para el inventario. 
	vector<string> inventory(10, "NA");

	//Creamos una variable bool para mantener el menú funcionando. 
	bool menuOpen = true;

	//Creamos una variable bool que revisa si se uso la opcion 1 
	bool generated = false;

	//Creamos la variable para la entrada del usuario. 
	int mainMenuOption;

	//Usamos un ciclo while para mantener el menú funcionando. 
	while (menuOpen) {

		//Este comando limpia la ventana de comandos. 
		system("CLS");

		//Creamos el "UI" para el menú.
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = =" << "\n" << endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. CREATE OPAQUE CRYSTAL" << endl;
		cout << "4. RECOLECT MENU (Can only be used after the inventory is generated)" << endl;
		cout << "5. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario. 
		cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;

		//Usamos un switch() para manejar el menú con la entrada del usuario.
		switch (mainMenuOption) {

		case 1:
			inventory = generateInventory();
			generated = true;
			break;

		case 2:
			inventory = openInventory(inventory);
			break;

		case 3:
			inventory = opaqueCraftMenu(inventory);
			break;

		case 4:
			if (generated == true) {
				inventory = recolectmenu(inventory);
			}
			break;

		case 5:
			menuOpen = false;
			break;

		default:
			system("CLS");
			break;

		}


	}

	return 0;

}