#ifndef BERSERKER_H
#define BERSERKER_H

#include "../../Character.h"

class Berserker : public Character {
public:
    Berserker(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
