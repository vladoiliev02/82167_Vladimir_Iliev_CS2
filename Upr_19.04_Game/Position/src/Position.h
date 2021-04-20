#pragma once

enum class DIRECTION {
    UP = -1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

class Position {
public:
    int x;
    int y;

    Position();
};