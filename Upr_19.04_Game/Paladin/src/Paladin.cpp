#include "Paladin.h"
#include <iostream>

Paladin::Paladin(const char* name)
        : Hero(name, 30)
{
    HP = 200;
}

//void Paladin::attack(Wizard& target)
//{
//    basicAttack(target);
//    target.afterFightSpecialPower();
//}

void Paladin::print() const
{
    std::cout << "Paladin {\n";
    basicStatsPrint();
    std::cout << " }" << std::endl;
}
