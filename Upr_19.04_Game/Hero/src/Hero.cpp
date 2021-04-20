#include "Hero.h"
#include <iostream>
#include <cstring>
#include <ctime>

Hero::Hero()
        : Position(), HP(0), damage(0)
{
    strcpy(this->name, "Not Set");
}

Hero::Hero(const char* name, int damage)
        : Position(), damage(damage)
{
    if (strlen(name) > 10)
        throw std::length_error("Name cannot be longer than 10 characters");
    strcpy(this->name, name);
}

Hero::Hero(const Hero& other)
{
    if (strlen(name) > 10)
        throw std::length_error("Name cannot be longer than 10 characters");
    strcpy(this->name, other.name);
    HP = other.HP;
    damage = other.damage;
}

int& Hero::getHP()
{ return HP; }

const char* Hero::getName() const
{ return name; }

int Hero::getAttackForce() const
{ return damage; }

bool Hero::isAlive() const
{ return HP > 0; }

void Hero::basicAttack(Hero& target)
{
    if (this == &target || (!isAlive()))
        throw std::logic_error("attack error");
    target.HP -= damage;
}

void Hero::basicStatsPrint() const
{
    std::cout << "Name: " << name
              << "\nHP: " << HP
              << "\nDamage: " << damage;
}

void Hero::attack(Hero& other)
{
    basicAttack(other);
}

void Hero::afterFightSpecialPower()
{
    ;
}


