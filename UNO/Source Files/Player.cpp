#include "Player.h"

void Player::create(const size_t idx)
{
	if (freeSpace())
		this->handSize = handSize;
	else
		this->handSize = 3;
	for (size_t i = 0; i < handSize; i++)
		hand[i].generateRandom();
}

bool Player::freeSpace() { return (0 < handSize && handSize <= 9); }

Player::Player()
{
	create(3);
}

Player::Player(const unsigned short handSize)
{
	create(handSize);
}

const unsigned Player::getHandSize() const { return handSize; }

const Card Player::getCard(const size_t idx) const
{
	if (idx < handSize)
		return hand[idx];
	Card a; //Invalid card by default;
	return a;
}

void Player::removeCard(const size_t idx)
{
	for (size_t i = idx; i < handSize - 1; i++)
		hand[i] = hand[i + 1];
	handSize--;
}

const size_t Player::chooseCard() const
{
	std::cout << "Pick a card: ";
	size_t choice;
	do {
		std::cin >> choice;
		if (choice >= handSize)
			std::cerr << "Invalid choice." << std::endl;
	} while (choice >= handSize);
	return choice;
}

void Player::drawCard(Deck& deck)
{
	if (!freeSpace())
		removeCard(chooseCard());
	hand[handSize++] = deck.topCard();
}

Card Player::playCard()
{
	const size_t choice = chooseCard();
	Card card(hand[choice]);
	removeCard(choice);
	return card;
}
