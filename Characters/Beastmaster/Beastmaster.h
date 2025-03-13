#ifndef BEASTMASTER_H
#define BEASTMASTER_H

#include "../../Character.h"
#include <string>

class Beastmaster : public Character {
public:
    Beastmaster(const std::string &name);
    virtual void attack(Character &target, bool isPayer) override;
};

#endif
