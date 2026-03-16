#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
class Animal {
protected:
    std::string name;

public:
    Animal(std::string n);
    virtual ~Animal();)
    virtual void breathe();
    virtual void eat();

    std::string getName();
};

#endif
