#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int main() 
{
    ifstream inputFile("file.bin", ios::binary); // Открываем бинарный файл

    if (!inputFile.is_open()) 
    {
        cerr << "Error: can't open file for reading" << endl;
        return 1;
    }
    int minPositive = INT_MAX;
    bool foundPositive = false;
    int number;
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(number))) 
    {
        if (number > 0) 
        {
            if (number < minPositive) 
            {
                minPositive = number;
            }
            foundPositive = true;
        }
    }
    inputFile.close();
    if (!foundPositive) 
    {
        cout << "File doesn't have any positive numbers" << endl;
    }
    else 
    {
        cout << "Min positive number: " << minPositive << endl;
    }
    return 0;
}
