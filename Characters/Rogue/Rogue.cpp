#include "Rogue.h"
#include <iostream>
#include <cstdlib>

Rogue::Rogue(const std::string &name)
    : Character(name, 75, 20, 4) {}  // Agile attacker with moderate health

void Rogue::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " swiftly attacks " << target.getName() 
              << " with a quick stab, dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
