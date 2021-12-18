#include <iostream>
#include "Field.cpp"
#include "Menu.cpp"

using namespace std;

void startGame() {
	printMenu();
	printField(10);
}

int main() {
	startGame();
	return 0;
}