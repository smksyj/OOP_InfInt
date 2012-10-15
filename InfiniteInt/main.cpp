#include <iostream>

#include "Calculator.h"
#include "Parser.h"
#include "ConsoleParser.h"
#include "FileParser.h"

int main(int argc, char *argv[]) {
	Calculator *calc = new Calculator(new ConsoleParser());
	//Calculator *calc = new Calculator(new FileParser("test.txt"));

	calc->run();

	return 0;
}
