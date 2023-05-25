#include "pch.h"
#include "../password_generator/Password.cpp"
#include <string>

class testFixture : public testing::Test {
private:
public:
	Password* password;
	testFixture() {
		password = new Password{11};
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
		for (int i{}; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->generate_password();
				ASSERT_EQ(i, (password->get_password()).size());
			}
			else {
				password->generate_password();
				ASSERT_EQ(12, (password->get_password()).size());
			}
			password->clear_password();
		}
	}
	//checking for duplicates of two the same characters
	TEST_F(testFixture, test_3) {
		for (int i{ 0 }; i < 256; i++) {
			if (password->set_pass_lenght(i)) {
				password->generate_password();
				std::cout << password->get_password() << std::endl;
				for (int j{ 1 }; j < i; j++) {
					ASSERT_NE((password->get_password()).at(j), (password->get_password()).at(j - 1));
				}
			}
			else {
				password->generate_password();
				std::cout << password->get_password() << std::endl;
				for (int k{ 1 }; k < 12; k++) {
					ASSERT_NE((password->get_password()).at(k), (password->get_password()).at(k - 1));
				}
			}
			password->clear_password();
		}
	}
}
	//checking the number of special characters
	//checking the number of numbers
	//checking the number of letters