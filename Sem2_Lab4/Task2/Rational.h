#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
    // Методы для получения числителя и знаменателя
    int Numerator() const;
    int Denominator() const;

    // Унарные операторы
    Rational operator+() const;
    Rational operator-() const;

    // Операторы присваивания (составные)
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // Вспомогательная функция для вывода в поток (удобно для тестов)
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

private:
    int num; // числитель
    int den; // знаменатель

    // Метод для сокращения дроби
    void simplify();
};

// Бинарные арифметические операторы
Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);

// Операторы сравнения
bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);

#endif
