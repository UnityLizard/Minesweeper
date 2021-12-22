#include <iostream>

using namespace std;

static void reset()
{
	cout << "\033[0m";
}

static void blue() {
	cout << "\033[0;94m";
}

static void green() {
	cout << "\033[0;92m";
}

static void yellow() {
	cout << "\033[0;33m";
}

static void red() {
	cout << "\033[0;31m";
}

static void purple() {
	cout << "\033[0;35m";
}

static void gray() {
	cout << "\033[0;90m";
}

static void orange() {
	cout << "\033[0;91m";
}

static void cyan() {
	cout << "\033[0;96m";
}

static void color(int number) {
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