#pragma once

#include "Position.h"


class Hero : public Position {
protected:
    char name[11];
    int HP = 100;
    int damage;

    Hero();
    Hero(const char* name, int damage);
    Hero(const Hero& other);
    Hero& operator=(const Hero& other) = delete;
    Hero& operator=(Hero&& other) = delete;

    void basicAttack(Hero& target); //move to protected
    void basicStatsPrint() const;

public:
    virtual void afterFightSpecialPower();
    virtual void attack(Hero& other);
    virtual void print() const = 0;

    int& getHP();
    const char* getName() const;
    int getAttackForce() const;
    bool isAlive() const;
};

