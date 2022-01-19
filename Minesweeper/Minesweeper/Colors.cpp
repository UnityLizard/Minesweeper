#include "Colors.h"

void reset() {
	cout << "\033[0m";
}

void blue() {
	cout << "\033[0;94m";
}

void green() {
	cout << "\033[0;92m";
}

void yellow() {
	cout << "\033[0;33m";
}

void red() {
	cout << "\033[0;31m";
}

void purple() {
	cout << "\033[0;35m";
}

void gray() {
	cout << "\033[0;90m";
}

void orange() {
	cout << "\033[0;91m";
}

void cyan() {
	cout << "\033[0;96m";
}

void color(int number) {
	switch (number) {
	case 1:
		blue();
		break;
	case 2:
		green();
		break;
	case 3:
		yellow();
		break;
	case 4:
		red();
		break;
	default:
		purple();
		break;
	}
	cout << number;
	reset();
}