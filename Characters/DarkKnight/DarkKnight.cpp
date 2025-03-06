#include "DarkKnight.h"
#include <iostream>
#include <cstdlib>

DarkKnight::DarkKnight(const std::string &name)
    : Character(name, 85, 22, 6) {}  // Balanced stats with a darker theme

void DarkKnight::attack(Character &target) {
    int damage = attackPower + (std::rand() % 11 - 5);
    std::cout << name << " performs a dark slash on " 
              << target.getName() << ", dealing " << damage << " damage!\n";
    target.takeDamage(damage);
}
