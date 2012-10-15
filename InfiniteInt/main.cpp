#include <iostream>

#include "Calculator.h"
#include "Parser.h"
#include "ConsoleParser.h"
#include "FileParser.h"

int main(int argc, char *argv[]) {

	//string MyExpress= "263731 + 343263474 / ( 8 * ( 110 - 2563 ) )";

	Calculator *calc = new Calculator(new FileParser("test.txt"));

	return 0;
}
