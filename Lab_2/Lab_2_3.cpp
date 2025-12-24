#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b <= c)  (a + c <= b)  (b + c <= a)) {
        cout << "UNDEFINED" << endl;
        return 0;
    }
    if (a > b && a > c){
        if (a*a == b*b + c*c){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    if (b > a && b > c){
        if (b*b == a*a + c*c){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    if (c > b && c > a){
        if (c*c == b*b + a*a){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
