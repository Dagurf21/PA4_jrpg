#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include "../../Character.h"

class DarkKnight : public Character {
public:
    DarkKnight(const std::string &name);
    virtual void attack(Character &target) override;
};

#endif
