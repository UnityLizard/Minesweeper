#include <iostream>
#include "Visual.cpp"

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
		clear();
	} while (difficulty < 1 || difficulty > 3);

	return difficulty;
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

static bool isBomb(int** field, int x, int y) {
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

static int** placeRemoveFlag(int** field, int x, int y) {
	if (field[x][y] == 2) {
		field[x][y] = 0;
	}
	else {
		field[x][y] = 2;
	}

	return field;
}

static int** placeMines(int** field, int size, int mines, int initialX, int initialY) {
	while (mines > 0) {
		int x = randomNumber(size);
		int y = randomNumber(size);

		if (x == initialX && y == initialY) {
			continue;
		}
		if (field[x][y] == -1) {
			continue;
		}

		field[x][y] = -1;
		mines--;
	}

	return field;
}

static void firstReveal(int** field, int** revealedField, int size, int mines, int& flags) {
	int x = 0;
	int y = 0;
	int action = 0;

	do {
		printField(size, flags);

		cin >> x;
		cin >> y;
		cin >> action;

		x--;
		y--;

		if (x < 0 || x >= size || y < 0 || y >= size || action < 1 || action > 2) {
			action = 0;
			continue;
		}
		if (action == 2) {
			placeRemoveFlag(revealedField, x, y);
		}
		if (action == 1) {
			if (isFlag(revealedField, x, y)) {
				action = 0;
				continue;
			}
		}

	} while (action != 1);
	placeMines(field, size, mines, x, y);
}

static int** showDangerousSquares(int** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[i][j] == -1) {
				continue;
			}
			if (i > 0) {
				if (field[i - 1][j] == -1) {
					field[i][j]++;
				}
			}
			if (j > 0) {
				if (field[i][j - 1] == -1) {
					field[i][j]++;
				}
			}
			if (i < size - 1) {
				if (field[i + 1][j] == -1) {
					field[i][j]++;
				}
			}
			if (j < size - 1) {
				if (field[i][j + 1] == -1) {
					field[i][j]++;
				}
			}

			if (i > 0 && j > 0) {
				if (field[i - 1][j - 1] == -1) {
					field[i][j]++;
				}
			}
			if (i > 0 && j < size - 1) {
				if (field[i - 1][j + 1] == -1) {
					field[i][j]++;
				}
			}
			if (i < size - 1 && j > 0) {
				if (field[i + 1][j - 1] == -1) {
					field[i][j]++;
				}
			}
			if (i < size - 1 && j < size - 1) {
				if (field[i + 1][j + 1] == -1) {
					field[i][j]++;
				}
			}
		}
	}

	return field;
}

static bool Minesweeping(int** field, int** revealedField, int size, int mines, int& flags) {
	int counter = mines + 1;
	int x = 0;
	int y = 0;
	int action = 0;

	while (counter < size * size) {
		printField(size, flags);

		cin >> x;
		cin >> y;
		cin >> action;

		x--;
		y--;

		if (x < 0 || x >= size || y < 0 || y >= size || action < 1 || action > 2) {
			continue;
		}

		if (action == 2) {
			if (isRevealed(revealedField, x, y)) {
				continue;
			}
			placeRemoveFlag(revealedField, x, y);
		}

		if (action == 1) {
			if (isRevealed(revealedField, x, y)) {
				continue;
			}
			if (isFlag(revealedField, x, y)) {
				continue;
			}

			if (isBomb(field, x, y)) {
				return false;
			}

			revealedField[x][y] = 1;
			counter++;
		}
	}

	return true;
}