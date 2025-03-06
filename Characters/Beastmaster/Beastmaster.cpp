#include "Beastmaster.h"
#include <iostream>
#include <cstdlib>

Beastmaster::Beastmaster(const std::string &name)
    : Character(name, 90, 18, 4) {}  // Example: moderate health, decent attack

void Beastmaster::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5); // Variation: -5 to +5
    std::cout << name << " commands his beast to attack " 
              << target.getName() << ", dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
