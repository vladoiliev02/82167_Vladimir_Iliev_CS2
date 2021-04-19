#pragma once

#include "Hero.h"
#include "Wizard.h"

class Paladin : public Hero {

public:
    Paladin(const char* name);
    void attack(Hero& target);
    void attack(Wizard& target);
    void print() const;
};