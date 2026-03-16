#ifndef SQUARE_H
#define SQUARE_H

#include "Figures.h"

class Square : public Figure {
    double* side;
public:
    Square(double side);
    ~Square() override;
    double calc_area() override;
    std::string to_string() override;
};

#endif
