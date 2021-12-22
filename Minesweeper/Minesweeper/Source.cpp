#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Logic.cpp"
#include "Resources.cpp"

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

	for (int i = 0; i < size; i++) {
		delete[] field[i];
		delete[] revealedField[i];
	}
	delete[] field;
	delete[] revealedField;

	return win;
}

int main() {
	srand(time(NULL));
	
	while (true) {
		bool win = startGame();
		int option = endGame(win);
		if (option == 2) {
			break;
		}
	}

	return 0;
}