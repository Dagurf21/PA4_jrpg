#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(const std::string &name, int health, int attackPower, int defense)
    : name(name), health(health), attackPower(attackPower), defense(defense) {}

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

void Character::takeDamage(int damage) {
    // calculate effective damage
    int actualDamage = std::max(damage - defense, 0);
    health -= actualDamage;
    std::cout << name << " takes " << actualDamage << "damage!\n";
    if (health < 0)
      health = 0;
}

bool Character::isAlive() const {
    return health > 0;
}
