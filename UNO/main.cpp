#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"

int main()
{
	Game UNO(2, 10);
	size_t i = 0;
	int winner;
	while (true) {
		UNO.printGame(UNO.getPlayer(i));
		UNO.turn(UNO.getPlayer(i), i);
		if (UNO.isWinner(UNO.getPlayer(i))) {
			winner = i;
			break;
		}
		i++;
		if (i >= 2)
			i = 0;
	}

	std::cout << "Player " << i << " wins!!!" << endl;

	return 0;
}