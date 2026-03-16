#include "Human.h"

class Teacher : public Human {
public:
    string subject;
    Teacher(string f, string l, string m, string s);

    void printTeacher();
};
