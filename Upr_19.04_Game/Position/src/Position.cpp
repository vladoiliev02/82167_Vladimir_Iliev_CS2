#include "Position.h"
#include "field.h"
#include <random>

Position::Position()
{
    x = rand() % height;
    y = rand() % (width - 1);
}