#include "Human.h"
class Student : public Human {
public:
    int grade;
    string group;
    Student(string f, string l, string m, int g, string gr);
    void printStudent();
};
