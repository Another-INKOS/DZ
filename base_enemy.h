#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_character.h"
#include "weapon.h"
#include <iostream>
using namespace std;

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;  // enemy's weapon

public:
    // Constructor
    BaseEnemy(double pos_x, double pos_y, Weapon w, int health);

    // Enemy attacks
    void hit(BaseCharacter* target);

    // Print enemy info
    friend ostream& operator<<(ostream& os, BaseEnemy& e);
};

#endif