#pragma once

#include <iostream>
#include "Resources.h"
#include "Colors.h"

using namespace std;

void clear();

void printMenu();

void printField(int** field, int** revealedField, int size, int flags);

void printCommand();

void printEndScreen(bool win);
