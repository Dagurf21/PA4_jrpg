#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(const std::string &name, int health, int attackPower, int defense)
    : name(name), health(health), attackPower(attackPower), defense(defense), defending(false) {}

Character::~Character() {}

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int hp) {
    health = hp;
}

void Character::defend() {
    std::cout << "Debug defend() char.cpp";
    defending = true;
    std::cout << name << " braces for next attack ! \n";
}

void Character::takeDamage(int damage) {
    // calculate effective damage
    int effectiveDamage = std::max(damage - defense, 0);
    
    if (defending) {
        effectiveDamage /= 2;
        std::cout << name << " defended! Damage is reduced. \n";
        defending = false;
    }
    health -= effectiveDamage;
    std::cout << name << " takes " << effectiveDamage << " damage!\n";

    if (health < 0)
      health = 0;
}

bool Character::isAlive() const {
    return health > 0;
}
