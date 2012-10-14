#include <iostream>

#include "Parser.h"

int main(int argc, char *argv[]) {

	string MyExpress= "263731 + 343263474 / ( 8 * ( 110 - 2563 ) )";

	Parser MyParser;

	InfInt Result= MyParser.Operation(MyExpress);

	cout<< Result << endl;

	return 0;
}