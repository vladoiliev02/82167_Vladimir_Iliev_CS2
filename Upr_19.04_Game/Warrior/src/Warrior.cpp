#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const char* name)
    : Hero(name, 20)
{}

void Warrior::lifeSteal()
{
    if (HP <= 95)
        HP += 5;
}

void Warrior::onKill(const Hero& target)
{
    if (!target.isAlive()) {
        if (HP < 30)
            HP *= 2;
        else
            HP = 100;
    }
}

void Warrior::attack(Hero& target)
{
    basicAttack(target);
    lifeSteal();
    onKill(target);
}

void Warrior::print() const
{
    std::cout << "Warrior {\n";
    basicStatsPrint();
    std::cout << " }" << std::endl;
}
