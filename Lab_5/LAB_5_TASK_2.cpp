#include <iostream>

using namespace std;

string proverka(string password) {
    string res = "";
    bool Upper = false, Lower = false, Digit = false, Special = false;
    for (char c : password) {
        if (c >= 32 && c <= 126) {
            if (isupper(c)){
                    Upper = true;
            }
            if (islower(c)) {
                    Lower = true;
            }
            if (isdigit(c)) {
                    Digit = true;
            }
            if (ispunct(c)) {
            Special = true;
            }
            c = (c > 126) ? (c - 95) : c;
            res += c;
        }
    }

    if (res.length() >= 8 && res.length() <= 14 && Upper && Lower && Digit && Special) {
        return "Welcome, Admin";
    } else {
        return "Password does not meet the requirements.";
    }
}


int main()
{
    string password;
    cout <<"Enter password: ";
    cin >> password;
    cout << proverka(password);
}
