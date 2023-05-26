#include "pch.h"
#include "../password_generator/Password.cpp"
#include <string>

class testFixture : public testing::Test {
private:
public:
	Password* password;
	testFixture() {
		password = new Password{ 11 };
	}
	~testFixture() {}

	void SetUp() {

	}

	void TearDown() {

	}
};

namespace password_tests {
	//checking set password lenght method
	TEST_F(testFixture, test_1) {
		for (int i{}; i < 256; i++) {
			if (i <= 48 && i >= 12) {
				ASSERT_EQ(true, password->set_pass_lenght(i));
			}
			else {
				ASSERT_EQ(false, password->set_pass_lenght(i));
			}
		}
	}
	//checking size of the genereted password
	TEST_F(testFixture, test_2) {
		for (int i{ 12 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->set_letter_char_amount(4 + i - 12);
				password->generate_password();
				ASSERT_EQ(i, (password->get_password()).size());
			}

			password->clear_password();
		}
	}
	//checking for duplicates of two the same characters
	TEST_F(testFixture, test_3) {
		for (int i{ 12 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->set_letter_char_amount(4 + i - 12);
				password->generate_password();
				for (int j{ 1 }; j < i; j++) {
					ASSERT_NE((password->get_password()).at(j), (password->get_password()).at(j - 1));
				}
			}

			password->clear_password();
		}
	}
	//checking the number of special characters
	TEST_F(testFixture, test_4) {
		for (int i{ 12 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->set_letter_char_amount(4 + i - 12);
				password->generate_password();
				uint8_t counter{};
				size_t position{};
				std::string pass{password->get_password()};
				for (int j{ 0 }; j < (password->get_special_char()).size(); j++, position = 0) {
					position = pass.find((password->get_special_char().at(j)));
					if (position != std::string::npos) counter++;
					while (position != std::string::npos) {
						position = pass.find(password->get_special_char().at(j), position + 1);
						if (position != std::string::npos) counter++;
						else break;
					}
				}
				std::cout << password->get_password() << std::endl;
				ASSERT_EQ(password->get_special_char_amount(), counter);
			}

			password->clear_password();
		}
	}
	//checking the number of numbers
	TEST_F(testFixture, test_5) {
		for (int i{ 12 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->set_letter_char_amount(4 + i - 12);
				password->generate_password();
				uint8_t counter{};
				size_t position{};
				std::string pass{password->get_password()};
				for (int j{ 0 }; j < (password->get_numbers()).size(); j++, position = 0) {
					position = pass.find('0' + (password->get_numbers().at(j)));
					if (position != std::string::npos) counter++;
					while (position != std::string::npos) {
						position = pass.find('0' + (password->get_numbers().at(j)), position + 1);
						if (position != std::string::npos) counter++;
						else break;
					}
				}
				std::cout << password->get_password() << std::endl;
				ASSERT_EQ(password->get_number_char_amount(), counter);
			}

			password->clear_password();
		}
	}
	//checking the number of letters
	TEST_F(testFixture, test_6) {
		for (int i{ 12 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->set_letter_char_amount(4 + i - 12);
				password->generate_password();
				uint8_t counter{};
				size_t position{};
				std::string pass{password->get_password()};
				for (int j{ 0 }; j < (password->get_letters()).size(); j++, position = 0) {
					position = pass.find((password->get_letters().at(j)));
					if (position != std::string::npos) counter++;
					while (position != std::string::npos) {
						position = pass.find(password->get_letters().at(j), position + 1);
						if (position != std::string::npos) counter++;
						else break;
					}
				}
				std::cout << password->get_password() << std::endl;
				ASSERT_EQ(password->get_letter_char_amount(), counter);
			}

			password->clear_password();
		}
	}
}