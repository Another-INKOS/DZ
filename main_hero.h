#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "base_character.h"
#include "weapon.h"
#include "base_enemy.h"
#include <vector>
using namespace std;

class MainHero : public BaseCharacter {
private:
    string name;                    // hero name
    vector<Weapon> inventory;       // array of weapons
    int current_weapon;             // index of current weapon

public:
    // Constructor
    MainHero(double pos_x, double pos_y, string n, int health);

    // Hero attacks enemy
    void hit(BaseEnemy* target);

    // Add weapon
    void add_weapon(Weapon w);

    // Switch to next weapon
    void next_weapon();

    // Heal
    void heal(int amount);

    // Check if has weapon
    bool has_weapon();
};

#endif