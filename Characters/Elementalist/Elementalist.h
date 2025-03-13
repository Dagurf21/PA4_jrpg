#ifndef ELEMENTALIST_H
#define ELEMENTALIST_H

#include "../../Character.h"
#include <string>

class Elementalist : public Character {
public:
    Elementalist(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
