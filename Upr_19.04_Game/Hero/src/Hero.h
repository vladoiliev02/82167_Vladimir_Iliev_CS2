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


public:
    void basicStatsPrint() const;
    void basicAttack(Hero& target); //move to protected

    int& getHP();
    const char* getName() const;
    int getAttackForce() const;
    bool isAlive() const;
};