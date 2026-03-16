#include "Circle.h"
#include <cmath>
#include <sstream>

Circle::Circle(double radius) {
    this->radius = new double(radius);
}

Circle::~Circle() {
    delete radius;
}

double Circle::calc_area() {
    return (*radius) * (*radius) * M_PI;
}

std::string Circle::to_string() {
    std::stringstream ss;
    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"circle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";
    return ss.str();
}
