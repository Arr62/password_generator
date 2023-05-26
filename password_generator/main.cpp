#include <iostream>
#include <array>
#include <string>
#include "Password.h"

int main()
{
	Password password{};

	while (1) {
		uint16_t pass_lenght{};
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
				return -1;
			}
		}
		password.set_pass_lenght(static_cast<uint8_t>(pass_lenght));
		password.set_special_char_amount(4);
		password.set_number_char_amount(4);
		password.set_letter_char_amount(password.get_pass_lenght() - password.get_special_char_amount() - password.get_number_char_amount());
		
		if (password.generate_password()) std::cout << "Generated password: " << password.get_password() << std::endl;
		else std::cerr << "Error generating password... check:\n1. Number of special charactes (set/get_special_char_amount)\n2. Number of numbers (set/get_number_char_amount)\n3. Number of letter (set/get_letter_char_amount)\n" << std::endl;

		password.clear_password();
	}
	return 0;
}
