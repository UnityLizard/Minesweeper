#include <iostream>

using namespace std;

void Clear()
{
	cout << "\x1B[2J\x1B[H";
}

void Red()
{
	cout << "\033[0;31m";
}

void Blue()
{
	cout << "\033[1;32m";
}

void Green()
{
	cout << "\033[1;33m";
}

void Color()
{
	cout << "\033[1;35m";
}

void Reset()
{
	cout << "\033[0m";
}

void printField(int difficulty) {

}

//const std::string red("\033[0;31m");
//const std::string green("\033[1;32m");
//const std::string yellow("\033[1;33m");
//const std::string cyan("\033[0;36m");
//const std::string magenta("\033[0;35m");
//const std::string reset("\033[0m");

int main() {
	char q = 201;
	char w = 203;
	char e = 187;
	char a = 204;
	char s = 206;
	char d = 185;
	char z = 200;
	char x = 202;
	char c = 188;

	char r = 186;
	char t = 205;

	char y = ' ';

	char p = 254;

	char m = 'P';
	char n = 'X';

	const int RED = 1;
	const int GREEN = 2;
	const int BLUE = 4;

	int colour[] = { RED, GREEN, BLUE };

	cout << endl;
	cout << "               " << m << ": " << 5 << "               " << endl;
	cout << "   " << q << t << t << t << w << t << t << t << w << t << t << t << w << t << t << t << w << t << t << t << w << t << t << t << w << t << t << t << e << endl;
	cout << "   " << r << y;

	Blue();
	cout << 1;
	Reset();

	cout << y << r << y << y << y << r << y << p << y << r << y << 1 << y << r << y << y << y << r << y << y << y << r << y << y << y << r << endl;
	cout << "   " << a << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << d << endl;
	cout << "   " << r << y << y << y << r << y << y << y << r << y << y << y << r << y << y << y << r << y << n << y << r << y << y << y << r << y << m << y << r << endl;
	cout << "   " << a << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << d << endl;
	cout << "   " << r << y << y << y << r << y;

	Red();
	cout << 4;
	Reset();

	cout << y << r << y << y << y << r << y << m << y << r << y << y << y << r << y << y << y << r << y << y << y << r << endl;
	cout << "   " << a << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << d << endl;
	cout << "   " << r << y << y << y << r << y << y << y << r << y << y << y << r << y << y << y << r << y << y << y << r << y << y << y << r << y << m << y << r << endl;
	cout << "   " << a << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << d << endl;
	cout << "   " << r << y << p << y << r << y << y << y << r << y << 1 << y << r << y << y << y << r << y << p << y << r << y << y << y << r << y << y << y << r << endl;
	cout << "   " << a << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << s << t << t << t << d << endl;
	cout << "   " << r << y << y << y << r << y << y << y << r << y << y << y << r << y << p << y << r << y << p << y << r << y << y << y << r << y << y << y << r << endl;
	cout << "   " << z << t << t << t << x << t << t << t << x << t << t << t << x << t << t << t << x << t << t << t << x << t << t << t << x << t << t << t << c << endl;

	cout << endl << ">> commands here" << endl;

	cout << endl << endl;

	cout << " " << q << t << t << t << t << t << t << t << t << t << t << t << t << t << e << endl;
	cout << " " << r;
	Color();
	cout << " MINESWEEPER ";
	Reset();
	cout << r << endl;
	cout << " " << z << t << t << t << t << t << t << t << t << t << t << t << t << t << c << endl;

	cout << endl;
	cout << " 1. ";
	Red();
	cout << "EASY" << endl;
	Reset();
	cout << " 2. ";
	Blue();
	cout << "MEDIUM" << endl;
	Reset();
	cout << " 3. ";
	Green();
	cout << "HARD" << endl;
	Reset();

	cout << endl << ">> commands here" << endl;

	cout << "\033[0;92m";//1*
	cout << "1" << endl;
	cout << "\033[0;94m";//2*
	cout << "2" << endl;
	cout << "\033[0;33m";//3*
	cout << "3" << endl;
	cout << "\033[0;31m";//4*
	cout << "4" << endl;
	cout << "\033[0;35m";//5+*
	cout << "5" << endl;


	cout << "\033[0;90m";//bomb*
	cout << "X" << endl;
	cout << "\033[0;91m";//flag*
	cout << "P" << endl;

	Reset();


	return 0;
}