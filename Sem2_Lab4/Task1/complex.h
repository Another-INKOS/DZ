#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    int re; // Действительная часть
    int im; // Мнимая часть

public:
    Complex();
    Complex(int x, int y);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);
    int magnitudeSq() const;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator--();
    Complex operator--(int); 
    Complex& operator++(); 
    Complex operator++(int);

    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif
