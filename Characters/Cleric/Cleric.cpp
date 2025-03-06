#include "Cleric.h"
#include <iostream>
#include <cstdlib>

Cleric::Cleric(const std::string &name)
    : Character(name, 75, 10, 5) {}  // Example: lower attack but higher defense

void Cleric::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " smites " << target.getName() 
              << " with holy power, dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
