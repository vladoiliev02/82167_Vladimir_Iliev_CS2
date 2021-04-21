#include "field.h"

void gameMenu(Field&);

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

    std::cout << "---Winner---" << std::endl;
    field.printHeroList();

    delete p;
    delete w;
    delete wz;

    return 0;
}

DIRECTION chooseDirection();
bool moveCharacter(DIRECTION, Field&, int);
void fight(Field&, Hero&);

void gameMenu(Field& field)
{
    std::cout << "Choose a Hero: \n";
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
    Hero* target = nullptr;
    do {
        std::cout << "Your choice:";
        std::cin >> idx;
        try {
            target = &field.getHero(idx);
        } catch (std::out_of_range&) {
            std::cerr << "Invalid choice" << std::endl;
            target = nullptr;
        }
    } while (!target || !field.battle(attacker, *target));
    std::cout << "\n---Attacker---\n";
    attacker.print();
    std::cout << "\n----Target----\n";
    target->print();
    if (!target->isAlive())
        std::cout << "-Target-Dead-" << std::endl;
    std::cout << std::endl;
}
