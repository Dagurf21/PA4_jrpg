#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include "../../Character.h"
#include <string>

class DarkKnight : public Character {
public:
    DarkKnight(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
