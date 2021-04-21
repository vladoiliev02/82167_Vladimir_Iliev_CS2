#pragma once

#include "Position.h"


class Hero : public Position {
protected:
    char name[11];
    int HP = 100;
    int damage;

    Hero(const char* name, int damage);

    void basicAttack(Hero& target);
    void basicStatsPrint() const;

public:
    Hero() =delete;
    Hero(const Hero& other) = delete;
    Hero& operator=(const Hero& other) = delete;
    Hero& operator=(Hero&& other) = delete;

    virtual void afterFightSpecialPower();
    virtual void attack(Hero& other);
    virtual void print() const = 0;

    int& getHP();
    const char* getName() const;
    int getAttackForce() const;
    bool isAlive() const;
};

