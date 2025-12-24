#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of even numbers: ";
    cin >> n;
    ofstream outFile("file.txt");
    if (!outFile) {
        cout << "File open error" << endl;
        return 1;
    }
    
    cout << "filling file with numbers... " << endl;
    for (int i = 1; i <= n; ++i) {
        outFile << 2 * i;
        if (i < n) outFile << " ";
    }
    outFile.close();
    cout << "Numbers are sucsessfuly entered in 'file.txt'" << endl;
    cout << "How much numbers do you want to read?: ";
    cin >> m;
    ifstream inFile("file.txt");
    if (!inFile) {
        cout << "File open error" << endl;
        return 1;
    }
    cout << "First numbers:" << endl;
    int number;
    int count = 0;
    while (inFile >> number && count < m) {
        cout << number << " ";
        ++count;
    }
    inFile.close();

    if (count == 0) {
        cout << "\nFile empty or doesnt have numbers" << endl;
    } else if (count < m) {
        cout << "\nAttention, there is less numbers in file(" << count << " from " << m << ")" << endl;
    } else {
        cout << endl;
    }

    return 0;
}
