#include <iostream>


#include "InfInt.h"

int main(int argc, char *argv[]) {
	InfInt a("-123");
	InfInt b(a);

	cout << b << endl;

	getchar();
	/*
	string temp("asdf");
	temp.insert(0, 'g', 1);

	cout << temp.c_str() << endl;

	getchar();
	*/

	return 0;
}