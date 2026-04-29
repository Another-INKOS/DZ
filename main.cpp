#include <iostream>
#include "get_password.h"
#include "password_exceptions.h"
#include "weapon.h"
#include "base_enemy.h"
#include "main_hero.h"
using namespace std;

// Custom exceptions for demonstration (requirement: 2 own exceptions)
class NoWeaponException {
public:
    string what() { return "Hero has no weapon to attack!"; }
};

class EnemyDeadException {
public:
    string what() { return "Cannot attack a dead enemy!"; }
};

// Test task 1
void test_password() {
    cout << "\n========== TASK 1: PASSWORD CHECK ==========\n" << endl;

    for (int i = 0; i < 5; i++) {
        try {
            cout << "\n--- Attempt " << i + 1 << " ---" << endl;
            cout << "Tip: try a password like 'Abc123def' (9 chars, digits, mixed case)" << endl;
            string p = get_password();
            cout << "Password accepted: " << p << endl;
        }
        catch (LengthError& e) {
            cout << "ERROR: " << e.what() << endl;
        }
        catch (RegisterError& e) {
            cout << "ERROR: " << e.what() << endl;
        }
        catch (DigitError& e) {
            cout << "ERROR: " << e.what() << endl;
        }
        catch (ForbiddenLetterError& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }
}

// Battle function
void battle() {
    cout << "\n========== TASK 2: BATTLE ==========\n" << endl;

    // Create weapons
    Weapon sword("Sword", 25, 3.0);
    Weapon bow("Bow", 15, 8.0);
    Weapon axe("Axe", 40, 1.5);

    // Create hero
    MainHero hero(0, 0, "Arthur", 100);

    // Add weapons to hero
    cout << "\n--- Hero picks up weapons ---" << endl;
    hero.add_weapon(sword);
    hero.add_weapon(bow);

    // Create enemies
    BaseEnemy enemy1(2, 2, axe, 50);
    BaseEnemy enemy2(5, 0, bow, 40);

    cout << "\n--- Enemy info ---" << endl;
    cout << enemy1 << endl;
    cout << enemy2 << endl;

    // Battle starts
    cout << "\n--- BATTLE STARTS ---" << endl;

    cout << "\n1. Attack first enemy with sword:" << endl;
    hero.hit(&enemy1);

    cout << "\n2. Switch weapon to bow:" << endl;
    hero.next_weapon();

    cout << "\n3. Attack first enemy again:" << endl;
    hero.hit(&enemy1);

    cout << "\n4. Attack second enemy:" << endl;
    hero.hit(&enemy2);

    cout << "\n5. Hero heals:" << endl;
    hero.heal(30);

    cout << "\n6. Attack first enemy again:" << endl;
    hero.hit(&enemy1);

    cout << "\n7. Switch weapon (cycle):" << endl;
    hero.next_weapon();
    hero.next_weapon();

    // Demonstrate custom exceptions
    cout << "\n--- CUSTOM EXCEPTIONS DEMO ---" << endl;
    try {
        if (!hero.has_weapon()) {
            throw NoWeaponException();
        }
        cout << "Hero has weapon (check passed)" << endl;

        if (!enemy1.is_alive()) {
            throw EnemyDeadException();
        }
        cout << "Enemy is still alive" << endl;
    }
    catch (NoWeaponException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (EnemyDeadException& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

int main() {
    cout << "LABORATORY WORK #6" << endl;
    cout << "zaitsev semyon, student 1st year" << endl;

    test_password();
    battle();

    cout << "\n========== PROGRAM FINISHED ==========" << endl;
    return 0;
}