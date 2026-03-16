#include "Triangle.h"
#include <sstream>

Triangle::Triangle(double base, double height) {
    this->base = new double(base);
    this->height = new double(height);
}

Triangle::~Triangle() {
    delete base;
    delete height;
}

double Triangle::calc_area() {
    return 0.5 * (*base) * (*height);
}

std::string Triangle::to_string() {
    std::stringstream ss;
    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"triangle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";
    return ss.str();
}
