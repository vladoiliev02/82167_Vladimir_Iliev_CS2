#pragma once

#include "Hero.h"

class Wizard : public Hero {
private:
    bool specialPowerAvailable = true;

public:
    Wizard(const char* name);
    void specialPower();
    void attack(Hero& target);
    void print() const;
};