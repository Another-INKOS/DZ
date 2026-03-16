#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    Fish(std::string n);

    void breathe() override; // Переопределение
    void swim();
};

#endif
