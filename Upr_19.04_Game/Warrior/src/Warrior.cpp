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

void Warrior::attack(Wizard& target)
{
    try {
        basicAttack(target);
    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    target.specialPower();
    lifeSteal();
    onKill(target);
}

void Warrior::print() const
{
    std::cout << "Warrior {\n";
    basicStatsPrint();
    std::cout << " }\n" << std::endl;
}
