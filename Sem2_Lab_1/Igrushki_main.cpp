#include <iostream>
#include <fstream>
#include <string>
#include "../Igra.h"
using namespace std;

int main() {
    ifstream file("igra.txt");
    if (!file) {
        cerr << "Oshibka: ne mogu otkrit` file igra.txt" << endl;
        return 1;
    }
    int count = 0;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) count++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    Igra* arr = new Igra[count];
    for (int i = 0; i < count; ++i) {
        file >> arr[i].name >> arr[i].color >> arr[i].material >> arr[i].size >> arr[i].rating;
    }
    file.close();
    cout << "Iznachalniy massiv:" << endl;
    for (int i = 0; i < count; ++i) {
        arr[i].print();
    }
    sortByColor(arr, count);
    cout <<"Igrushki po cvetu:" << endl;
    for (int i = 0; i < count; ++i) {
        arr[i].print();
    }
    sortByRating(arr, count);
    cout << "Igrushki po ratingu:" << endl;
    for (int i = 0; i < count; ++i) {
        arr[i].print();
    }

    delete[] arr;
    return 0;
}
