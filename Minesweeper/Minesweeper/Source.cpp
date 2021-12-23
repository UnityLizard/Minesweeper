#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Logic.h"

using namespace std;

bool startGame() {
	int difficulty = chooseDifficulty();

	int size = 0;
	int mines = 0;

	applyDifficulty(difficulty, size, mines);

	int** field = generateField(size);
	int** revealedField = generateField(size);

	int flags = mines;
	int counter = mines;

	firstReveal(field, revealedField, size, mines, flags, counter);

	bool win = Minesweeping(field, revealedField, size, mines, flags, counter);

	bool playAgain = endGame(field, revealedField, size, flags, win);

	for (int i = 0; i < size; i++) {
		delete[] field[i];
		delete[] revealedField[i];
	}
	delete[] field;
	delete[] revealedField;

	return playAgain;
}

int main() {
	srand(time(NULL));
	
	while (true) {
		bool playAgain = startGame();
		if (!playAgain) {
			break;
		}
	}

	return 0;
}