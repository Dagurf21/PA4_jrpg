#ifndef PALADIN_H
#define PALADIN_H 

#include "../../Character.h"

class Paladin : public Character {
public:
    Paladin(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
