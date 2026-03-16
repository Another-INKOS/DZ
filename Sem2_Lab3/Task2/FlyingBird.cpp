#include "FlyingBird.h"

FlyingBird::FlyingBird(std::string n) : Bird(n) {}

void FlyingBird::fly() {
    std::cout << name << " LETAET V NATURE!!!" << std::endl;
}
