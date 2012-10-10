#include <iostream>

#include "InfInt.h"

int main(int argc, char *argv[]) {

	InfInt a("-60");
	InfInt b("-30");


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