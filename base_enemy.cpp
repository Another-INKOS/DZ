#include "base_enemy.h"

BaseEnemy::BaseEnemy(double pos_x, double pos_y, Weapon w, int health)
    : BaseCharacter(pos_x, pos_y, health) {
    weapon = w;
}

void BaseEnemy::hit(BaseCharacter* target) {
    weapon.hit(this, target);
}

ostream& operator<<(ostream& os, BaseEnemy& e) {
    os << "Enemy at position (" << e.get_x() << ", " << e.get_y()
        << ") with weapon " << e.weapon;
    return os;
}