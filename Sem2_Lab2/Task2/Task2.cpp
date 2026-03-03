#include <iostream>
#include <vector>

using namespace std;

class OddEvenSeparator {
    private:
    vector<int> even_numbers; //вектор для четных 
    vector<int> odd_numbers; //не люблю нечетные, про них не напишу
    public:
    void add_number(int number) {
        if (number % 2 == 0) {
            even_numbers.push_back(number); //добавление в вектор четных чисел
        }
        else {
            odd_numbers.push_back(number);
        }
        
    }
    void even() const {
    for (int i = 0; i < even_numbers.size(); i++) { //вывод четных на экран
        cout << even_numbers[i] << " " << endl;
    }
}
    void odd() const {
    for (int i = 0; i < odd_numbers.size(); i++) {
        cout << odd_numbers[i] << " " << endl;
    }
}
};
int main() {
    OddEvenSeparator separator; //создание объекта что бы потом вывести

    separator.add_number(5);
    separator.add_number(1);
    separator.add_number(10);
    separator.add_number(2);
    separator.add_number(3);
    separator.add_number(8);

    cout << "Chet: " << endl; //вывод четных чисел
    separator.even();

    cout << "Ne chet: " << endl;
    separator.odd();

    return 0;
}
