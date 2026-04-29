#include "main_hero.h"
#include <iostream>
using namespace std;

MainHero::MainHero(double pos_x, double pos_y, string n, int health)
    : BaseCharacter(pos_x, pos_y, health) {
    name = n;
    current_weapon = 0;
}

void MainHero::hit(BaseEnemy* target) {
    // Check if has weapon?
    if (inventory.size() == 0) {
        cout << "I have no weapon" << endl;
        return;
    }

    // Attack with current weapon
    inventory[current_weapon].hit(this, target);
}

void MainHero::add_weapon(Weapon w) {
    // Add weapon to inventory
    inventory.push_back(w);
    cout << "Picked up " << w << endl;

    // If this is first weapon - equip it
    if (inventory.size() == 1) {
        current_weapon = 0;
    }
}

void MainHero::next_weapon() {
    // No weapon
    if (inventory.size() == 0) {
        cout << "I have no weapon" << endl;
        return;
    }

    // Only one weapon
    if (inventory.size() == 1) {
        cout << "I have only one weapon" << endl;
        return;
    }

    // Switch to next weapon (in a circle)
    current_weapon = (current_weapon + 1) % inventory.size();
    cout << "Switched weapon to " << inventory[current_weapon] << endl;
}

void MainHero::heal(int amount) {
    hp = hp + amount;
    if (hp > 200) {
        hp = 200;  // max 200 HP
    }
    cout << "Healed, now health is " << hp << endl;
}

bool MainHero::has_weapon() {
    return inventory.size() > 0;
}