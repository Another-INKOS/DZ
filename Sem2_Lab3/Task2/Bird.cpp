#include "Bird.h"

Bird::Bird(std::string n) : Animal(n) {}

void Bird::breathe() {
    std::cout << name << " Ya ne znau kak dishat ptichki" << std::endl;
}

void Bird::layEggs() {
    std::cout << name << " otkladivayet yaica" << std::endl;
}
