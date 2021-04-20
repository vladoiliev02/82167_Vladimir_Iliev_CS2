#pragma once

#include "Hero.h"
#include "Wizard.h"

class Paladin : public Hero {

public:
    Paladin(const char* name);
    void print() const override;
};