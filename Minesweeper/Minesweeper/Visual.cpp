#include <iostream>
#include "Resources.cpp"

using namespace std;

static void clear()
{
	cout << "\x1B[2J\x1B[H";
}

static void printMenu() {
	clear();
	cout << ' ' << UPPER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << UPPER_RIGHT_CORNER << endl;

	cout << ' ' << VERTICAL_LINE << " MINESWEEPER " << VERTICAL_LINE << endl;//color

	cout << ' ' << LOWER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << LOWER_RIGHT_CORNER << endl;

	cout << endl;
	cout << " 1. " << "EASY" << endl;//color
	cout << " 2. " << "MEDIUM" << endl;//color
	cout << " 3. " << "HARD" << endl;//color
	cout << endl;

	cout << " >> ";
}

static void printField(int** field, int** revealedField, int size, int flags) {
	clear();
	cout << endl;
	for (int i = 0; i < 2 * (size + 1); i++) {
		cout << ' ';
	}
	cout << FLAG << ": " << flags << endl;

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
					cout << ' ' << j << ' ' << VERTICAL_LINE;
				}
				else {
					cout << j << ' ' << VERTICAL_LINE;
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
				cout << ' ' << i << ' ' << VERTICAL_LINE;
			}
			else {
				cout << i << ' ' << VERTICAL_LINE;
			}
			for (int j = 0; j < size; j++) {
				cout << ' ';

				if (revealedField[i - 1][j] == 0) {
					cout << ' ';
				}
				else if (revealedField[i - 1][j] == 2) {
					cout << FLAG;//color
				}
				else {
					if (field[i - 1][j] == -1) {
						cout << MINE;//color
					}
					else if (field[i - 1][j] == 0) {
						cout << SQUARE;//color
					}
					else {
						cout << field[i - 1][j];//color
					}
				}

				cout << ' ' << VERTICAL_LINE;
			}
			cout << endl;
		}
	}
	cout << endl;

	cout << "   >> row-column-reveal(1)/(un)mark(2)" << endl;
	cout << "   >> ";
}

static void printEndScreen(bool win) {
	clear();

	if (win) {
		cout << ' ' << UPPER_LEFT_CORNER;
		for (int i = 0; i < 9; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << UPPER_RIGHT_CORNER << endl;

		cout << ' ' << VERTICAL_LINE << " YOU WIN " << VERTICAL_LINE << endl;//color

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

		cout << ' ' << VERTICAL_LINE << " YOU LOSE " << VERTICAL_LINE << endl;//color

		cout << ' ' << LOWER_LEFT_CORNER;
		for (int i = 0; i < 10; i++) {
			cout << HORIZONTAL_LINE;
		}
		cout << LOWER_RIGHT_CORNER << endl;
	}

	cout << endl;
	cout << " 1. " << "PLAY AGAIN" << endl;//color
	cout << " 2. " << "EXIT" << endl;//color
	cout << endl;

	cout << " >> ";
}