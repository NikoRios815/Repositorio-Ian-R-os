#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <array>

using namespace std;

vector<string> generateInventory();
vector<string> openInventory(vector<string> inventory);
vector<string> recollectionMenu(vector<string> inventory);


vector<string> generateInventory() //REWRITE LOGIC. WORKING.
{
	vector<string> randInventory(20, "Empty.");

	const vector<string> Items = { "Hierba Mala (HM)", "Gusano Dorado (GD)" };

	int min = 0;
	int max = Items.size() - 1;

	int inventory_generate_size = 7;

	for (int i = 0; i < inventory_generate_size; i++) {
		int random = rand() % (max - min + 1) + min;
		randInventory[i] = Items[random];
	}

	system("CLS");
	cout << "Inventory Generated.";
	system("pause");
	system("CLS");

	return randInventory;
}

vector<string> openInventory(vector<string> inventory)
{
	bool inventory_opened = true;

	int user_input;
	int user_confirmation;

	while (inventory_opened)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << endl << endl;

		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i + 1 << ". " << inventory[i] << endl;
		}

		cout << inventory.size() + 1 << ". " << "Exit." << endl;
		cout << "===============================================================" << endl;
		cin >> user_input;
		if (user_input == inventory.size() + 1)
		{
			inventory_opened = false;
		}
		else if (user_input <= inventory.size() && user_input > 0)
		{
			cout << "Are you sure you want to destroy this?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> user_confirmation;
			if (user_confirmation == 1)
			{
				inventory[user_input - 1] = "Empty.";
				system("CLS");
				cout << "The object has been destroyed." << endl;
				system("pause");
				system("CLS");
			}
		}
	}
	return inventory;
}

//recollectionMenu lets the player collect a item from a randomize list.
vector<string> recollectionMenu(vector<string> inventory)
{
	const int array_index_size = 4;

	const array<string, array_index_size> possible_found_items = { "Roca Blanda", "Roca Dura", "Roca Cristalina", "Roca Mágica" };
	array<string, array_index_size> found_items = {};

	const int max = found_items.size() - 1;
	const int min = 0;

	int index_value;
	int inventory_spaces;

	for (int i = 0; i < found_items.size(); i++)
	{
		int random = rand() % (max - min + 1) + min;
		found_items[i] = possible_found_items[random];
	}

	while (true)
	{
		inventory_spaces = count(inventory.begin(), inventory.end(), "Empty.");

		system("CLS");

		cout << "===============================================================" << endl;
		cout << "= = found items to recollect = =" << "    inventory spaces left: " << inventory_spaces << endl << endl;
		for (int i = 0; i < found_items.size(); i++)
		{
			cout << i << ". " << found_items[i] << endl;
		}
		cout << found_items.size() << ". " << "Exit." << endl;
		cout << "===============================================================" << endl;
		cout << "Which item do you wish to recollect?" << endl;
		//------------------------------------------------------------------------------------//
		cin >> index_value;
		//int index_value = user_input - 1;
		cout << "index: " << index_value << endl;
		cout << "inventory slot index: " << inventory.size() - inventory_spaces << endl;
		if (index_value < found_items.size())	//checks if the user inputted a out of bounds number or the exit button.
		{
			if (!(found_items[index_value] == "Recollected." || found_items[index_value] == "Destroyed.")) //checks if the user didn't select a already recollected number.
			{
				if (inventory_spaces > 0) //makes sure the player still has spaces left before proceeding.
				{
					if (found_items[index_value] != "Roca Mágica")
					{
						int success_checker = rand() % 3;
						switch (success_checker)
						{
						case 0:
							cout << "Item was succesfully recollected." << endl;
							inventory[inventory.size() - inventory_spaces] = found_items[index_value];
							found_items[index_value] = "Recollected.";
							break;
						case 1:
							cout << "Item was succesfully recollected." << endl;
							inventory[inventory.size() - inventory_spaces] = found_items[index_value];
							found_items[index_value] = "Recollected.";
							break;
						case 2:
							cout << "Item was succesfully recollected." << endl;
							inventory[inventory.size() - inventory_spaces] = found_items[index_value];
							found_items[index_value] = "Recollected.";
							break;
						case 3:
							cout << "The item was destoryed." << endl;
							found_items[index_value] = "Destroyed.";
							break;
						default:
							break;
						}
						system("PAUSE");
					}
					else
					{
						int success_checker = rand() % 3;
						switch (success_checker)
						{
						case 0:
							cout << "Item was succesfully recollected." << endl;
							inventory[inventory.size() - inventory_spaces] = found_items[index_value];
							found_items[index_value] = "Recollected.";
							break;
						case 1:
							cout << "The item was destoryed." << endl;
							found_items[index_value] = "Destroyed.";
							break;
						default:
							break;
						}
						system("PAUSE");
					}
				}
				else
				{
					system("CLS");
					cout << "You have no space left in your inventory." << endl;
					system("pause");
				}
			}
			else
			{
				system("CLS");
				cout << "That item was already recollected or destroyed." << endl;
				system("pause");
			}
		}
		else
		{
			if (index_value == 4)
			{
				return inventory;
			}
		}
	}
}

int main()
{

	//RANDOM SEED.
	srand(time(0));

	//Creamos un vector para el inventario.
	vector<string> inventory(20, "Empty.");

	//Creamos una variable bool para mantener el menú funcionando.
	bool menu_open = true;

	//Creamos la variable para la entrada del usuario.
	int main_menu_option;

	//Usamos un ciclo while para mantener el menú funcionando.
	while (menu_open)
	{

		//Este comando limpia la ventana de comandos.
		system("CLS");

		//Creamos el "UI" para el menú.
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = ="
			<< "\n"
			<< endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. RECOLLECTION MENU" << endl;
		cout << "4. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario.
		cout << "AWAITING USER INPUT:  ";
		cin >> main_menu_option;

		//Usamos un switch() para manejar el menú con la entrada del usuario.
		switch (main_menu_option)
		{

		case 1:
			inventory = generateInventory();
			break;

		case 2:
			inventory = openInventory(inventory);
			break;

		case 3:
			inventory = recollectionMenu(inventory);
			break;

		case 4:
			menu_open = false;
			break;

		default:
			system("CLS");
			break;
		}
	}

	return 0;
}