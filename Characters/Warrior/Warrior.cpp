#include "Warrior.h"
#include <iostream>
#include <cstdlib>

Warrior::Warrior(const std::string &name)
    : Character(name, 100, 20, 5) {} // Stats

void Warrior::attack(Character &target) {
    // Sword swing attack, random variant in damage it deals
    int damage = attackPower + (std::rand() % 11 - 5); // +-5
    std::cout << name << " swings a sword at " << target.getName()
              << " dealing " << damage << "damage!\n";
    target.takeDamage(damage);
}
