#pragma once
#include <array>
#include <string>
#include <random>

class Password {
private:
	int pass_lenght{ 0 };
	//array of special char
	const std::array<char, 13> special_char{ ',', '.', '!', '@', '$', '%', '*', '_', '#', '&', '/', '?', '\\'};
	//number of special char in pass
	int special_char_amount{ 0 };

	//array of numbers
	const std::array<int, 10> numbers{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//number of numbers in pass
	int number_char_amount{ 0 };

	//array of letters
	const std::array<char, 52> letters{ 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L',
	'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z' };
	//number of letters in pass
	int letter_char_amount{ 0 };

	//password
	std::string password{};
	void generate_password();

public:
	//constructor
	Password() = default;
	//destructor
	~Password() = default;

	//pass lenght
	bool set_pass_lenght(uint16_t pass_lenght);
	uint8_t get_pass_lenght();

	//special char
	bool set_special_char_amount(uint8_t amount);
	uint8_t get_special_char_amount();

	//numbers
	bool set_number_char_amount(uint8_t amount);
	uint8_t get_number_char_amount();

	//letters
	bool set_letter_char_amount(uint8_t amount);
	uint8_t get_letter_char_amount();

	//password
	std::string get_password();
	void clear_password();
};

