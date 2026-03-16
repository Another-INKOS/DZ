#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figures.h"

class Triangle : public Figure {
    double* base;
    double* height;
public:
    Triangle(double base, double height);
    ~Triangle() override;
    double calc_area() override;
    std::string to_string() override;
};

#endif
