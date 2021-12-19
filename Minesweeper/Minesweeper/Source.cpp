#include <iostream>
#include "Logic.cpp"
#include "Resources.cpp"

using namespace std;

void startGame() {
	int difficulty = chooseDifficulty();

	int size = 0;
	int mines = 0;

	switch (difficulty) {
	case 1:
		size = EASY_SIZE;
		mines = EASY_MINES;
		break;
	case 2:
		size = MEDIUM_SIZE;
		mines = MEDIUM_MINES;
		break;
	case 3:
		size = HARD_SIZE;
		mines = HARD_MINES;
		break;
	}

	int** field = generateField(size);
	int** revealedField = generateRevealedField(size);

	firstReveal(field, revealedField, size, mines);

	int counter = mines + 1;

	/*while (counter <= size * size) {
		int x, y, action;


	}*/




	int a = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (field[i][j] == -1) {
				a++;
			}
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
	cout << a << endl;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << revealedField[i][j] << " ";
		}
		cout << endl;
	}







	for (int i = 0; i < size; i++) {
		delete[] field[i];
		delete[] revealedField[i];
	}
	delete[] field;
	delete[] revealedField;
}

int main() {
	startGame();

	return 0;
}