#include "Complex.h"
#include <iostream>

using namespace std;

int main() 
{
    Complex z1(3, 4);
    Complex z2(1, -2);

    cout << "z1 = "; z1.Print();
    cout << "z2 = "; z2.Print();

    cout << "\nABS z1: " << z1.Abs() << endl;
    cout << "Argument z1: " << z1.Arg() << " rad" << endl;

    cout << "\nTrig. forma z1:" << endl;
    z1.TrigPrint();

    cout << "\nPokaz. forma z1:" << endl;
    z1.ExpPrint();

    cout << "\nz1 + z2:" << endl;
    Complex sum = z1.Add(z2);
    sum.Print();

    cout << "\nz1 - z2:" << endl;
    Complex diff = z1.Sub(z2);
    diff.Print();

    cout << "\nz1 * z2:" << endl;
    Complex prod = z1.Mult(z2);
    prod.Print();

    cout << "\nz1 / z2:" << endl;
    Complex quot = z1.Div(z2);
    quot.Print();
    z1.SetRe(5);
    z1.SetIm(-1);
    cout << "\nNew z1: "; z1.Print();

    return 0;
}
