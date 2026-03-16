#include "Teacher.h"

Teacher::Teacher(string f, string l, string m, string s) {
    firstName = f;
    lastName = l;
    middleName = m;
    subject = s;
}

void Teacher::printTeacher() {
    cout << "Prepodavatel: " << getFullName() << ", Predmet: " << subject << endl;
}
