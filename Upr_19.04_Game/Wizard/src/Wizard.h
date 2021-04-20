#pragma once

#include "Hero.h"

class Wizard : public Hero {
private:
    bool specialPowerAvailable = true;

public:
    Wizard(const char* name);
    void afterFightSpecialPower() override;
    void print() const override;
};