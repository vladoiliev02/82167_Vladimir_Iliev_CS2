#pragma once
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game {
private:
	size_t playerCount;
	Player* players;
	Deck deck;
	Deck onTheField;
	size_t currentCard; //Holds the index of the current card on the field;

public:
	Game();
	Game(const size_t playerCount);
	Game(const size_t playerCount, const size_t deckSize);
	~Game();

private: 
	void createGame(const size_t playerCount, const size_t deckSize = 30);
	void deleteGame();
	bool cardIsValid(const Card& card);
	bool hasPlayableCards(const Player& player);
	void deckHasEnded();

public:
	Player& getPlayer(const size_t idx) const;
	void turn(Player& player, const size_t& i); //i keeps track of the player whose turn it is;
	bool isWinner(const Player& player);
	void printGame(const Player& player) const;
};