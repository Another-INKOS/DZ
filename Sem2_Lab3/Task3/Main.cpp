#include <iostream>
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Teacher t1("Ivan", "Ivanov", "Ivanovich", "Matematika");
    
    Student s1("Petr", "Petrov", "Petrovich", 10, "A");
    t1.printTeacher();
    s1.printStudent();
    cout << "Short name: " << s1.getShortName() << endl;
    return 0;
}
