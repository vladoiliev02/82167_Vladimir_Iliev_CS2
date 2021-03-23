#include "Player.h"

void Player::create(const size_t handSize)
{
	if (freeSpace(handSize))
		this->handSize = handSize;
	else
		this->handSize = 3;
	for (size_t i = 0; i < handSize; i++)
		hand[i].generateRandom();
}

bool Player::freeSpace(const size_t handSize) { return (0 <= handSize && handSize <= 9); }

Player::Player()
{
	create(3);
}

Player::Player(const unsigned short handSize)
{
	create(handSize);
}

const size_t Player::getHandSize() const { return handSize; }

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

void Player::removeCard(const Card& card)
{
	size_t idx = 0;
	while (card != hand[idx])
		idx++;
	if (idx < handSize) {
		removeCard(idx);
		return;
	}
	std::cerr << "Card not found." << std::endl;
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
	if (!freeSpace(handSize))
		removeCard(chooseCard());
	hand[handSize++] = deck.topCard();
}

Card Player::playCard()
{
	const size_t choice = chooseCard();
	Card card(hand[choice]);
	return card;
}
