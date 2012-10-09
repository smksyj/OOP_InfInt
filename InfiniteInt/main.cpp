#include <iostream>


#include "InfInt.h"

int main(int argc, char *argv[]) {
	InfInt a("99");
	InfInt b("32");

	cout << a - b << endl;

	getchar();
	/*
	string temp("asdf");
	temp.insert(0, 'g', 1);

	cout << temp.c_str() << endl;

	getchar();
	*/

	return 0;
}