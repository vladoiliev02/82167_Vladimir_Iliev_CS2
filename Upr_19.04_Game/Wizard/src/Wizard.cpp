#include "Wizard.h"
#include <iostream>

Wizard::Wizard(const char* name)
    : Hero(name, 20)
{}

void Wizard::specialPower()
{
    if (specialPowerAvailable && HP < 40) {
        specialPowerAvailable = false;
        HP *= 2;
        damage -= 15;
    }
}

void Wizard::attack(Hero& target)
{
    try {
        basicAttack(target);
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Wizard::print() const
{
    std::cout << "Wizard {\n";
    basicStatsPrint();
    std::cout << " }\n" << std::endl;
}
