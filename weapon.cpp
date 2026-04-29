#include "weapon.h"
#include "base_character.h"
#include <iostream>
#include <cmath>
using namespace std;

Weapon::Weapon(string n, int d, double r) {
    name = n;
    damage = d;
    range = r;
}

void Weapon::hit(BaseCharacter* actor, BaseCharacter* target) {
    // Check if enemy is alive?
    if (!target->is_alive()) {
        cout << "Enemy is already defeated" << endl;
        return;
    }

    // Calculate distance between characters
    double dx = actor->get_x() - target->get_x();
    double dy = actor->get_y() - target->get_y();
    double distance = sqrt(dx * dx + dy * dy);

    // Check if enough range?
    if (distance > range) {
        cout << "Enemy is too far for weapon " << name << endl;
        return;
    }

    // Deal damage
    cout << "Enemy took damage from weapon " << name << " - " << damage << " points" << endl;
    target->get_damage(damage);
}

// Output operator
ostream& operator<<(ostream& os, const Weapon& w) {
    os << w.name;
    return os;
}

// Input operator
istream& operator>>(istream& is, Weapon& w) {
    cout << "Enter weapon name: ";
    is >> w.name;
    cout << "Enter damage: ";
    is >> w.damage;
    cout << "Enter range: ";
    is >> w.range;
    return is;
}