#include "Paladin.h"
#include <iostream>
#include <cstdlib>

Paladin::Paladin(const std::string &name)
    : Character(name, 95, 18, 8) {}  // Higher health and defense, moderate attack

void Paladin::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " strikes " << target.getName() 
              << " with a holy blade, dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
