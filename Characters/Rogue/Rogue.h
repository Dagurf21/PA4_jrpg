#ifndef ROGUE_H
#define ROGUE_H

#include "../../Character.h"

class Rogue : public Character {
public:
    Rogue(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
