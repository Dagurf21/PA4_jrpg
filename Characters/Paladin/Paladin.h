#ifndef PALADIN_H
#define PALADIN_H 

#include "../../Character.h"
#include <string>

class Paladin : public Character {
public:
    Paladin(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
