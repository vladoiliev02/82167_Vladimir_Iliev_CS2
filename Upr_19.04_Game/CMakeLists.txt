cmake_minimum_required(VERSION 3.19)
project(Game_character)

set(CMAKE_CXX_STANDARD 20)

include_directories(Hero
        Hero/src
        Paladin
        Paladin/src
        Warrior
        Warrior/src
        Wizard
        Wizard/src
        Position
        Position/src
        Field
        Field/src)

set(Hero_SRC
        Hero/src/Hero.cpp)

set(Paladin_SRC
        Paladin/src/Paladin.cpp)

set(Warrior_SRC
        Warrior/src/Warrior.cpp)

set(Wizard_SRC
        Wizard/src/Wizard.cpp)

set(Position_SRC
        Position/src/Position.cpp)

set(Field_SRC
        Field/src/field.cpp)

add_executable(main
        main.cpp
        ${Position_SRC}
        ${Hero_SRC}
        ${Paladin_SRC}
        ${Warrior_SRC}
        ${Wizard_SRC}
        ${Field_SRC})
