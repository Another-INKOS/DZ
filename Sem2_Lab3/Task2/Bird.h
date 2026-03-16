#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird(std::string n);

    void breathe() override;
    void layEggs(); 
};

#endif
