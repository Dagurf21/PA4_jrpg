#ifndef CLERIC_H
#define CLERIC_H

#include "../../Character.h"
#include <string>

class Cleric : public Character {
public:
    Cleric(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
