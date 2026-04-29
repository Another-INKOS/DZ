#ifndef PASSWORD_EXCEPTIONS_H
#define PASSWORD_EXCEPTIONS_H

#include <string>
using namespace std;

// Base class for all password errors
class PasswordError {
protected:
    string message;
public:
    PasswordError(string msg) : message(msg) {}
    string what() { return message; }
};

// Error: password too short
class LengthError : public PasswordError {
public:
    LengthError() : PasswordError("Error: password is too short (need at least 9 characters)") {}
};

// Error: same letter case
class RegisterError : public PasswordError {
public:
    RegisterError() : PasswordError("Error: all letters are the same case") {}
};

// Error: no digits
class DigitError : public PasswordError {
public:
    DigitError() : PasswordError("Error: no digits in the password") {}
};

// Error: forbidden letters (I, i, l, 1, o, O, 0)
class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError(char c) : PasswordError("Error: forbidden character '" + string(1, c) + "'") {}
};

#endif