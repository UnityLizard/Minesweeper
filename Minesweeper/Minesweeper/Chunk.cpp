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

//const std::string red("\033[0;31m");
//const std::string green("\033[1;32m");
//const std::string yellow("\033[1;33m");
//const std::string cyan("\033[0;36m");
//const std::string magenta("\033[0;35m");
//const std::string reset("\033[0m");

int _main() {

	//cout << " " << q << t << t << t << t << t << t << t << t << t << t << t << t << t << e << endl;
	//cout << " " << r;
	//Color();
	//cout << " MINESWEEPER ";
	//Reset();
	//cout << r << endl;
	//cout << " " << z << t << t << t << t << t << t << t << t << t << t << t << t << t << c << endl;

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
	cout << "\033[0;35m";//logo / 5+*
	cout << "5" << endl;


	cout << "\033[0;90m";//bomb*
	cout << "X" << endl;
	cout << "\033[0;91m";//flag*
	cout << "P" << endl;
	cout << "\033[0;96m";//table*
	cout << "0" << endl;


	Reset();

	return 0;
}