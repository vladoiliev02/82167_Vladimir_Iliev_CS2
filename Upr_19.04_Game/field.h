#pragma once

#include "Hero.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"

#define EMPTY '_'

const unsigned height = 6;
const unsigned width = 15;

class Field : public Hero {
    Hero** heroes = nullptr;
    unsigned numOfHeroes = 0;
    unsigned charactersInPlay = 0;
    char field[height][width];

private:
    bool characterExists(const char* name) const;
    bool canMove(const Hero& hero, int x, int y) const;
    static bool heroIsInBounds(const Hero& hero, int x, int y) ;

public:
    Field() = delete;
    ~Field();
    explicit Field(unsigned numOfHeroes);
    void insertCharacter(Hero& character);
    void move(Hero& hero, int x, int y);
    bool canFight(const Hero& hero) const;
    void heroDies();
    bool hasWon() const;
    void print();
    void printHeroList();
    Hero& getHero(unsigned idx);

};