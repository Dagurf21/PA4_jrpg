#ifndef WARRIOR_H
#define WARRIOR_H

#include "../../Character.h"
#include <string>


class Warrior : public Character {
public:
    Warrior(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
