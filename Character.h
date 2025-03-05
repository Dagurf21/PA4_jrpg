#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;
    int defense;

public:
    Character(const std::string &name, int health, int attackPower, int defense);
    virtual ~Character();

    std::string getName() const;
    int getHealth() const;
    void setHealth(int hp);

    // pure virtual function so every derived class can implement its own attack 
    virtual void attack(Character &target) = 0;

    // applies damage after considering defense
    void takeDamage(int damage);
    bool isAlive() const;
};

#endif 
