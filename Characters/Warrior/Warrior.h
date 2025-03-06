#ifndef WARRIOR_H
#define WARRIOR_H

#include "../../Character.h"

class Warrior : public Character {
public:
    Warrior(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
