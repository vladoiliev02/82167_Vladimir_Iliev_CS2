#pragma once

#include "Hero.h"
#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Position.h"
#include <iostream>
#include <ctime>
#include <random>

#define EMPTY '-'

const unsigned height = 5;
const unsigned width = 10;

class Field {
    Hero** heroes = nullptr;
    unsigned numOfHeroes = 0;
    unsigned charactersInPlay = 0;
    char field[height][width];

private:
    bool characterExists(const char* name) const;
    bool canMove(const Hero& hero, int x, int y) const;
    static bool heroIsInBounds(const Hero& hero, int x, int y) ;
    bool canAttack(const Hero& attacker, const Hero& target) const;

public:
    Field() = delete;
    Field(const Field& other) = delete;
    Field& operator=(const Field& other) = delete;
    ~Field();
    explicit Field(unsigned numOfHeroes);
    void insertCharacter(Hero& character);
    void move(Hero& hero, int x, int y);
    bool canFight(const Hero& hero) const;
    bool battle(Hero& attacker, Hero& target);
    void heroDies();
    bool hasWon() const;
    void print() const;
    void printHeroList();
    Hero& getHero(unsigned idx);

};