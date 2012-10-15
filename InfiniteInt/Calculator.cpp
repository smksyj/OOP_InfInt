#include "Calculator.h"


/*
Calculator::Calculator(void)
{
	this->parser = new ConsoleParser();
	this->oper = new Operator();
}
*/


Calculator::~Calculator(void)
{
	delete this->parser;
	delete this->oper;
}

Calculator::Calculator(Parser *parser) {
	this->parser = parser;
	this->oper = new Operator();
}

void Calculator::run() {
	string line;

	while ( true ) {
		cout << "Input : ";

		vector<string> splittedLine = this->parser->split(this->parser->getExpression(), ' ');

		if ( splittedLine.size() == 1 && splittedLine[0] == "0" ) {
			exit(0);
		} else {
			cout << "Output : " << this->oper->Operation(splittedLine) << endl;
		}
	}
}