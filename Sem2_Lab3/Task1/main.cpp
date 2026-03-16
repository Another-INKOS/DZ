 #include <iostream>
#include "Figures.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

int main() {
    Figure* figures[4];
    figures[0] = new Circle(3);
    figures[1] = new Rectangle(3, 4);
    figures[2] = new Triangle(5, 2);
    figures[3] = new Square(4);

    for (int i = 0; i < 4; ++i) {
        cout << "Figure " << i + 1 << ":" << endl;
        cout << figures[i]->to_string() << endl;
        cout << "Cylinder volume (height=5): " << calc_cylinder_volume(figures[i], 5) << endl;
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete figures[i];
    }

    return 0;
}
