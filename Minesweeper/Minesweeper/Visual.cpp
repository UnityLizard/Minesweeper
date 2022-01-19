#include "Visual.h"

void clear() {
	cout << "\x1B[2J\x1B[H";
}

void printMenu() {
	clear();
	cout << ' ' << UPPER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << UPPER_RIGHT_CORNER << endl;

	cout << ' ' << VERTICAL_LINE;
	purple();
	cout << " MINESWEEPER ";
	reset();
	cout << VERTICAL_LINE << endl;

	cout << ' ' << LOWER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << LOWER_RIGHT_CORNER << endl;

	cout << endl;
	cout << " 1. ";
	green();
	cout << "EASY" << endl;
	reset();
	cout << " 2. ";
	yellow();
	cout << "MEDIUM" << endl;
	reset();
	cout << " 3. ";
	red();
	cout << "HARD" << endl;
	reset();
	cout << endl;

	cout << " >> ";
}

void printField(int** field, int** revealedField, int size, int flags) {
	clear();
	cout << endl;
	for (int i = 0; i < 2 * (size + 1); i++) {
		cout << ' ';
	}
	orange();
	cout << FLAG;
	reset();
	cout << ": " << flags << endl;

	for (int i = 0; i <= size + 1; i++) {
		if (i == 0) {
			cout << ' ' << ' ' << ' ' << UPPER_LEFT_CORNER;
			for (int j = 0; j < size; j++) {
				cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << UPPER_EDGE;
			}
			cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << UPPER_RIGHT_CORNER << endl;

			cout << ' ' << ' ' << ' ' << VERTICAL_LINE;
			for (int j = 0; j <= size; j++) {
				if (j == 0) {
					cout << ' ' << '#' << ' ' << VERTICAL_LINE;
				}
				else if (j > 0 && j < 10) {
					cout << ' ';
					cyan();
					cout << j;
					reset();
					cout << ' ' << VERTICAL_LINE;
				}
				else {
					cyan();
					cout << j;
					reset();
					cout << ' ' << VERTICAL_LINE;
				}
			}
			cout << endl;
		}

		else if (i == size + 1) {
			cout << ' ' << ' ' << ' ' << LOWER_LEFT_CORNER;
			for (int j = 0; j < size; j++) {
				cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << LOWER_EDGE;
			}
			cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << LOWER_RIGHT_CORNER << endl;
		}

		else {
			cout << ' ' << ' ' << ' ' << LEFT_EDGE;
			for (int j = 0; j < size; j++) {
				cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << CENTER;
			}
			cout << HORIZONTAL_LINE << HORIZONTAL_LINE << HORIZONTAL_LINE << RIGHT_EDGE << endl;

			cout << ' ' << ' ' << ' ' << VERTICAL_LINE;
			if (i < 10) {
				cout << ' ';
				cyan();
				cout << i;
				reset();
				cout << ' ' << VERTICAL_LINE;
			}
			else {
				cyan();
				cout << i;
				reset();
				cout << ' ' << VERTICAL_LINE;
			}
			for (int j = 0; j < size; j++) {
				cout << ' ';

				if (revealedField[i - 1][j] == 0) {
					cout << ' ';
				}
				else if (revealedField[i - 1][j] == 2) {
					orange();
					cout << FLAG;
					reset();
				}
				else {
					if (field[i - 1][j] == -1) {
						gray();
						cout << MINE;
						reset();
					}
					else if (field[i - 1][j] == 0) {
						cout << SQUARE;
					}
					else {
						color(field[i - 1][j]);
					}
				}

				cout << ' ' << VERTICAL_LINE;
			}
			cout << endl;
		}
	}
	cout << endl;
}

void printCommand() {
	cout << "   >> row-column-reveal(1)/(un)mark(2)" << endl;
	cout << "   >> ";
}

void printEndScreen(bool win) {
	if (win) {
		cout << ' ' << UPPER_LEFT_CORNER;
		for (int i = 0; i < 9; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << UPPER_RIGHT_CORNER << endl;

		cout << ' ' << VERTICAL_LINE;
		green();
		cout << " YOU WIN ";
		reset();
		cout << VERTICAL_LINE << endl;

		cout << ' ' << LOWER_LEFT_CORNER;
		for (int i = 0; i < 9; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << LOWER_RIGHT_CORNER << endl;
	}

	else {
		cout << ' ' << UPPER_LEFT_CORNER;
		for (int i = 0; i < 10; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << UPPER_RIGHT_CORNER << endl;

		cout << ' ' << VERTICAL_LINE;
		orange();
		cout << " YOU LOSE ";
		reset();
		cout << VERTICAL_LINE << endl;

		cout << ' ' << LOWER_LEFT_CORNER;
		for (int i = 0; i < 10; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << LOWER_RIGHT_CORNER << endl;
	}

	cout << endl;
	cout << " 1. ";
	cyan();
	cout << "PLAY AGAIN" << endl;
	reset();
	cout << " 2. ";
	purple();
	cout << "EXIT" << endl;
	reset();
	cout << endl;

	cout << " >> ";
}