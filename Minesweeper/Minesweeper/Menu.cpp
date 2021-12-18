#include <iostream>
#include "Resources.cpp"

using namespace std;

static void printMenu() {
	cout << ' ' << UPPER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << UPPER_RIGHT_CORNER << endl;

	cout << ' ' << VERTICAL_LINE << " MINESWEEPER " << VERTICAL_LINE << endl;

	cout << ' ' << LOWER_LEFT_CORNER;
	for (int i = 0; i < 13; i++) {
		cout << HORIZONTAL_LINE;
	}
	cout << LOWER_RIGHT_CORNER << endl;

	cout << endl;
	cout << " 1. " << "EASY" << endl;
	cout << " 2. " << "MEDIUM" << endl;
	cout << " 3. " << "HARD" << endl;
	cout << endl;

	cout << "   >> ";
}