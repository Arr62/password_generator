#include <iostream>
#include <random>

int main()
{
	std::cout << "Enter password lenght: ";
	int pass_lenght{ 0 };
	std::cin >> pass_lenght;
	//rand initialization
	srand(time(NULL));
	//special char in pass
	char special_char[] = { '!', '#', '&', '/', '?', '\\', '|', '\0'};
	int special_char_amount{ 0 };
	const int special_char_max{ 3 };
	const int special_char_min{ 1 };
	special_char_amount = rand() % special_char_max + special_char_min;
	//std::cout << "Special char: " << special_char_amount << std::endl;
	//numbers in pass
	int number_char_amount{ 0 };
	const int number_char_max{ 6 };
	const int number_char_min{ 3 };
	number_char_amount = rand() % number_char_max + number_char_min;
	//std::cout << "Numbers: " << number_char_amount << std::endl;
	//letters in pass
	char letters[2 * 26 + 1];
	int a{ 65 };
	for (int i{ 0 }; i < (2 * 26); i++) {
		letters[i] = a++;
		if (a == 91) a = 97;
	}
	letters[2 * 26] = '\0';
	int letter_char_amount{ 0 };
	letter_char_amount = pass_lenght - special_char_amount - number_char_amount;
	//std::cout << "Letters: " << letter_char_amount << std::endl;
	int* password_temp = new int[pass_lenght];
	//init array with 0 values
	for (int i{ 0 }; i < pass_lenght; i++) {
		password_temp[i] = 0;
	}
	//
	//0 -> letter
	//1 -> number
	//2 -> special char
	int spec_count{ 0 };
	int number_count{ 0 };
	int temp{ 0 };
	for (int i{ 0 }; number_count != number_char_amount; i++) {
		temp = rand() % pass_lenght;
		//std::cout << temp << std::endl;
		if (spec_count < special_char_amount && password_temp[temp] != 2) {
			password_temp[temp] = 2;
			spec_count++;
		}
		else if (number_count < number_char_amount && password_temp[temp] != 2 && password_temp[temp] != 1) {
			password_temp[temp] = 1;
			number_count++;
		}
	}
	//create password
	char* password = new char[pass_lenght + 1];
	for (int i{ 0 }; i < pass_lenght; i++) {
		if (password_temp[i] == 2) {
			password[i] = special_char[rand() % (strlen(special_char) + 1)];
		}
		else if (password_temp[i] == 1) {
			password[i] = rand() % 10 + 48;
		}
		else if (password_temp[i] == 0) {
			password[i] = letters[rand() % (strlen(letters) + 1)];
		}
	}
	password[pass_lenght] = '\0';
	//output password
	for (int i{ 0 }; i < pass_lenght; i++) {
		std::cout << password[i];
	}

	return 0;
}
