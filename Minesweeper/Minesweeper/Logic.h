#pragma once

#include <iostream>
#include <limits>
#include "Visual.h"

using namespace std;

int randomNumber(int limit);

int chooseDifficulty();

void applyDifficulty(int difficulty, int& size, int& mines);

int** generateField(int size);

bool isMine(int** field, int x, int y);

bool isRevealed(int** field, int x, int y);

bool isFlag(int** field, int x, int y);

bool isSafe(int** field, int x, int y);

void placeRemoveFlag(int** field, int x, int y, int& flags);

void placeMines(int** field, int size, int mines, int initialX, int initialY);

void revealSafeZone(int** field, int** revealedField, int size, int x, int y, int& counter);

void revealLeft(int** revealedField, int size);

void revealAll(int** field, int** revealedField, int size);

void showDangerousSquares(int** field, int size);

void firstReveal(int** field, int** revealedField, int size, int mines, int& flags, int& counter);

bool Minesweeping(int** field, int** revealedField, int size, int mines, int& flags, int& counter);

bool endGame(int** field, int** revealedField, int size, int flags, bool win);
