#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figures.h"
#include <string>

class Circle : public Figure {
private:
    double* radius;
public:
    Circle(double radius);
    ~Circle() override;
    double calc_area() override;
    std::string to_string() override;
};

#endif
