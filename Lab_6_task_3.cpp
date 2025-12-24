#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int main() 
{
    ifstream inputFile("file.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error: cant open file for reading" << endl;
        return 1;
    }
    int minPositive = INT_MAX;
    bool foundPositive = false;
    int number;
    while (inputFile >> number) 
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
        cout << "File don have any positive numbers" << endl;
    }
    else 
    {
        cout << "Min positive numbers: " << minPositive << endl;
    }
    return 0;
}
