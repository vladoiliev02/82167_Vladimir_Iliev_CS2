cmake_minimum_required(VERSION 3.19)
project(Game_character)

set(CMAKE_CXX_STANDARD 20)

include_directories(Hero
        ${CMAKE_CURRENT_SOURCE_DIR}
        Hero/src
        Paladin
        Paladin/src
        Warrior
        Warrior/src
        Wizard
        Wizard/src
        Position
        Position/src)

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

add_executable(main
        main.cpp
        ${Hero_SRC}
        ${Paladin_SRC}
        ${Warrior_SRC}
        ${Wizard_SRC}
        ${Position_SRC}
        field.cpp)
