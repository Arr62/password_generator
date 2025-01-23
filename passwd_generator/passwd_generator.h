#ifndef _PASSWD_GENERATOR_H_
#define _PASSWD_GENERATOR_H_

#include <string>

class PasswdGenerator {
private:
static const std::string generate_passwd_characters(const bool use_uppercase, const bool use_lowercase,
    const bool use_number, const bool use_specialchar);

public:
static const std::string get_uppercase_characters();
static const std::string get_lowercase_characters();
static const std::string get_number_characters();
static const std::string get_special_characters();

static const std::string generate_passwd(const size_t passwd_len, const bool use_uppercase,
    const bool use_lowercase, const bool use_number, const bool use_specialchar);
static const std::string generate_passwd(const size_t passwd_len);
};

#endif