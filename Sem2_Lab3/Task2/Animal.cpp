#include "Animal.h"

Animal::Animal(std::string n) : name(n) {}

Animal::~Animal() {
    std::cout << "[Animal] " << name << " ushel iz zooparka" << std::endl;
}

void Animal::breathe() {
    std::cout << name << " umeet dishat`" << std::endl;
}

void Animal::eat() {
    std::cout << name << " est che ta kobila" << std::endl;
}

std::string Animal::getName() {
    return name;
}
