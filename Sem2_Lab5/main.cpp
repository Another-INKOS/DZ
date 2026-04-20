
#include <iostream>
#include <string>
#include "contains.hpp"
#include "change.hpp"
#include "Matrix.hpp"
#include "Polynomial.hpp"
#include "Complex.hpp"

using namespace std;                                
template<typename T>
void printArray(const T* arr, size_t n) {
    for (size_t i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int iarr[] = { 10, 20, 30, 40, 50 };
    size_t isz = 5;
    cout << "int       : "; printArray(iarr, isz);
    cout << "contains(30): " << contains(30, iarr, isz) << endl;
    cout << "contains(99): " << contains(99, iarr, isz) << endl;
    change(20, 40, iarr, isz);
    cout << "      change(20,40): "; printArray(iarr, isz);
    double darr[] = { 1.1, 2.2, 3.3, 4.4 };
    size_t dsz = 4;
    cout << "\ndouble       : "; printArray(darr, dsz);
    change(2.2, 4.4, darr, dsz);
    cout << "      change(2.2,4.4): "; printArray(darr, dsz);
    change(9.9, 1.1, darr, dsz); //                 
    string sarr[] = { "apple", "banana", "cherry", "date" };
    size_t ssz = 4;
    cout << "\nstring       : "; printArray(sarr, ssz);
    change(string("banana"), string("date"), sarr, ssz);
    cout << "      change(banana, date): "; printArray(sarr, ssz);
    Matrix<int> A(2, 2);
    A.Set(0, 0, 1); A.Set(0, 1, 2);
    A.Set(1, 0, 3); A.Set(1, 1, 4);
    Matrix<int> B(2, 2);
    B.Set(0, 0, 5); B.Set(0, 1, 6);
    B.Set(1, 0, 7); B.Set(1, 1, 8);
    cout << "A:\n" << A << "\nB:\n" << B;
    cout << "A+B:\n" << A + B;
    cout << "A*B:\n" << A * B;
    Matrix<string> S(2, 2);
    S.Set(0, 0, "a"); S.Set(0, 1, "b");
    S.Set(1, 0, "c"); S.Set(1, 1, "d");
    Matrix<string> T(2, 2);
    T.Set(0, 0, "1"); T.Set(0, 1, "2");
    T.Set(1, 0, "3"); T.Set(1, 1, "4");
    cout << "\nS (string):\n" << S << "T:\n" << T;
    cout << "S+T (            ):\n" << S + T;
    vector<int> vint = { 1, 2, 1 };
    Polynomial<int> p1(vint);
    Polynomial<int> p2(5);
    cout << "p1 = " << p1 << ",         " << p1.Degree() << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1 + p2 = " << (p1 + p2) << endl;
    cout << "p1 * p2 = " << (p1 * p2) << endl;
    cout << "p1(3) = " << p1(3) << endl;
    vector<Complex> vc = { Complex(1,0), Complex(2,0), Complex(1,0) };
    Polynomial<Complex> q1(vc);
    Polynomial<Complex> q2(Complex(5, 0));
    cout << "\nq1 = " << q1 << endl;
    cout << "q2 = " << q2 << endl;
    cout << "q1 + q2 = " << (q1 + q2) << endl;
    Complex x(2, 1);
    cout << "q1(" << x << ") = " << q1(x) << endl;

    return 0;
}
