#include <iostream>
#include "Rational.h"

int main() {
    try {
        Rational r1(1, 2); // 1/2
        Rational r2(1, 3); // 1/3

        std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;

        // Тест арифметики
        std::cout << r1 << " + " << r2 << " = " << (r1 + r2) << " (should be 5/6)" << std::endl;
        std::cout << r1 << " - " << 1 << " = " << (r1 - 1) << " (should be -1/2)" << std::endl;

        // Тест умножения/деления
        Rational r3 = r1 * 2; // Автоматическое преобразование int в Rational
        std::cout << r1 << " * 2 = " << r3 << " (should be 1/1)" << std::endl;

        // Тест сравнения
        Rational r4(2, 4);
        if (r1 == r4) {
            std::cout << r1 << " is equal to " << r4 << " (correct)" << std::endl;
        }

        // Тест унарного минуса
        std::cout << "Negative " << r2 << " is " << (-r2) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
