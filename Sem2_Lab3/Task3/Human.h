#include <iostream>
#include <string>

using namespace std; // Новички всегда так делают, чтобы не писать std::

class Human {
public: // Делаем всё публичным, чтобы не мучиться с доступом
    string firstName;
    string lastName;
    string middleName;

    // Обычные конструкторы
    Human();
    Human(string f, string l, string m);

    // Обычный деструктор (без virtual)
    ~Human();

    // Просто функции вывода, без всяких const
    string getShortName();
    string getFullName();
};
