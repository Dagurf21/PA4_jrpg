#include "Berserker.h"
#include "../../UI.h"
#include <iostream>
#include <cstdlib>

Berserker::Berserker(const std::string &name)
    : Character(name, 80, 30, 2) {}  // Example: lower health, high attack

void Berserker::attack(Character &target, bool isPlayer) { 
    // ATTACK OPTIONS
    std::string attackOptions[3] = {"Frenzied Strike", "Blood Rage", "Rampage Smash"};
        
    int choice = 0;
    if (isPlayer){
        choice = UI::chooseAttackMenu(attackOptions);
    } else {
        choice = std::rand() % 3 + 1;
    }

    if (choice < 1 || choice > 3) {
        std::cout << "Invalid choice, defaulting to Backstab. \n";
        choice = 1;
    }

    // Compute damage
    int damage = 0;
    switch (choice) {
        case 1:
            damage = attackPower + 5 + (std::rand() % 3 - 1); // + - 1
            break;
        case 2:
            damage = attackPower + 10 + (std::rand() % 5 - 2);
            break;
        case 3:
            damage = attackPower + 3 + (std::rand() % 3 - 1);
            break;
    }

    std::cout << name << " uses " << attackOptions[choice - 1] << " on " << 
                target.getName() << ", dealing " << damage << " damage!\n";

    target.takeDamage(damage);
}
