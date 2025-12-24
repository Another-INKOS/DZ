#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter your number" << endl;
    cin >> n;
    int n2 = n*10;
    int pal = 0;
    if (n > 0 && n <= 9999){
        while (n2 > 0){
            pal += (n2%10);
            n2 = n2/10;
            pal = pal*10;
        }
        pal = pal/10;
        if (pal == n){
        cout << "Palindrome"<< endl;
    }
    else{
        cout << "Not palindrome" <<endl;
    }
    }
    else{
        cout << "out of range";
    }

    return 0;
}
