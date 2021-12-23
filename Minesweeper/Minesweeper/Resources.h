#include <string>

using namespace std;

const int EASY_SIZE = 7;
const int MEDIUM_SIZE = 10;
const int HARD_SIZE = 12;

const int EASY_MINES = 5;
const int MEDIUM_MINES = 15;
const int HARD_MINES = 28;

#ifdef _WIN32

const unsigned char UPPER_LEFT_CORNER = 201;
const unsigned char UPPER_EDGE = 203;
const unsigned char UPPER_RIGHT_CORNER = 187;
const unsigned char LEFT_EDGE = 204;
const unsigned char CENTER = 206;
const unsigned char RIGHT_EDGE = 185;
const unsigned char LOWER_LEFT_CORNER = 200;
const unsigned char LOWER_EDGE = 202;
const unsigned char LOWER_RIGHT_CORNER = 188;

const unsigned char VERTICAL_LINE = 186;
const unsigned char HORIZONTAL_LINE = 205;

const unsigned char FLAG = 'P';
const unsigned char MINE = 'X';
const unsigned char SQUARE = 254;

#else

const string UPPER_LEFT_CORNER = "╔";
const string UPPER_EDGE = "╦";
const string UPPER_RIGHT_CORNER = "╗";
const string LEFT_EDGE = "╠";
const string CENTER = "╬";
const string RIGHT_EDGE = "╣";
const string LOWER_LEFT_CORNER = "╚";
const string LOWER_EDGE = "╩";
const string LOWER_RIGHT_CORNER = "╝";

const string VERTICAL_LINE = "║";
const string HORIZONTAL_LINE = "═";

const string FLAG = "P";
const string MINE = "X";
const string SQUARE = "■";

#endif