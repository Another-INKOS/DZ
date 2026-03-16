#include <iostream>
#include <string>

using namespace std;

class Human {
public:
    string firstName;
    string lastName;
    string middleName;
    Human();
    Human(string f, string l, string m);
    ~Human();
    string getShortName();
    string getFullName();
};
