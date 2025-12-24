#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of numbers: ";
    cin >> n;
    ofstream outFile("file.bin", ios::binary);
    if (!outFile) {
        cerr << "File open error" << endl;
        return 1;
    }
    cout << "Filling file with numbers... " << endl;
    for (int i = 1; i <= n; ++i) {
        outFile.write(reinterpret_cast<const char*>(&i), sizeof(i));
    }
    outFile.close();


    cout << "Numbers are sucsessfuly entered in 'file.bin'" << endl;
    cout << endl;
    ifstream inFile("file.bin", ios::binary);
    if (!inFile) {
        cout << "File open error" << endl;
        return 1;
    }

    cout << "Reading numbers..." << endl;
    int number;
    int env_nums = 0;
    int count = 0;

    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        if (number % 2 == 0) {
            cout << number << endl;
            env_nums += number;
        }
        ++count;
    }

    inFile.close();

    if (count == 0) {
        cout << "\nFile empty or doesn't have numbers" << endl;
    } else {
        cout << "Sum of even numbers: " << env_nums << endl;
    }

    return 0;
}
