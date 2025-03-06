#include "Mage.h"
#include <iostream>
#include <cstdlib>

Mage::Mage(const std::string &name)
    : Character(name, 70, 25, 3) {} // High attack low health

void Mage::attack(Character &target) {
    // cast fireball, random damage variation
    int damage = attackPower + (std::rand() % 11 - 5); // +- 5
    
    // Let player choose 

    std::cout << name << " casts fireball at " << target.getName()
              << " dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
