#include "Stock.h"
#include <iostream>

using namespace std;

int main() 
{

    Stock sklad;

    sklad.Add(10, 20);
    sklad.Add(5, 30);
    sklad.Add(10, 25);
    sklad.Add(15, 10);

    cout << "Gruzovaya orobka ≥ 6 кг → ";
    cout << sklad.GetByW(6) << endl;

    cout << "Eshe gruzovaya korobka  ≥ 6 кг → ";
    cout << sklad.GetByW(6) << endl;

    cout << "Eshe ";
    cout << sklad.GetByW(6) << endl;

    cout << "Ob`emnaya korobka ≥ 15 л → ";
    cout << sklad.GetByV(15) << endl;

    cout << "Ect` tol`ko ≥ 5 л → ";
    cout << sklad.GetByV(5) << endl;

    return 0;
}
