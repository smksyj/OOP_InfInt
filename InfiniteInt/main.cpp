#include <iostream>

#include "InfInt.h"

int main(int argc, char *argv[]) {
	InfInt a("123235412345312413413512353151213413513513561326346567678456745");
	InfInt b("452475924349785794746534523236479578657867856754633556476557865875675675676787878784547545334413251345132541");
	
	cout << a * b << endl;

	getchar();
	/*
	string temp("asdf");
	temp.insert(0, 'g', 1);

	cout << temp.c_str() << endl;

	getchar();
	*/

	return 0;
}