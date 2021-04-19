#include <iostream>
#include <cstring>
#include "field.h"


void Field::print()
{
    for (unsigned i = 0; i < height; i++)
        std::cout << field[i] << '\n';
    std::cout << std::endl;
}

Field::Field(unsigned numOfHeroes)
        : numOfHeroes(numOfHeroes), charactersInPlay(0)
{
    for (unsigned i = 0; i < height; i++) {
        for (unsigned j = 0; j < width - 1; j++)
            field[i][j] = '_';
        field[i][width - 1] = '\0';
    }
    heroes = new Hero* [numOfHeroes];
}

void Field::insertCharacter(Hero& character)
{
    if (charactersInPlay >= numOfHeroes)
        throw std::out_of_range("Field::insertCharacter");

    if (characterExists(character.getName()))
        throw std::invalid_argument("Character exists");

    try {
        heroes[charactersInPlay++] = &character;
    } catch (std::bad_alloc&) {
        std::cerr << "Hero not allocated, try later" << std::endl;
        charactersInPlay--;
        return;
    }
    field[character.x][character.y] = character.getName()[0];
}

bool Field::characterExists(const char* name) const
{
    for (unsigned i = 0; i < charactersInPlay; i++)
        if (strcmp(name, heroes[i]->getName()) == 0)
            return true;
    return false;
}

Field::~Field()
{
    delete[] heroes;
}

void Field::move(Hero& hero, int x, int y)
{
    if (!canMove(hero, x, y))
        throw std::out_of_range("Field::move()");
    field[hero.x][hero.y] = EMPTY;
    hero.x += x;
    hero.y += y;
    field[hero.x][hero.y] = hero.getName()[0];
}

bool Field::canMove(const Hero& hero, int x, int y) const
{
    return heroIsInBounds(hero, x, y) &&
           field[hero.x + x][hero.y + y] == EMPTY;
}

bool Field::heroIsInBounds(const Hero& hero, int x, int y)
{
    return (hero.x + x < height && hero.x + x >= 0) &&
           (hero.y + y < width - 1 && hero.y + y >= 0);
}

bool Field::canFight(const Hero& hero) const
{
    bool can_fight = false;
    int dx[24] = {2, -2,  0, 0, 2, -2,  2, -2, 1, -1,  0, 0, 1, -1,  1, -1, 2, -2,  2, -2, 1, 1, -1, -1}; //Some are missing :(((
    int dy[24] = {0,  0, -2, 2, 2,  2, -2, -2, 0,  0, -1, 1, 1, -1, -1,  1, 1,  1, -1, -1, 2, -2, 2, -2}; //Some are missing :(((
    for (unsigned i = 0; i < 12; i++) {
        if (heroIsInBounds(hero, dx[i], dy[i])) {
            if (field[hero.x + dx[i]][hero.y + dy[i]] != EMPTY) {
                    return true;
            }
        }
    }
}

void Field::heroDies()
{
    for (unsigned i = 0; i < charactersInPlay; i++)
        if (!heroes[i]->isAlive()) {
            heroes[i] = nullptr;
            while (i != charactersInPlay - 1) {
                heroes[i] = heroes[i - 1];
                i++;
            }
            heroes[--charactersInPlay] = nullptr;
            return;
        }
}

bool Field::hasWon() const
{ return charactersInPlay == 1; }

Hero& Field::getHero(unsigned idx)
{
    return *heroes[idx];
}

void Field::printHeroList()
{
    for (unsigned i = 0; i < charactersInPlay; i++)
        std::cout << i << ": " << heroes[i]->getName() << std::endl;
}


/*
 * bool canFight():
 return (heroIsInBounds(hero, 2, 0) && field[hero.x + 2][hero.y] != EMPTY) ||
           (heroIsInBounds(hero, -2, 0) && field[hero.x - 2][hero.y] != EMPTY) ||
           (heroIsInBounds(hero, 0, -2) && field[hero.x][hero.y - 2] != EMPTY) ||
           (heroIsInBounds(hero, 0, 2) && field[hero.x][hero.y + 2] != EMPTY) ||
           (heroIsInBounds(hero, 1, 0) && field[hero.x + 1][hero.y] != EMPTY) ||
           (heroIsInBounds(hero, -1, 0) && field[hero.x - 1][hero.y] != EMPTY) ||
           (heroIsInBounds(hero, 0, -1) && field[hero.x][hero.y - 1] != EMPTY) ||
           (heroIsInBounds(hero, 0, 1) && field[hero.x][hero.y + 1] != EMPTY);
 */

