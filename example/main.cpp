#include <iostream>

#include "../passwd_generator/passwd_generator.h"

int main() {
    const size_t passwd_len = 24;
    auto passwd = PasswdGenerator::generate_passwd(passwd_len, true, true, true, true);
    std::cout << "password: " << passwd << std::endl;

    return 0;
}