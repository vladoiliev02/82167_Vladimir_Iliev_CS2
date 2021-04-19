#include "Position.h"
#include "field.h"
#include <random>
#include <ctime>

Position::Position()
{
    x = rand() % height;
    y = rand() % (width - 1);
}