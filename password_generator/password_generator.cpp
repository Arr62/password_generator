#include <iostream>
#include <random>
#include <array>
#include <string>

int main()
{
	while (1) {
		int pass_lenght{ 0 };
		std::cout << "Enter password lenght: ";
		std::cin >> pass_lenght;
		//entering a pass lenght
		while ((pass_lenght < 12 && std::cin.good()) || (pass_lenght > 48 && std::cin.good()) || (!std::cin.good())) {
			if (pass_lenght < 12 && std::cin.good()) {
				std::cout << "Password too short! Minimum 12 char." << std::endl;
				std::cout << "Enter password lenght: ";
				std::cin >> pass_lenght;
			}
			if (pass_lenght > 48 && std::cin.good()) {
				std::cout << "Password too long! Maximum 48 char." << std::endl;
				std::cout << "Enter password lenght: ";
				std::cin >> pass_lenght;
			}
			if (!std::cin.good()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong value...";
				break;
			}
		}
		//rand initialization
		srand((unsigned int)time(NULL) + rand() % (unsigned int)time(NULL));
		//array of special char
		std::array<char, 13> special_char{ ',', '.', '!', '@', '$', '%', '*', '_', '#', '&', '/', '?', '\\'};
		//number of special char in pass
		int special_char_amount{ 0 };
		//max number of special char in pass
		const int special_char_max{ pass_lenght / 4 };
		//min number of special char in pass
		int special_char_min{ pass_lenght / 8 };
		special_char_amount = rand() % (special_char_max - special_char_min + 1) + special_char_min;
		//array of numbers
		std::array<int, 10> numbers{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//number of numbers in pass
		int number_char_amount{ 0 };
		//max number of numbers in pass
		const int number_char_max{ pass_lenght / 4 };
		//min number of numbers in pass
		const int number_char_min{ pass_lenght / 8 };
		number_char_amount = rand() % (number_char_max - number_char_min + 1) + number_char_min;
		//array of letters
		std::array<char, 52> letters{ 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L',
		'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z' };
		//number of letters in pass
		int letter_char_amount{ 0 };
		letter_char_amount = pass_lenght - special_char_amount - number_char_amount;
		//vector contains temp password
		std::vector<int> password_temp(pass_lenght, 0);
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
		std::string password{};
		for (int i{ 0 }; i < pass_lenght; i++) {
			if (password_temp[i] == 2) {
				password += special_char.at(rand() % special_char.size());
			}
			else if (password_temp[i] == 1) {
				password += std::to_string(numbers.at(rand() % numbers.size()));
			}
			else {
				password += letters.at(rand() % letters.size());
			}
		}
		//output password
		std::cout << "Generated password: " << password << std::endl << std::endl;
		//clear password_temp and password
		password_temp.clear();
		password.clear();
	}

	return 0;
}
