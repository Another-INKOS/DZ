#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    cout << "Enter num 1" << endl;
    cin >> a;
    cout << "Enter num 2" << endl;
    cin >> b;
    if(a > 0 && b%2==0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
