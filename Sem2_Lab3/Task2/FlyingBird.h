#ifndef FLYINGBIRD_H
#define FLYINGBIRD_H

#include "Bird.h"

class FlyingBird : public Bird {
public:
    FlyingBird(std::string n);

    void fly(); 
};

#endif
