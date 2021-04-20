#include "Wizard.h"
#include <iostream>

Wizard::Wizard(const char* name)
    : Hero(name, 20)
{}

void Wizard::afterFightSpecialPower()
{
    if (specialPowerAvailable && HP < 40 && isAlive()) {
        specialPowerAvailable = false;
        HP *= 2;
        damage -= 15;
    }
}

void Wizard::print() const
{
    std::cout << "Wizard {\n";
    basicStatsPrint();
    std::cout << " }" << std::endl;
}

