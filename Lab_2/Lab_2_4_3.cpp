#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 500; i++) { 
        if (i % 35 == 0) {
            cout << "fuzzbuzz" << endl;
        } else if (i % 5 == 0) {
            cout << "fuzz" << endl;
        } else if (i % 7 == 0) {
            cout << "buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
    return 0;
}
