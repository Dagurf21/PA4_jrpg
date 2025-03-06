#include "Berserker.h"
#include <iostream>
#include <cstdlib>

Berserker::Berserker(const std::string &name)
    : Character(name, 80, 30, 2) {}  // Example: lower health, high attack

void Berserker::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " unleashes a furious strike on " 
              << target.getName() << ", dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
