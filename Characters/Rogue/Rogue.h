#ifndef ROGUE_H
#define ROGUE_H

#include "../../Character.h"
#include <string>

class Rogue : public Character {
public:
    Rogue(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
