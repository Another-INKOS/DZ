#include "get_password.h"
#include "password_exceptions.h"
#include <iostream>
#include <cctype>
using namespace std;

// Function to check for forbidden characters
bool has_forbidden_char(string password, char& found_char) {
    string forbidden = "Ii1oO0";

    for (int i = 0; i < password.length(); i++) {
        for (int j = 0; j < forbidden.length(); j++) {
            if (password[i] == forbidden[j]) {
                found_char = password[i];
                return true;
            }
        }
    }
    return false;
}

string get_password() {
    string password;

    cout << "Enter password: ";
    cin >> password;

    // Check 1: length
    if (password.length() < 9) {
        throw LengthError();
    }

    // Check 2: letter case
    bool has_lower = false;
    bool has_upper = false;

    for (int i = 0; i < password.length(); i++) {
        if (islower(password[i])) has_lower = true;
        if (isupper(password[i])) has_upper = true;
    }

    if (!has_lower || !has_upper) {
        throw RegisterError();
    }

    // Check 3: has digits
    bool has_digit = false;
    for (int i = 0; i < password.length(); i++) {
        if (isdigit(password[i])) {
            has_digit = true;
            break;
        }
    }

    if (!has_digit) {
        throw DigitError();
    }

    // Check 4: forbidden characters
    char forbidden_char;
    if (has_forbidden_char(password, forbidden_char)) {
        throw ForbiddenLetterError(forbidden_char);
    }

    return password;
}