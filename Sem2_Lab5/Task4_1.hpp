#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double re, im;
public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    Complex operator+(const Complex& other) const { return Complex(re + other.re, im + other.im); }
    Complex operator-(const Complex& other) const { return Complex(re - other.re, im - other.im); }
    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }
    Complex operator/(const Complex& other) const {
        double den = other.re * other.re + other.im * other.im;
        return Complex((re * other.re + im * other.im) / den,
            (im * other.re - re * other.im) / den);
    }
    bool operator==(const Complex& other) const { return re == other.re && im == other.im; }
    bool operator!=(const Complex& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.re << "," << c.im << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.re >> c.im;
        return is;
    }
};

#endif
