#include "Rational.h"
#include <numeric> 
#include <stdexcept>
Rational::Rational(int numerator, int denominator) : num(numerator), den(denominator) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    simplify();
}
void Rational::simplify() {
    int common = std::gcd(num, den);
    num /= common;
    den /= common;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

int Rational::Numerator() const { return num; }
int Rational::Denominator() const { return den; }
Rational Rational::operator+() const { return *this; }
Rational Rational::operator-() const { return Rational(-num, den); }
Rational& Rational::operator+=(const Rational& other) {
    num = num * other.den + other.num * den;
    den = den * other.den;
    simplify();
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    num = num * other.den - other.num * den;
    den = den * other.den;
    simplify();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    num *= other.num;
    den *= other.den;
    simplify();
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    if (other.num == 0) throw std::invalid_argument("Division by zero");
    num *= other.den;
    den *= other.num;
    simplify();
    return *this;
}
Rational operator+(Rational lhs, const Rational& rhs) { return lhs += rhs; }
Rational operator-(Rational lhs, const Rational& rhs) { return lhs -= rhs; }
Rational operator*(Rational lhs, const Rational& rhs) { return lhs *= rhs; }
Rational operator/(Rational lhs, const Rational& rhs) { return lhs /= rhs; }
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.num << "/" << r.den;
    return os;
}
