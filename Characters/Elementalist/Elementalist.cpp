#include "Elementalist.h"
#include <iostream>
#include <cstdlib>

Elementalist::Elementalist(const std::string &name)
    : Character(name, 70, 24, 3) {}  // Lower health, high magical attack

void Elementalist::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " unleashes elemental fury at " 
              << target.getName() << ", dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
