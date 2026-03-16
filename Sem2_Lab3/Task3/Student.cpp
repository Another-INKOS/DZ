#include "Student.h"

Student::Student(string f, string l, string m, int g, string gr) {
    firstName = f;
    lastName = l;
    middleName = m;
    grade = g;
    group = gr;
}

void Student::printStudent() {
    cout << "Uchenik: " << getFullName() << ", Klass: " << grade << ", Gruppa: " << group << endl;
}
