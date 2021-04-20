#pragma once

#include "Hero.h"
#include "Wizard.h"

class Warrior : public Hero {
private:
    void lifeSteal();
    void onKill(const Hero& target);

public:
    Warrior(const char* name);
    void attack(Hero& target) override;
    void print() const override;
};