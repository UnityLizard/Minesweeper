#include <iostream>
#include <limits>
#include "Visual.h"

using namespace std;

static int randomNumber(int limit) {
	int random = rand();
	random %= limit;

	return random;
}

static int chooseDifficulty() {
	int difficulty = 0;

	do {
		printMenu();
		cin >> difficulty;

		if (!difficulty)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		clear();
	} while (difficulty < 1 || difficulty > 3);

	return difficulty;
}

static void applyDifficulty(int difficulty, int& size, int& mines) {
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
}

static int** generateField(int size) {
	int** field = new int* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = 0;
		}
	}

	return field;
}

static bool isMine(int** field, int x, int y) {
	if (field[x][y] == -1) {
		return true;
	}

	return false;
}

static bool isRevealed(int** field, int x, int y) {
	if (field[x][y] == 1) {
		return true;
	}

	return false;
}

static bool isFlag(int** field, int x, int y) {
	if (field[x][y] == 2) {
		return true;
	}

	return false;
}

static bool isSafe(int** field, int x, int y) {
	if (field[x][y] == 0) {
		return true;
	}

	return false;
}

static void placeRemoveFlag(int** field, int x, int y, int& flags) {
	if (field[x][y] == 2) {
		field[x][y] = 0;
		flags++;
	}
	else {
		field[x][y] = 2;
		flags--;
	}
}

static void placeMines(int** field, int size, int mines, int initialX, int initialY) {
	while (mines > 0) {
		int x = randomNumber(size);
		int y = randomNumber(size);

		if (x == initialX && y == initialY) {
			continue;
		}
		if (isMine(field, x , y)) {
			continue;
		}

		field[x][y] = -1;
		mines--;
	}
}

static void revealSafeZone(int** field, int** revealedField, int size, int x, int y, int& counter) {
	if (x > 0) {
		if (!isRevealed(revealedField, x - 1, y)) {
			revealedField[x - 1][y] = 1;
			counter++;
			if (isSafe(field, x - 1, y)) {
				revealSafeZone(field, revealedField, size, x - 1, y, counter);
			}
		}
	}
	if (y > 0) {
		if (!isRevealed(revealedField, x, y - 1)) {
			revealedField[x][y - 1] = 1;
			counter++;
			if (isSafe(field, x, y - 1)) {
				revealSafeZone(field, revealedField, size, x, y - 1, counter);
			}
		}
	}
	if (x < size - 1) {
		if (!isRevealed(revealedField, x + 1, y)) {
			revealedField[x + 1][y] = 1;
			counter++;
			if (isSafe(field, x + 1, y)) {
				revealSafeZone(field, revealedField, size, x + 1, y, counter);
			}
		}
	}
	if (y < size - 1) {
		if (!isRevealed(revealedField, x, y + 1)) {
			revealedField[x][y + 1] = 1;
			counter++;
			if (isSafe(field, x, y + 1)) {
				revealSafeZone(field, revealedField, size, x, y + 1, counter);
			}
		}
	}

	if (x > 0 && y > 0) {
		if (!isRevealed(revealedField, x - 1, y - 1)) {;
			revealedField[x - 1][y - 1] = 1;
			counter++;
			if (isSafe(field, x - 1, y - 1)) {
				revealSafeZone(field, revealedField, size, x - 1, y - 1, counter);
			}
		}
	}
	if (x > 0 && y < size - 1) {
		if (!isRevealed(revealedField, x - 1, y + 1)) {
			revealedField[x - 1][y + 1] = 1;
			counter++;
			if (isSafe(field, x - 1, y + 1)) {
				revealSafeZone(field, revealedField, size, x - 1, y + 1, counter);
			}
		}
	}
	if (x < size - 1 && y > 0) {
		if (!isRevealed(revealedField, x + 1, y - 1)) {
			revealedField[x + 1][y - 1] = 1;
			counter++;
			if (isSafe(field, x + 1, y - 1)) {
				revealSafeZone(field, revealedField, size, x + 1, y - 1, counter);
			}
		}
	}
	if (x < size - 1 && y < size - 1) {
		if (!isRevealed(revealedField, x + 1, y + 1)) {
			revealedField[x + 1][y + 1] = 1;
			counter++;
			if (isSafe(field, x + 1, y + 1)) {
				revealSafeZone(field, revealedField, size, x + 1, y + 1, counter);
			}
		}
	}
}

