#include "Table.h"
#include <iostream>

using namespace std;

int main()
{
    Table tab(3, 4);

    tab.set_value(0, 0, 10);
    tab.set_value(0, 2, 25);
    tab.set_value(1, 1, -3);
    tab.set_value(1, 3, 17);
    tab.set_value(2, 0, 8);
    tab.set_value(2, 3, 42);

    cout << "Tablica:" << endl;

    tab.print();

    cout << endl <<"Strok: " << tab.n_rows() << ", stolbcov: " << tab.n_cols() << endl;

    cout << "Znacheniye [1][3]: " << tab.get_value(1, 3) << endl;

    cout << "Srednee arifmeticheskoye: " << tab.average() << endl;

    return 0;
}
