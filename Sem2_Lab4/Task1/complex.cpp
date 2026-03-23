#include "complex.h"
Complex::Complex() : re(0), im(0) {}
Complex::Complex(int x, int y) : re(x), im(y) {}
Complex::Complex(const Complex& other) {
    re = other.re;
    im = other.im;
}
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) { 
        re = other.re;
        im = other.im;
    }
    return *this;
}
int Complex::magnitudeSq() const {
    return re * re + im * im;
}
Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    int denom = other.re * other.re + other.im * other.im;
    if (denom == 0) return Complex(0, 0);
    return Complex((re * other.re + im * other.im) / denom, 
                   (im * other.re - re * other.im) / denom);
}
Complex& Complex::operator++() {
    re++; im++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    re++; im++;
    return temp;
}

Complex& Complex::operator--() {
    re--; im--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    re--; im--;
    return temp;
}
bool Complex::operator==(const Complex& other) const {
    return magnitudeSq() == other.magnitudeSq();
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator>(const Complex& other) const {
    return magnitudeSq() > other.magnitudeSq();
}

bool Complex::operator<(const Complex& other) const {
    return magnitudeSq() < other.magnitudeSq();
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re << " + " << c.im << "*i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Введите re: "; is >> c.re;
    std::cout << "Введите im: "; is >> c.im;
    return is;
}
