#include <iostream>


#include "InfInt.h"

int main(int argc, char *argv[]) {
	InfInt a("9");
	InfInt b("31");
	
	cout << a + b << endl;

	getchar();
	/*
	string temp("asdf");
	temp.insert(0, 'g', 1);

	cout << temp.c_str() << endl;

	getchar();
	*/

	return 0;
}