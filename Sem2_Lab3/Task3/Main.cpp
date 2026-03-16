#include <iostream>
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main() {
    // Устанавливаем кодировку (новичок часто гуглит "как выводить русский язык")
    setlocale(LC_ALL, "Russian");

    // Создаем учителя
    Teacher t1("Ivan", "Ivanov", "Ivanovich", "Matematika");
    
    // Создаем студента
    Student s1("Petr", "Petrov", "Petrovich", 10, "A");

    // Выводим данные через их собственные функции
    cout << "--- Informaciya ---" << endl;
    t1.printTeacher();
    s1.printStudent();

    // Просто проверяем работу функций из базового класса
    cout << "Short name: " << s1.getShortName() << endl;

    // Пауза, чтобы консоль не закрылась (классика новичков)
    system("pause"); 

    return 0;
}
