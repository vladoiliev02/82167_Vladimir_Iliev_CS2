#include "Paladin.h"
#include <iostream>

Paladin::Paladin(const char* name)
        : Hero(name, 30)
{
    HP = 200;
}

void Paladin::attack(Hero& target)
{
    try {
        basicAttack(target);
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Paladin::attack(Wizard& target)
{
    try {
        basicAttack(target);
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    target.specialPower();
}

void Paladin::print() const
{
    std::cout << "Paladin {\n";
    basicStatsPrint();
    std::cout << " }\n" << std::endl;
}
