#include <iostream>
#include <ctime> //for srand() (seed based on computer clock).

using namespace std;

//alphnum is a char array holding all the allowed characters for the password generation.
const char alphnum[] = "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" "!¡¿?*/"; //size 69; true size 68.
//true size of alphnum.
const int string_length = sizeof(alphnum) - 1;


//Generates a password that follows the requirements.
string passwordGenerator()
{
	//The size the outcome password will be.
	const int password_length = 8;

	//boolean checkers.
	bool contains_capital_letter = false;
	bool contains_number = false;
	bool contains_special_character = false;

	//variable that will return password.
	string password = "";

	//variable that holds the last alphnum chosen for the password.
	char last_alphnum = ' ';

	//for loops 8 times, goes character for character building the password.
	for (int i = 0; i < password_length; i++)
	{
		//holds the current alphnum.
		char holder = alphnum[rand() % string_length];

		//checks if current alphnum is not equal to the last one (to evade repeats).
		if (last_alphnum != holder)
		{
			//makes current last_alphnum equal to current for next use.
			last_alphnum = holder;

			//sums the new char to the password.
			password += holder;

			//indexes on the char array.
			int capital_index = 26;
			int number_index = 52;
			int special_char_index = 63;

			/*This block is used for checking if the current character that was added was a capital letter
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_caps: //label.
			if (contains_capital_letter == false)
			{
				for (int y = 0; y < 26; y++)
				{
					if (holder == alphnum[capital_index])
					{
						contains_capital_letter = true;
						goto check_caps; //goes back to label.
					}
					capital_index++;
				}
			}

			/*This block is used for checking if the current character that was added was a number
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_nums: //label.
			if (contains_number == false)
			{
				for (int y = 0; y < 10; y++)
				{
					if (holder == alphnum[number_index]) {
						contains_number = true;
						goto check_nums; //goes back to label.
					}
					number_index++;
				}
			}

			/*This block is used for checking if the current character that was added was a special character
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_special_char: //label.
			if (contains_special_character == false)
			{
				for (int y = 0; y < 6; y++)
				{
					if (holder == alphnum[special_char_index]) {
						contains_special_character = true;
						goto check_special_char; //goes back to label.
					}
					special_char_index++;
				}
			}
		}
	}

	if (contains_capital_letter == false)
	{
		password[rand() % 3] = alphnum[rand() % (51 - 26 + 1) + 26];
	}

	if (contains_number == false)
	{
		password[rand() % (6 - 4 + 1) + 4] = alphnum[rand() % (62 - 52 + 1) + 52];
	}

	if (contains_special_character == false)
	{
		password[7] = alphnum[rand() % (67 - 63 + 1) + 63];
	}

	return password;
}

bool checkUserPassword(string user_password)
{
	bool contains_capital_letter = false;
	bool contains_number = false;
	bool contains_special_character = false;

	if (user_password.size() == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			int capital_index = 26;
			int number_index = 52;
			int special_char_index = 63;

			/*This block is used for checking if the current character that is in the password is a capital letter
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_caps: //label.
			if (contains_capital_letter == false) {
				for (int y = 0; y < 26; y++)
				{
					if (user_password[i] == alphnum[capital_index]) {
						contains_capital_letter = true;
						goto check_caps; //goes back to label.
					}
					capital_index++;
				}
			}

			/*This block is used for checking if the current character that that is in the password is a number
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_nums: //label.
			if (contains_number == false)
			{
				for (int y = 0; y < 10; y++)
				{
					if (user_password[i] == alphnum[number_index]) {
						contains_number = true;
						goto check_nums; //goes back to label.
					}
					number_index++;
				}
			}

			/*This block is used for checking if the current character that that is in the password is a special character
			* if it is, it will make the checker true and it will go back to the label and not be run again. */

		check_special_char: //label.
			if (contains_special_character == false)
			{
				for (int y = 0; y < 6; y++)
				{
					if (user_password[i] == alphnum[special_char_index]) {
						contains_special_character = true;
						goto check_special_char; //goes back to label.
					}
					special_char_index++;
				}
			}
		}
	}

	if (contains_capital_letter == true && contains_number == true && contains_special_character == true)
	{
		system("CLS");
		cout << "PASSWORD MEETS REQUIREMENTS" << endl;
		system("pause");
		return true;

	}
	else {
		system("CLS");
		cout << "ERROR PASSWORD DOESN'T MEET REQUIREMENTS" << endl;
		system("pause");
		return false;
	}
}

int main() {
	srand(time(0));

	int user_input = 0;
	string password = "";

	cout << "1. Introduce a password." << endl << "2. Generate a password." << endl;
	cin >> user_input;

	switch (user_input)
	{
	case 1:
		do
		{
			system("CLS");
			cout << "Introduce a password (The password must be 8 characters long, and must contain a capital letter, a number, and a special character): ";
			cin >> password;
		} while (checkUserPassword(password) != true);
		system("CLS");
		cout << endl << "Your introduced password is: " << password << endl;
		break;

	case 2:
		system("CLS");
		cout << endl << "The generated password is: " << passwordGenerator() << "." << endl;
		break;
	}
}