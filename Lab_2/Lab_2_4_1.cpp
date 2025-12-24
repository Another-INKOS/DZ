#include <iostream>
using namespace std;

int main() {
    int i = 1;

    do { 
        if (i % 35 == 0) {
            cout << "fuzzbuzz" << endl;
        } else if (i % 5 == 0) {
            cout << "fuzz" << endl;
        } else if (i % 7 == 0) {
            cout << "buzz" << endl;
        } else {
            cout << i << endl;
        }
        i++;
    } while (i <= 500);

    return 0;
}
