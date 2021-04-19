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
    std::cin >> heroIdx;
    bool canFight = field.canFight(field.getHero(heroIdx));
    std::cout << "Choose option\n"
              << "1. Move\n"
              << (canFight ? "2. Attack" : "\n")
              << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        case 1: {
            bool hasMoved = false;
            while (!hasMoved) {
                DIRECTION d = chooseDirection();
                hasMoved = moveCharacter(d, field, heroIdx);
            }
            break;
        }
        case 2: {
            if (canFight) {
                fight(field, field.getHero(heroIdx));
                break;
            } //Else overflow to default
        }
        default:
            std::cerr << "Invalid option" << std::endl;
            break;
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


void fight(Field& field, Hero& hero)
{
    std::cout << "Choose target" << std::endl;
    field.printHeroList();
    int idx;
    std::cin >> idx; //Check that only targets in range can be attacked;
    hero.basicAttack(field.getHero(idx)); //Has to be changed to specific character attack;
    std::cout << "Attacker:\n ";
    hero.basicStatsPrint();
    std::cout << "\nTarget:\n ";
    field.getHero(idx).basicStatsPrint();
    std::cout << std::endl;
}