static void revealLeft(int** revealedField, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (!(isRevealed(revealedField, i, j) || isFlag(revealedField, i, j))) {
				revealedField[i][j] = 1;
			}
		}
	}
}

static void revealAll(int** field, int** revealedField, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (isRevealed(revealedField, i, j)) {
				continue;
			}
			if (isMine(field, i, j) && isFlag(revealedField, i, j)) {
				continue;
			}
			revealedField[i][j] = 1;
		}
	}
}

static void showDangerousSquares(int** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (isMine(field, i, j)) {
				continue;
			}
			if (i > 0) {
				if (isMine(field, i - 1, j)) {
					field[i][j]++;
				}
			}
			if (j > 0) {
				if (isMine(field, i, j - 1)) {
					field[i][j]++;
				}
			}
			if (i < size - 1) {
				if (isMine(field, i + 1, j)) {
					field[i][j]++;
				}
			}
			if (j < size - 1) {
				if (isMine(field, i, j + 1)) {
					field[i][j]++;
				}
			}

			if (i > 0 && j > 0) {
				if (isMine(field, i - 1, j - 1)) {
					field[i][j]++;
				}
			}
			if (i > 0 && j < size - 1) {
				if (isMine(field, i - 1, j + 1)) {
					field[i][j]++;
				}
			}
			if (i < size - 1 && j > 0) {
				if (isMine(field, i + 1, j - 1)) {
					field[i][j]++;
				}
			}
			if (i < size - 1 && j < size - 1) {
				if (isMine(field, i + 1, j + 1)) {
					field[i][j]++;
				}
			}
		}
	}
}

static void firstReveal(int** field, int** revealedField, int size, int mines, int& flags, int& counter) {
	int x = 0;
	int y = 0;
	int action = 0;

	do {
		printField(field, revealedField, size, flags);
		printCommand();

		cin >> x;
		cin >> y;
		cin >> action;

		if (!x || !y || !action)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		x--;
		y--;

		if (x < 0 || x >= size || y < 0 || y >= size || action < 1 || action > 2) {
			action = 0;
			continue;
		}
		if (action == 2) {
			placeRemoveFlag(revealedField, x, y, flags);
		}
		if (action == 1) {
			if (isFlag(revealedField, x, y)) {
				action = 0;
				continue;
			}
			revealedField[x][y] = 1;
			counter++;
		}

	} while (action != 1);

	placeMines(field, size, mines, x, y);

	showDangerousSquares(field, size);

	if (isSafe(field, x, y)) {
		revealSafeZone(field, revealedField, size, x, y, counter);
	}
}

static bool Minesweeping(int** field, int** revealedField, int size, int mines, int& flags, int& counter) {
	int x = 0;
	int y = 0;
	int action = 0;

	while (counter < size * size) {
		printField(field, revealedField, size, flags);
		printCommand();

		cin >> x;
		cin >> y;
		cin >> action;

		if (!x || !y || !action)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		x--;
		y--;

		if (x < 0 || x >= size || y < 0 || y >= size || action < 1 || action > 2) {
			continue;
		}

		if (action == 2) {
			if (isRevealed(revealedField, x, y)) {
				continue;
			}
			placeRemoveFlag(revealedField, x, y, flags);
		}

		if (action == 1) {
			if (isRevealed(revealedField, x, y)) {
				continue;
			}
			if (isFlag(revealedField, x, y)) {
				continue;
			}

			if (isMine(field, x, y)) {
				revealAll(field, revealedField, size);

				return false;
			}

			revealedField[x][y] = 1;
			counter++;

			if (isSafe(field, x, y)) {
				revealSafeZone(field, revealedField, size, x, y, counter);
			}
		}
	}
	
	revealLeft(revealedField, size);

	return true;
}

static bool endGame(int** field, int** revealedField, int size, int flags, bool win) {
	int playAgain = 0;

	do {
		printField(field, revealedField, size, flags);
		printEndScreen(win);
		cin >> playAgain;

		if (!playAgain)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		clear();
	} while (playAgain < 1 || playAgain > 2);

	if (playAgain == 1) {
		return true;
	}

	return false;
}