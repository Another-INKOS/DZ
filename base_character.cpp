#include "base_character.h"
#include <iostream>
using namespace std;

BaseCharacter::BaseCharacter(double pos_x, double pos_y, int health) {
    x = pos_x;
    y = pos_y;
    hp = health;
}

void BaseCharacter::move(double delta_x, double delta_y) {
    x = x + delta_x;
    y = y + delta_y;
}

bool BaseCharacter::is_alive() {
    return hp > 0;  // alive if health > 0
}

void BaseCharacter::get_damage(int amount) {
    hp = hp - amount;
    if (hp < 0) {
        hp = 0;  // health cannot be negative
    }
    cout << "Character took " << amount << " damage. HP left: " << hp << endl;
}

double BaseCharacter::get_x() {
    return x;
}

double BaseCharacter::get_y() {
    return y;
}