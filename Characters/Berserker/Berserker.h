#ifndef BERSERKER_H
#define BERSERKER_H
  
#include "../../Character.h"
#include <string>

class Berserker : public Character {
public:
    Berserker(const std::string &name);
    virtual void attack(Character &target, bool isPlayer) override;
};

#endif
