#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of even numbers: ";
    cin >> n;
    ofstream outFile("file.txt");
    if (!outFile) {
        cerr << "File open error" << endl;
        return 1;
    }
    outFile.close();


    cout << "Numbers are sucsessfuly entered in 'file.txt'" << endl;
    cout << endl;
    ifstream inFile("file.txt");
    if (!inFile) {
        cout << "File open error" << endl;
        return 1;
    }

    cout << "Even numbers:" << endl;
    int number;
    int env_nums = 0;
    int count = 0;
    while (inFile >> number && count < n) {
            if (number%2==0){
                cout << number << endl;
                env_nums+=number;
            }
        ++count;
    }
    cout <<"Summ of even numbers: "<< env_nums << endl;
    inFile.close();

    if (count == 0) {
        cout << "\nFile empty or doesnt have numbers" << endl;
    }
    return 0;
}
