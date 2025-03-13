#ifndef MAGE_H
#define MAGE_H

#include "../../Character.h"
#include <string>

class Mage : public Character {
public:
    Mage(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif

