#include <iostream>
#include "complex.h"

int main() {
    Complex a(3, 4);
    Complex b;

    std::cout << "A: " << a << std::endl;
    std::cout << "vvedite B:" << std::endl;
    std::cin >> b;
    Complex c = a;
    Complex d;
    d = b; 
    std::cout << "C (copiya A): " << c << std::endl;
    std::cout << "D (prisv B): " << d << std::endl;
    std::cout << "A + B = " << (a + b) << std::endl;
    std::cout << "A - B = " << (a - b) << std::endl;
    std::cout << "A * B = " << (a * b) << std::endl;
    std::cout << "A / B = " << (a / b) << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "A++ (post): " << a++ << " A: " << a << std::endl;
    std::cout << "++A (pre): " << ++a << std::endl;
    --b;
    std::cout << "B: " << b << std::endl;
    if (a > b) std::cout << "A > B" << std::endl;
    if (a == c) std::cout << "A = C" << std::endl;

    return 0;
}
