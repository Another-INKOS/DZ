#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class BaseCharacter;  // forward declaration

class Weapon {
private:
    string name;      // weapon name
    int damage;       // damage amount
    double range;     // attack range

public:
    // Constructor
    Weapon(string n = "no weapon", int d = 0, double r = 0);

    // Hit method
    void hit(BaseCharacter* actor, BaseCharacter* target);

    // Getters
    string getName() { return name; }
    int getDamage() { return damage; }
    double getRange() { return range; }

    // Input/output operators
    friend ostream& operator<<(ostream& os, const Weapon& w);
    friend istream& operator>>(istream& is, Weapon& w);
};

#endif