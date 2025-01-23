#include "passwd_generator.h"

#include <stdexcept>
#include <iostream>
#include <random>
#include <unordered_map>

static std::unordered_map<std::string, std::string> characters_map = {
    {"uppercase", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"lowercase", "abcdefghijklmnopqrstuvwxyz"},
    {"number", "0123456789"},
    {"specialchar", "!@#$%^&*()_+"}
};

const std::string PasswdGenerator::get_uppercase_characters() {
    return characters_map["uppercase"];
}

const std::string PasswdGenerator::get_lowercase_characters() {
    return characters_map["lowercase"];
}

const std::string PasswdGenerator::get_number_characters() {
    return characters_map["number"];
}

const std::string PasswdGenerator::get_special_characters() {
    return characters_map["specialchar"];
}

const std::string PasswdGenerator::generate_passwd_characters(const bool use_uppercase, const bool use_lowercase,
    const bool use_number, const bool use_specialchar) {

    std::string characters;
    if(use_uppercase) characters += get_uppercase_characters();
    if(use_lowercase) characters += get_lowercase_characters();
    if(use_number) characters += get_number_characters();
    if(use_specialchar) characters += get_special_characters();

    return characters;
}

const std::string PasswdGenerator::generate_passwd(const size_t passwd_len, const bool use_uppercase,
    const bool use_lowercase, const bool use_number, const bool use_specialchar) {
    
    const auto passwd_characters = PasswdGenerator::generate_passwd_characters(use_uppercase, use_lowercase, use_number, use_specialchar);
    if(passwd_characters.size() <= 0) throw std::runtime_error("Can not generate password characters, check arguments...");

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, passwd_characters.size() - 1);

    std::string passwd;

    for(size_t char_idx = 0; char_idx < passwd_len; char_idx++) {
        passwd += passwd_characters[distribution(generator)];;
    }

    return passwd;
}

const std::string generate_passwd(const size_t passwd_len) {
    return PasswdGenerator::generate_passwd(passwd_len, true, true, true, true);
}