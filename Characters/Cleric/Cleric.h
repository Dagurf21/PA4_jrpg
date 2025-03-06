#ifndef CLERIC_H
#define CLERIC_H

#include "../../Character.h"

class Cleric : public Character {
public:
    Cleric(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
