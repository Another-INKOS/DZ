#ifndef IGRA_H
#define IGRA_H

#include <string>


using namespace std;

struct Igra {

	string name;
	string color;
	string material;
	double size;
	double rating;

	void print() const;

};
void sortByColor(Igra arr[], int size); 
void sortByRating(Igra arr[], int size);
#endif 
