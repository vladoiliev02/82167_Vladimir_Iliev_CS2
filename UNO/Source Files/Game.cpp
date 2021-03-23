#include "Game.h"

void Game::createGame(const size_t playerCount, const size_t deckSize)
{
	this->currentCard = 29; //Because the deck will have 30 cards by default;
	this->playerCount = playerCount;
	players = new(std::nothrow) Player[playerCount];
	if (!players)
		std::cerr << "Memory for players not allocated" << std::endl;
	if (deckSize != 30) {
		deck.setSize(deckSize);
		onTheField.setSize(deckSize);
		this->currentCard = deckSize - 1; //Index of the top card in the deck on the field;
	}
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
	if (deck.getSize() == currentCard + deck.getSize()) {
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

bool Game::cardIsValid(const Card& card) const
{
	if (onTheField[currentCard].getColor() == card.getColor())
		return true;
	if (onTheField[currentCard].getNumber() == card.getNumber())
		return true;
	return false;
}

void Game::turn(Player& player, const size_t& i)
{
	deckHasEnded();
	if (!hasPlayableCards(player)) {
		player.drawCard(deck);
		std::cout << "No card can be played. You drew: " << players[i].getCard(players[i].getHandSize() - 1) << std::endl;
		system("pause");
		return;
	}
	Card card; //Card that will now be played;
	do {
		card = player.playCard();
		if (!cardIsValid(card))
			std::cerr << "Invalid choice. Try again" << std::endl;
	} while (!cardIsValid(card));
	onTheField[--currentCard] = card;
	player.removeCard(card);
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

void Game::play()
{
	size_t i = 0;
	int winner;
	while (true) {
		printGame(getPlayer(i));
		std::cout << "Player " << i << "'s turn." << std::endl;
		turn(getPlayer(i), i);
		if (isWinner(getPlayer(i))) {
			winner = i;
			break;
		}
		i++;
		if (i >= playerCount)
			i = 0;
	}

	std::cout << "Player " << i << " wins!!!" << endl;
}
