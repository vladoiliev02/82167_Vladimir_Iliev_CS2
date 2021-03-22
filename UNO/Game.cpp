#include "Game.h"

void Game::createGame(const size_t playerCount, const size_t deckSize)
{
	this->currentCard = 29; //Because the deck will have 30 cards;
	this->playerCount = playerCount;
	players = new(std::nothrow) Player[playerCount];
	if (!players)
		std::cerr << "Memory for players not allocated" << std::endl;
	if (deckSize != 30) {
		deck.setSize(deckSize);
		onTheField.setSize(deckSize);
		this->currentCard = deckSize - 1; //Index of the top card in the deck on the field;
	}
	for (size_t i = 0; i < deck.getSize(); i++)
		deck[i].generateRandom();
}

void Game::deleteGame() { delete[] players; }

Game::Game() { createGame(2); }

Game::Game(const size_t playerCount) { createGame(playerCount); }

Game::Game(const size_t playerCount, const size_t deckSize) { createGame(playerCount, deckSize); }

Game::~Game() {	deleteGame(); }

Player& Game::getPlayer(const size_t idx) const 
{ 
	if (idx < playerCount)
		return players[idx];
	return players[playerCount - 1]; //If idx is out of bounds return last player;
}

void Game::deckHasEnded()
{
	if (deck.getSize() == currentCard) {
		deck = onTheField;
		currentCard = deck.getSize() - 1;
	}
}

bool Game::hasPlayableCards(const Player& player)
{
	for (size_t i = 0; i < player.getHandSize(); i++)
		if (cardIsValid(player.getCard(i)))
			return true;
	return false;
}

bool Game::cardIsValid(const Card& card)
{
	if (onTheField[currentCard].getColor() == card.getColor())
		return true;
	if (onTheField[currentCard].getNumber() == card.getNumber())
		return true;
	return false;
}

void Game::turn(Player& player, const size_t& i)
{
	cout << "Player" << i << "'s turn." << endl;
	deckHasEnded();
	if (!hasPlayableCards(player)) {
		player.drawCard(deck);
		return;
	}
	Card card; //Card that will now be played;
	do {
		card = player.playCard();
		if (!cardIsValid(card))
			std::cerr << "Invalid choice. Try again" << std::endl;
	} while (!cardIsValid(card));
	onTheField[currentCard] = card;
	currentCard -= 1;
}

bool Game::isWinner(const Player& player)
{
	if (player.getHandSize() == 0)
		return true;
	return false;
}

void Game::printGame(const Player& player) const
{
	system("cls");
	std::cout << "Current card:        " << onTheField[currentCard] << std::endl;
	for (size_t i = 0; i < player.getHandSize(); i++)
		std::cout << i << " : " << player.getCard(i) << std::endl;
}
