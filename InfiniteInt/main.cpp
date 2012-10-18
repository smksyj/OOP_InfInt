#include <iostream>

#include "Calculator.h"
#include "Parser.h"
#include "ConsoleParser.h"
#include "FileParser.h"

int main(int argc, char *argv[]) {
	Calculator *calc = NULL;

	if ( argc == 2 ) {
		calc = new Calculator(new FileParser(argv[1]));
	} else {
		calc = new Calculator(new ConsoleParser());
	}

	calc->run();

	return 0;
}
