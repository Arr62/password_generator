#include <gtest/gtest.h>
#include <string>

#include "../passwd_generator/passwd_generator.h"

#define PASSWD_MIN_LEN (1)
#define PASSWD_MAX_LEN (2137)

static inline void generate_and_check_passwd_len(const size_t passwd_len, const bool use_uppercase,
    const bool use_lowercase, const bool use_number, const bool use_specialchar) {
    
    auto passwd = PasswdGenerator::generate_passwd(passwd_len, use_uppercase,
        use_lowercase, use_number, use_specialchar);
    ASSERT_EQ(passwd.size(), passwd_len);
}

// check passwd length
TEST(PasswdLengthTests, UsingAllChars) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, true, true, true, true);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingUppercaseAndLowercase) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, true, true, false, false);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingNumbersAndSpecialchars) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, false, false, true, true);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingUppercase) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, true, false, false, false);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingLowercase) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, false, true, false, false);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingNumbers) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, false, false, true, false);
    }
}

// check passwd length
TEST(PasswdLengthTests, UsingSpecialchars) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        generate_and_check_passwd_len(passwd_len, false, false, false, true);
    }
}

// check passwd characters
TEST(PasswdCharactersTests, UsingUppercase) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        auto passwd = PasswdGenerator::generate_passwd(passwd_len, true, false, false, false);
        for(auto passwd_char : passwd) {
            if(PasswdGenerator::get_uppercase_characters().find(passwd_char) != std::string::npos) { }
            else FAIL() << "Invalid character: " << '\"' << passwd_char << '\"' << " , password: " << '\"' << passwd << '\"';
        }
        EXPECT_TRUE(true);
    }
}

// check passwd characters
TEST(PasswdCharactersTests, UsingLowercase) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        auto passwd = PasswdGenerator::generate_passwd(passwd_len, false, true, false, false);
        for(auto passwd_char : passwd) {
            if(PasswdGenerator::get_lowercase_characters().find(passwd_char) != std::string::npos) { }
            else FAIL() << "Invalid character: " << '\"' << passwd_char << '\"' << " , password: " << '\"' << passwd << '\"';
        }
        EXPECT_TRUE(true);
    }
}

// check passwd characters
TEST(PasswdCharactersTests, UsingNumbers) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        auto passwd = PasswdGenerator::generate_passwd(passwd_len, false, false, true, false);
        for(auto passwd_char : passwd) {
            if(PasswdGenerator::get_number_characters().find(passwd_char) != std::string::npos) { }
            else FAIL() << "Invalid character: " << '\"' << passwd_char << '\"' << " , password: " << '\"' << passwd << '\"';
        }
        EXPECT_TRUE(true);
    }
}

// check passwd characters
TEST(PasswdCharactersTests, UsingSpecialchars) {
    for(size_t passwd_len = PASSWD_MIN_LEN; passwd_len < PASSWD_MAX_LEN; passwd_len++) {
        auto passwd = PasswdGenerator::generate_passwd(passwd_len, false, false, false, true);
        for(auto passwd_char : passwd) {
            if(PasswdGenerator::get_special_characters().find(passwd_char) != std::string::npos) { }
            else FAIL() << "Invalid character: " << '\"' << passwd_char << '\"' << " , password: " << '\"' << passwd << '\"';
        }
        EXPECT_TRUE(true);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
