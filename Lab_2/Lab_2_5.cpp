#include <iostream>
using namespace std;

int main() {
    double y;
    cout << "-------------------" << endl;
    cout << "   x     |   y     " << endl;
    cout << "-------------------" << endl;

    for (double i = -2.0; i <= 2.0; i += 0.5) {
        y = -2.4 * i * i + 5 * i - 3; // вычисляем значение функции
        cout << i << " | " << y << endl;
    }
    return 0;
}
