#include <iostream>

#include "InfInt.h"

int main(int argc, char *argv[]) {

	InfInt a("-1");
	InfInt b("1");
	for(int i=0;i<10;i++){
		a=a+b;
		
		cout << a << endl;

	}


	getchar();
	/*
	string temp("asdf");
	temp.insert(0, 'g', 1);

	cout << temp.c_str() << endl;

	getchar();
	*/

	return 0;
}