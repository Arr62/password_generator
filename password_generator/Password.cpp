#include "Password.h"

Password::Password(uint8_t pass_lenght_, uint8_t special_char_amount_, uint8_t number_char_amount_)
	: pass_lenght(pass_lenght_), special_char_amount(special_char_amount_), number_char_amount(number_char_amount_), letter_char_amount(pass_lenght - special_char_amount - number_char_amount) {}

bool Password::set_pass_lenght(uint8_t lenght) {
	if (lenght >= 12 && lenght <= 48) {
		pass_lenght = lenght;
		return true;
	}
	else {
		pass_lenght = 12;
		return false;
	}
}

uint8_t Password::get_pass_lenght() {
	return pass_lenght;
}

std::array<char, 13> Password::get_special_char() {
	return special_char;
}

void Password::set_special_char_amount(uint8_t amount) {
	special_char_amount = amount;
}

uint8_t Password::get_special_char_amount() {
	return special_char_amount;
}

std::array<int, 10> Password::get_numbers() {
	return numbers;
}

void Password::set_number_char_amount(uint8_t amount) {
	number_char_amount = amount;
}

uint8_t Password::get_number_char_amount() {
	return number_char_amount;
}

std::array<char, 52> Password::get_letters() {
	return letters;
}

void Password::set_letter_char_amount(uint8_t amount) {
	letter_char_amount = amount;
}

uint8_t Password::get_letter_char_amount() {
	return letter_char_amount;
}

//password
bool Password::generate_password() {
	if ((special_char_amount + number_char_amount + letter_char_amount) != pass_lenght) return false;
	//rand initialization
	srand((unsigned int)time(NULL) + rand() % (unsigned int)time(NULL));

	int spec_count{ };
	int number_count{ };
	int letter_count{ };
	int index{ };
	enum { letter = 0, number = 1, special_char_ = 2 };
	for (size_t i{ 0 }; i < pass_lenght; i++) {
		index = rand() % 3;
		if (spec_count < special_char_amount && index == special_char_) {
			char actual_char = static_cast<char>(special_char.at(rand() % special_char.size()));
			if (i > 0 && password.back() == actual_char) i--;
			else {
				password += actual_char;
				spec_count++;
			}
		}
		else if (number_count < number_char_amount && index == number) {
			int actual_char = numbers.at(rand() % numbers.size());
			if (i > 0 && password.back() == ('0' + actual_char)) i--;
			else {
				password += std::to_string(actual_char);
				number_count++;
			}
		}
		else if (letter_count < letter_char_amount && index == letter) {
			char actual_char = static_cast<char>(letters.at(rand() % letters.size()));
			if (i > 0 && password.back() == actual_char) i--;
			else {
				password += actual_char;
				letter_count++;
			}
		}
		else i--;
	}
	return true;
}

std::string Password::get_password() {

	return password;
}

void Password::clear_password() {
	password.clear();
}