#include "Igra.h"
#include <iostream>
#include <string>

using namespace std;

void Igra::print() const {
	cout << name << " " << color << " " << material << " " << size << " " << rating << " "<<endl;
}
void sortByColor(Igra arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].color > arr[j + 1].color) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortByRating(Igra arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].rating > arr[j + 1].rating) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
