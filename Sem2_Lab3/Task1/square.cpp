#include "Square.h"
#include <sstream>

Square::Square(double side) {
    this->side = new double(side);
}

Square::~Square() {
    delete side;
}

double Square::calc_area() {
    return (*side) * (*side);
}

std::string Square::to_string() {
    std::stringstream ss;
    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"square\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";
    return ss.str();
}
