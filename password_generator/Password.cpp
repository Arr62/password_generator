#include "Password.h"

bool Password::set_pass_lenght(uint16_t lenght) {
	pass_lenght = lenght;
	return true;
}

uint8_t Password::get_pass_lenght() {
	return pass_lenght;
}

bool Password::set_special_char_amount(uint8_t amount) {
	special_char_amount = amount;
	return true;
}

uint8_t Password::get_special_char_amount() {
	return special_char_amount;
}

bool Password::set_number_char_amount(uint8_t amount) {
	number_char_amount = amount;
	return true;
}

uint8_t Password::get_number_char_amount() {
	return number_char_amount;
}

bool Password::set_letter_char_amount(uint8_t amount) {
	letter_char_amount = amount;
	return true;
}

uint8_t Password::get_letter_char_amount() {
	return letter_char_amount;
}

//password
void Password::generate_password() {
	//rand initialization
	srand((unsigned int)time(NULL) + rand() % (unsigned int)time(NULL));

	int spec_count{ 0 };
	int number_count{ 0 };
	int index{ 0 };
	enum c { letter = 0, number = 1, special_char_ = 2 };
	for (size_t i{ 0 }; i < pass_lenght; i++) {
		index = rand() % 3;
		if (spec_count < special_char_amount && index == c::special_char_) {
			char actual_char = static_cast<char>(special_char.at(rand() % special_char.size()));
			if (i > 0 && password.back() == actual_char) i -= 1;
			else {
				password += actual_char;
				spec_count++;
			}
		}
		else if (number_count < number_char_amount && index == c::number) {
			int actual_char = numbers.at(rand() % numbers.size());
			if (i > 0 && password.back() == actual_char) i -= 1;
			else {
				password += std::to_string(actual_char);
				number_count++;
			}
		}
		else {
			char actual_char = static_cast<char>(letters.at(rand() % letters.size()));
			if (i > 0 && password.back() == actual_char) i -= 1;
			else password += actual_char;
		}
	}
}

std::string Password::get_password() {
	generate_password();
	return password;
}

void Password::clear_password() {
	password.clear();
}