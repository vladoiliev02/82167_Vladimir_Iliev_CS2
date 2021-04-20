#include <iostream>
#include <ctime>
#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"
#include "field.h"

enum class DIRECTION {
    UP = -1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

void gameMenu(Field& field);
DIRECTION chooseDirection();
bool moveCharacter(DIRECTION direction, Field& field, int idx);
void fight(Field& field, Hero& hero);

int main()
{
    srand(time(nullptr));
    Paladin* p = new Paladin("Jivko");
    Warrior* w = new Warrior("Zdravko");
    Wizard* wz = new Wizard("Petko");

    Field field(5);

    field.insertCharacter(*p);
    field.insertCharacter(*w);
    field.insertCharacter(*wz);

    while (!field.hasWon()) {
        field.print();
        gameMenu(field);
    }

    delete p;
    delete w;
    delete wz;

    return 0;
}

void gameMenu(Field& field)
{
    std::cout << "Choose Hero: \n";
    field.printHeroList();
    int heroIdx;
    bool isValid;
    bool canFight;
    do {
        isValid = false;
        try {
            std::cin >> heroIdx;
            canFight = field.canFight(field.getHero(heroIdx));
            isValid = true;
        } catch (std::out_of_range& e) {
            std::cerr << "Invalid hero chosen" << std::endl;
        }
    } while (!isValid);

    std::cout << "Choose option\n"
              << "1. Move"
              << (canFight ? "\n2. Attack\n" : "\n");
    int option;
    bool exit = false;
    while (!exit) {
        std::cin >> option;
        switch (option) {
            case 1: {
                bool hasMoved = false;
                while (!hasMoved) {
                    DIRECTION d = chooseDirection();
                    hasMoved = moveCharacter(d, field, heroIdx);
                }
                exit = true;
                break;
            }
            case 2: {
                if (canFight) {
                    fight(field, field.getHero(heroIdx));
                    exit = true;
                    break;
                } //Else overflow to default
            }
            default:
                std::cerr << "Invalid option" << std::endl;
                break;
        }
    }
}


DIRECTION chooseDirection()
{
    while (true) {
        int option;
        std::cout << "1. Up\n2. Down\n3. Left\n4. Right" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1:
                return DIRECTION::UP;
            case 2:
                return DIRECTION::DOWN;
            case 3:
                return DIRECTION::LEFT;
            case 4:
                return DIRECTION::RIGHT;
            default:
                std::cout << "Try again" << std::endl;
        }
    }
}

bool moveCharacter(DIRECTION direction, Field& field, int idx)
{
    try {
        switch (direction) {
            case DIRECTION::UP : {
                field.move(field.getHero(idx), -1, 0);
                break;
            }
            case DIRECTION::DOWN : {
                field.move(field.getHero(idx), 1, 0);
                break;
            }
            case DIRECTION::LEFT : {
                field.move(field.getHero(idx), 0, -1);
                break;
            }
            case DIRECTION::RIGHT : {
                field.move(field.getHero(idx), 0, 1);
                break;
            }
        }
    } catch (std::out_of_range&) {
        std::cerr << "Invalid move" << std::endl;
        return false;
    }
    return true;

}


void fight(Field& field, Hero& attacker)
{
    std::cout << "Choose target: " << std::endl;
    field.printHeroList();
    int idx;
    do {
        std::cout << "Your choice:";
        std::cin >> idx;
    } while (!field.battle(attacker, field.getHero(idx)));
    std::cout << "---Attacker---\n";
    attacker.basicStatsPrint();
    std::cout << "\n----Target----\n";
    field.getHero(idx).basicStatsPrint();
    std::cout << std::endl;
}
