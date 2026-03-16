#include "Human.h"
Human::Human() {
    firstName = "Неизвестно";
    lastName = "Неизвестно";
    middleName = "Неизвестно";
}
Human::Human(string f, string l, string m) {
    firstName = f;
    lastName = l;
    middleName = m;
}
Human::~Human() {
}
string Human::getShortName() {
    string result = lastName + " " + firstName[0] + "." + middleName[0] + ".";
    return result;
}
string Human::getFullName() {
    return lastName + " " + firstName + " " + middleName;
}
